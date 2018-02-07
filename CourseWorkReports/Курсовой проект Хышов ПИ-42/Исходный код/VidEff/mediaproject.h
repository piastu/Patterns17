#ifndef MEDIAPROJECT_H
#define MEDIAPROJECT_H

#include "defs.h"
#include "clipsource.h"
#include "clip.h"
#include "track.h"
#include "filter.h"

struct TrackInfo
{
		int length, numClips;
};

struct ProjectData
{
		int framerate, w, h;
		ProjectData()
		{
			framerate = w = h = 1;
		}
		ProjectData(int w, int h, int framerate)
		{
			this->w = w;
			this->h = h;
			this->framerate = framerate;
		}
};

class MediaProject
{
	private:
		int framerate, w, h;
		vector<Track *> tracks;
		vector<ClipSource *> sources;
		MediaProject();
		static MediaProject *instance;
		int framePtr;
		int maxLength;
	public:
		static MediaProject *getInstance();
		void reset(int w, int h, int framerate);
		ProjectData getProjectData();
		void addTrack();
		void deleteTrack(int id);
		void addSource(ClipSource *src);
		vector<int> getSourcesList();
		ClipSource * getSource(int id);
		void deleteSource(int id);
		void addClip(int uid, int track, int frameOffset, int offsetStart, int offsetEnd);
		void removeClip(int id, int track);
		void makeTransition(int id_A, int id_B, int track, wstring name, int frames);
		int getTracksNum();
		int getFramePtr();
		void seek(int ptr);
		bool movePtr(int offset);
		Frame * getCurrentFrame();
		void updateLengths();
		vector<TrackInfo> getTracksInfo();
		vector<ClipInfo> getClipsInfo(int track);
		void addFilter(int track, int id, wstring fltName);
		void removeFilter(int track, int clipId, int fltId);
		vector<FilterEntry> getUsedFilters(int track, int clipId);
};

#endif // MEDIAPROJECT_H
