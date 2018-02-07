#include "track.h"

Track::Track()
{

}

Track::~Track()
{
	while (!clips.empty())
	{
		ClipEntry ce = clips.back();
		clips.pop_back();
		delete ce.clip;
	}
}

Frame *Track::getFrame(int pos)
{
	Frame *result = nullptr;
	int offset = 0;
	int sizeInt = clips.size();
	for (int i = 0; i < sizeInt; i++)
	{
		if (pos >= offset && pos < (offset + clips[i].offsetFrame) && clips[i].offsetFrame != 0)
		{
			result = new Frame(1, 1, nullptr);
			break;
		}
		else if (pos >= (offset + clips[i].offsetFrame) && pos <= (offset + clips[i].clip->getFramesLength() + clips[i].offsetFrame))
		{
			Clip *clip = clips[i].clip;
			result = clip->renderFrame(pos - clips[i].offsetFrame - offset);
			break;
		}
		offset += clips[i].clip->getFramesLength() + clips[i].offsetFrame;
	}
	if (result == nullptr)
		result = new Frame(1, 1, nullptr);
	return result;
}

void Track::addClip(Clip *clip, int offset)
{
	ClipEntry entry;
	entry.clip = clip;
	entry.offsetFrame = offset;
	clips.push_back(entry);
}

vector<ClipEntry> Track::getClips()
{
	return clips;
}

int Track::getClipNum()
{
	return clips.size();
}

ClipEntry Track::getClip(int id)
{
	ClipEntry result;
	if (id >= 0 && id < clips.size())
		result = clips[id];
	return result;
}

int Track::getLength()
{
	int result = 0;
	int sizeint = clips.size();
	for (int i = 0; i < sizeint; i++)
	{
		result += (clips[i].offsetFrame + clips[i].clip->getFramesLength());
	}
	return result;
}

void Track::removeClip(int id)
{
	if (id < 0 || id >= clips.size())
		return;
	ClipEntry ce = clips[id];
	clips.erase(clips.begin() + id);
	delete ce.clip;
}

void Track::makeTransition(int id_A, int id_B, wstring transName, int frames)
{
	if (id_A < 0 || id_B < 0 || id_A >= clips.size() || id_B >= clips.size())
		return;
	// переход следует делать для рядом стоящих клипов
	int diff = id_B - id_A;
	if (diff < 0) diff = 0 - diff;
	if (diff != 1)
		return;
	int idA = id_A, idB = id_B;
	if (idA > idB)
	{
		int t = idA;
		idA = idB;
		idB = t;
	}
	ClipEntry clipBEntry = clips[idB];
	clips.erase(clips.begin() + idB);
	Clip *clipA = clips[idA].clip, *clipB = clipBEntry.clip;
	ClipCombo *combo = new ClipCombo(clipA, clipB, frames);
	combo->setTransition(transName, frames);
	clips[idA].clip = combo;
}

void Track::deleteClipsWith(ClipSource *src)
{
	int sizeInt = clips.size();
	for (int i = sizeInt - 1; i >= 0; i--)
	{
		if (clips[i].clip->usesSource(src))
		{
			Clip *clip = clips[i].clip;
			clips.erase(clips.begin() + i);
			delete clip;
		}
	}
}

vector<ClipInfo> Track::getClipsInfo()
{
	vector<ClipInfo> result;
	int sizeInt = clips.size();
	for (int i = 0; i < sizeInt; i++)
	{
		ClipInfo cInfo;
		Clip *clip = clips[i].clip;
		cInfo.ctype = clip->getType();
		cInfo.frames = clip->getFramesLength();
		result.push_back(cInfo);
	}
	return result;
}

bool Track::isEmptyAt(int pos)
{
	bool ok = true;
	int offset = 0;
	int sizeInt = clips.size();
	for (int i = 0; i < sizeInt; i++)
	{
		if (pos >= offset && pos < (offset + clips[i].offsetFrame) && clips[i].offsetFrame != 0)
		{
			return true;
		}
		else if (pos >= (offset + clips[i].offsetFrame) && pos <= (offset + clips[i].clip->getFramesLength() + clips[i].offsetFrame))
		{
			return false;
		}
		offset += clips[i].clip->getFramesLength() + clips[i].offsetFrame;
	}
	return ok;
}

void Track::addFilter(int id, wstring fltName)
{
	if (id >= 0 && id < clips.size())
	{
		Clip *clip = clips[id].clip;
		clip->addFilter(fltName);
	}
}

void Track::removeFilter(int id, int fltId)
{
	if (id >= 0 && id < clips.size())
	{
		Clip *clip = clips[id].clip;
		clip->removeFilter(fltId);
	}
}

vector<FilterEntry> Track::getUsedFilters(int id)
{
	vector<FilterEntry> result;
	if (id >= 0 && id < clips.size())
	{
		Clip *clip = clips[id].clip;
		result = clip->getUsedFilters();
	}
	return result;
}
