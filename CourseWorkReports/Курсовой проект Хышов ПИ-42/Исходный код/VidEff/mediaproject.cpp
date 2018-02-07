#include "mediaproject.h"

MediaProject * MediaProject::instance = nullptr;

MediaProject::MediaProject()
{
	w = h = framerate = 1;
	framePtr = 0;
	maxLength = 0;
}

MediaProject *MediaProject::getInstance()
{
	if (instance == nullptr)
		instance = new MediaProject();
	return instance;
}

void MediaProject::reset(int w, int h, int framerate)
{
	while (!tracks.empty())
	{
		Track *t = tracks.back();
		tracks.pop_back();
		delete t;
	}
	this->w = w;
	this->h = h;
	this->framerate = framerate;
	framePtr = 0;
}

ProjectData MediaProject::getProjectData()
{
	return ProjectData(w, h, framerate);
}

void MediaProject::addTrack()
{
	tracks.push_back(new Track());
}

void MediaProject::deleteTrack(int id)
{
	if (id >= 0 && id < tracks.size())
	{
		Track *t = tracks[id];
		tracks.erase(tracks.begin() + id);
		delete t;
	}
}

void MediaProject::addSource(ClipSource *src)
{
	sources.push_back(src);
}

ClipSource *MediaProject::getSource(int id)
{
	int sizeInt = sources.size();
	ClipSource *src = nullptr;
	for (int i = 0; i < sizeInt; i++)
	{
		if (sources[i]->getUID() == id)
		{
			src = sources[i];
			break;
		}
	}
	return src;
}

void MediaProject::deleteSource(int id)
{
	int sizeInt = sources.size();
	ClipSource *src = nullptr;
	for (int i = 0; i < sizeInt; i++)
	{
		if (sources[i]->getUID() == id)
		{
			src = sources[i];
			sources.erase(sources.begin() + i);
		}
	}
	sizeInt = tracks.size();
	for (int i = 0; i < sizeInt; i++)
	{
		Track *t = tracks[i];
		t->deleteClipsWith(src);
	}
	delete src;
}

void MediaProject::addClip(int uid, int track, int frameOffset, int offsetStart, int offsetEnd)
{
	if (track < 0 || track >= tracks.size())
		return;
	int sizeInt = sources.size();
	ClipSource *src = nullptr;
	for (int i = 0; i < sizeInt; i++)
	{
		if (sources[i]->getUID() == uid)
		{
			src = sources[i];
			break;
		}
	}
	if (src == nullptr)
		return;
	Track *t = tracks[track];
	Clip *clip = new ClipSingle(src, offsetStart, offsetEnd);
	t->addClip(clip, frameOffset);
	updateLengths();
}

void MediaProject::removeClip(int id, int track)
{
	if (track < 0 || track >= tracks.size())
		return;
	Track *t = tracks[track];
	t->removeClip(id);
	updateLengths();
}

void MediaProject::makeTransition(int id_A, int id_B, int track, wstring name, int frames)
{
	if (track >= 0 && track < tracks.size())
	{
		Track *t = tracks[track];
		t->makeTransition(id_A, id_B, name, frames);
		updateLengths();
	}
}

int MediaProject::getTracksNum()
{
	return tracks.size();
}

int MediaProject::getFramePtr()
{
	return framePtr;
}

void MediaProject::seek(int ptr)
{
	framePtr = ptr;
}

bool MediaProject::movePtr(int offset)
{
	bool ok = true;
	framePtr += offset;
	if (framePtr == (maxLength - 1))
		ok = false;
	return ok;
}

Frame *MediaProject::getCurrentFrame()
{
	// сначала возьмем пустой кадр
	Frame *result = new Frame(w, h, nullptr);
	uint32_t *resData = result->getData();
	int sizeint = tracks.size();
	for (int k = 0; k < sizeint; k++)
	{
		Track *t = tracks[k];
		Frame *tmpFrame = t->getFrame(framePtr);
		uint32_t *frmData = tmpFrame->getData();
		int frameW = tmpFrame->width(), frameH = tmpFrame->height();
		if (t->isEmptyAt(framePtr))
			continue;
		// накладываем один кадр на другой
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				resData[clamp(i, 0, h - 1) * w + clamp(j, 0, w - 1)] = frmData[clamp(i, 0, frameH - 1) * w + clamp(j, 0, frameW - 1)];
			}
		}
	}
	result->setTemporary(true);
	return result;
}

void MediaProject::updateLengths()
{
	int len = -1;
	int sizeint = tracks.size();
	for (int i = 0; i < sizeint; i++)
	{
		Track *t = tracks[i];
		if (t->getLength() > len)
			len = t->getLength();
	}
	if (len != -1)
		maxLength = len;
}

vector<TrackInfo> MediaProject::getTracksInfo()
{
	vector<TrackInfo> result;
	int sizeInt = tracks.size();
	for (int i = 0; i < sizeInt; i++)
	{
		TrackInfo tInfo;
		Track *t = tracks[i];
		tInfo.length = t->getLength();
		tInfo.numClips = t->getClipNum();
		result.push_back(tInfo);
	}
	return result;
}

vector<ClipInfo> MediaProject::getClipsInfo(int track)
{
	vector<ClipInfo> result;
	if (track >= 0 && track < tracks.size())
	{
		Track *t = tracks[track];
		result = t->getClipsInfo();
	}
	return result;
}

void MediaProject::addFilter(int track, int id, wstring fltName)
{
	if (track >= 0 && track < tracks.size())
	{
		Track *t = tracks[track];
		t->addFilter(id, fltName);
	}
}

void MediaProject::removeFilter(int track, int clipId, int fltId)
{
	if (track >= 0 && track < tracks.size())
	{
		Track *t = tracks[track];
		t->removeFilter(clipId, fltId);
	}
}

vector<FilterEntry> MediaProject::getUsedFilters(int track, int clipId)
{
	vector<FilterEntry> result;
	if (track >= 0 && track < tracks.size())
	{
		Track *t = tracks[track];
		result = t->getUsedFilters(clipId);
	}
	return result;
}
