#include "clip.h"

Clip::Clip()
{

}

Clip::~Clip()
{

}


ClipSingle::ClipSingle() : Clip()
{
	this->src = nullptr;
}

ClipSingle::ClipSingle(ClipSource *src, int frameOffsetStart, int frameOffsetEnd) : ClipSingle()
{
	this->src = src;
	this->frameOffsetStart = frameOffsetStart;
	this->frameOffsetEnd = frameOffsetEnd;
}

Frame *ClipSingle::renderFrame(int pos)
{
	EffectLib *el = EffectLib::getInstance();
	Frame * result;
	int sizeInt = src->getLength();
	if (pos >= 0 && pos < sizeInt)
	{
		result = src->getFrame(pos);
	}
	else if (pos < 0)
	{
		result = src->getFrame(0);
	}
	else if (pos >= sizeInt)
	{
		result = src->getFrame(sizeInt - 1);
	}
	for (int f = 0; f < usedFilters.size(); f++)
	{
		Filter *flt = el->getFilter(usedFilters[f].flt);
		result->setTemporary(true);
		vector<Keyframe> keyframes = usedFilters[f].keyframes;
		if (keyframes.size() == 1)
		{
			result = flt->use(result, keyframes[0].props);
		}
		else if (keyframes.empty())
		{
			result = flt->use(result);
		}
		else
		{
			// отсортируем ключевые кадры по возрастанию
			for (int i = 0; i < keyframes.size() - 1; i++)
			{
				for (int j = 0; j < keyframes.size() - i - 1; i++)
				{
					if (keyframes[j].frame > keyframes[j + 1].frame)
					{
						Keyframe kf = keyframes[j];
						keyframes[j] = keyframes[j + 1];
						keyframes[j + 1] = kf;
					}
				}
			}
			if (pos <= keyframes[0].frame)
			{
				result = flt->use(result, keyframes[0].props);
			}
			else if (pos >= keyframes[keyframes.size() - 1].frame)
			{
				result = flt->use(result, keyframes[keyframes.size() - 1].props);
			}
			else
			{
				int idLow = 0, idHi = 1;
				int posLow = 0, posHi = 0;
				for (int i = 0; i < keyframes.size() - 1; i++)
				{
					if (pos > keyframes[i].frame && pos <= keyframes[i].frame)
					{
						idLow = i;
						idHi = i + 1;
						break;
					}
					else if (pos == keyframes[i].frame)
					{
						idLow = idHi = i;
						break;
					}
				}
				posLow = keyframes[idLow].frame;
				posHi = keyframes[idHi].frame;
				int interframe = posHi - posLow;
				float kfOffset = (float)(pos - posLow) / (float)interframe;
				vector<Property> props;
				for (int i = 0; i < keyframes[posLow].props.size(); i++)
				{
					int propHi = -1;
					for (int j = 0; j < keyframes[posHi].props.size(); j++)
					{
						if (keyframes[posLow].props[i].name == keyframes[posHi].props[j].name)
						{
							props.push_back(Property(keyframes[posLow].props[i].name, keyframes[posLow].props[i].value + (keyframes[posHi].props[j].value - keyframes[posLow].props[i].value) * kfOffset));
							break;
						}
					}
				}
				result = flt->use(result, props);
			}
		}
	}
	return result;
}

Frame *ClipSingle::getSrcFrame(int pos)
{
	Frame * result;
	int sizeInt = src->getLength();
	if (pos >= 0 && pos < sizeInt)
	{
		result = src->getFrame(pos);
	}
	else if (pos < 0)
	{
		result = src->getFrame(0);
	}
	else if (pos > sizeInt)
	{
		result = src->getFrame(sizeInt - 1);
	}
	return result;
}

void ClipSingle::addFilter(wstring fltName)
{
	int sizeint = fltAvailable.size();
	int fltId = -1;
	for (int i = 0; i < sizeint; i++)
	{
		if (fltAvailable[i].name == fltName)
		{
			fltId = i;
			break;
		}
	}
	if (fltId == -1)
		return;
	EffectLib *el = EffectLib::getInstance();
	Filter *flt = el->getFilter(fltName);
	vector<PropertyInfo> propsInfo = flt->getPropertiesInfo();
	Keyframe kf;
	kf.frame = 0;
	kf.props = vector<Property>();
	sizeint = propsInfo.size();
	for (int i = 0; i < sizeint; i++)
	{
		kf.props.push_back(Property(propsInfo[i].name, propsInfo[i].defValue));
	}
	FilterEntry fEnt;
	fEnt.flt = fltName;
	fEnt.keyframes = vector<Keyframe>({kf});
	usedFilters.push_back(fEnt);
}

void ClipSingle::removeFilter(int id)
{
	int sizeint = usedFilters.size();
	if (id >= 0 && id < sizeint)
	{
		usedFilters.erase(usedFilters.begin() + id);
	}
}

void ClipSingle::setFilterProp(int id, wstring propName, float value, int frameId)
{
	int sizeint = usedFilters.size();
	if (id < 0 || id >= sizeint)
		return;
	FilterEntry fEnt = usedFilters[id];
	if (frameId < 0 || frameId >= fEnt.keyframes.size())
		return;
	Keyframe kf = fEnt.keyframes[frameId];
	sizeint = kf.props.size();
	for (int i = 0; i < sizeint; i++)
	{
		if (propName == kf.props[i].name)
		{
			kf.props[i].value = value;
			break;
		}
	}
	fEnt.keyframes[frameId] = kf;
	usedFilters[id] = fEnt;
}

float ClipSingle::getFilterProp(int id, wstring propName, int frameId)
{
	float value = 0.0;
	int sizeint = usedFilters.size();
	if (id < 0 || id >= sizeint)
		return 0.0;
	FilterEntry fEnt = usedFilters[id];
	if (frameId < 0 || frameId >= fEnt.keyframes.size())
		return 0.0;
	Keyframe kf = fEnt.keyframes[frameId];

	for (int i = 0; i < sizeint; i++)
	{
		if (propName == kf.props[i].name)
		{
			return kf.props[i].value;
			break;
		}
	}
	return value;
}

vector<FilterEntry> ClipSingle::getUsedFilters()
{
	return usedFilters;
}

ClipType ClipSingle::getType()
{
	return CLIP_SG;
}

int ClipSingle::getFramesLength()
{
	return src->getLength() - frameOffsetStart + frameOffsetEnd;
}

bool ClipSingle::usesSource(ClipSource *src)
{
	return (this->src == src);
}

ClipCombo::ClipCombo() : Clip()
{
	clipA = clipB = nullptr;
}

ClipCombo::ClipCombo(Clip *clipA, Clip *clipB, int transitionFrames) : ClipCombo()
{
	this->clipA = clipA;
	this->clipB = clipB;
	
}

Frame *ClipCombo::renderFrame(int pos)
{
	EffectLib *el = EffectLib::getInstance();
	Frame * result;
	int sizeInt = this->getFramesLength();
	if (pos >= 0 && pos < sizeInt)
	{
		if (pos >= 0 && pos < clipA->getFramesLength() - transFrames)
		{
			result = clipA->renderFrame(pos);
		}
		else if (pos >= clipA->getFramesLength() - transFrames && pos < clipA->getFramesLength())
		{
			Frame *resA = clipA->renderFrame(pos),
					*resB = clipB->renderFrame(pos - clipA->getFramesLength() + transFrames);
			resA->setTemporary(true);
			resB->setTemporary(true);
			Transition *trans = el->getTransition(usedTransition);
			result = trans->use(resA, resB, (float)(pos - clipA->getFramesLength() + transFrames) / (float)transFrames);
		}
		else
		{
			result = clipB->renderFrame(pos + clipA->getFramesLength() + transFrames);
		}
	}
	else if (pos < 0)
	{
		result = clipA->renderFrame(0);
	}
	else if (pos > sizeInt)
	{
		result = clipB->renderFrame(clipB->getFramesLength() - 1);
	}
	for (int f = 0; f < usedFilters.size(); f++)
	{
		Filter *flt = el->getFilter(usedFilters[f].flt);
		result->setTemporary(true);
		vector<Keyframe> keyframes = usedFilters[f].keyframes;
		if (keyframes.size() == 1)
		{
			result = flt->use(result, keyframes[0].props);
		}
		else if (keyframes.empty())
		{
			result = flt->use(result);
		}
		else
		{
			// отсортируем ключевые кадры по возрастанию
			for (int i = 0; i < keyframes.size() - 1; i++)
			{
				for (int j = 0; j < keyframes.size() - i - 1; i++)
				{
					if (keyframes[j].frame > keyframes[j + 1].frame)
					{
						Keyframe kf = keyframes[j];
						keyframes[j] = keyframes[j + 1];
						keyframes[j + 1] = kf;
					}
				}
			}
			if (pos <= keyframes[0].frame)
			{
				result = flt->use(result, keyframes[0].props);
			}
			else if (pos >= keyframes[keyframes.size() - 1].frame)
			{
				result = flt->use(result, keyframes[keyframes.size() - 1].props);
			}
			else
			{
				int idLow = 0, idHi = 1;
				int posLow = 0, posHi = 0;
				for (int i = 0; i < keyframes.size() - 1; i++)
				{
					if (pos > keyframes[i].frame && pos <= keyframes[i].frame)
					{
						idLow = i;
						idHi = i + 1;
						break;
					}
					else if (pos == keyframes[i].frame)
					{
						idLow = idHi = i;
						break;
					}
				}
				posLow = keyframes[idLow].frame;
				posHi = keyframes[idHi].frame;
				int interframe = posHi - posLow;
				float kfOffset = (float)(pos - posLow) / (float)interframe;
				vector<Property> props;
				for (int i = 0; i < keyframes[posLow].props.size(); i++)
				{
					int propHi = -1;
					for (int j = 0; j < keyframes[posHi].props.size(); j++)
					{
						if (keyframes[posLow].props[i].name == keyframes[posHi].props[j].name)
						{
							props.push_back(Property(keyframes[posLow].props[i].name, keyframes[posLow].props[i].value + (keyframes[posHi].props[j].value - keyframes[posLow].props[i].value) * kfOffset));
							break;
						}
					}
				}
				result = flt->use(result, props);
			}
		}
	}
	return result;
}

Frame *ClipCombo::getSrcFrame(int pos)
{
	EffectLib *el = EffectLib::getInstance();
	Frame * result;
	int sizeInt = this->getFramesLength();
	if (pos >= 0 && pos < sizeInt)
	{
		if (pos >= 0 && pos < clipA->getFramesLength() - transFrames)
		{
			result = clipA->getSrcFrame(pos);
		}
		else if (pos >= clipA->getFramesLength() - transFrames && pos < clipA->getFramesLength())
		{
			Frame *resA = clipA->getSrcFrame(pos), *resB = clipB->getSrcFrame(pos - clipA->getFramesLength() + transFrames);
			resA->setTemporary(true);
			resB->setTemporary(true);
			Transition *trans = el->getTransition(usedTransition);
			result = trans->use(resA, resB, (float)(pos - clipA->getFramesLength() + transFrames) / (float)transFrames);
		}
		else
		{
			result = clipB->getSrcFrame(pos + clipA->getFramesLength() + transFrames);
		}
	}
	else if (pos < 0)
	{
		result = clipA->getSrcFrame(0);
	}
	else if (pos > sizeInt)
	{
		result = clipB->getSrcFrame(clipB->getFramesLength() - 1);
	}
	return result;
}

void ClipCombo::addFilter(wstring fltName)
{
	int sizeint = fltAvailable.size();
	int fltId = -1;
	for (int i = 0; i < sizeint; i++)
	{
		if (fltAvailable[i].name == fltName)
		{
			fltId = i;
			break;
		}
	}
	if (fltId == -1)
		return;
	EffectLib *el = EffectLib::getInstance();
	Filter *flt = el->getFilter(fltName);
	vector<PropertyInfo> propsInfo = flt->getPropertiesInfo();
	Keyframe kf;
	kf.frame = 0;
	kf.props = vector<Property>();
	sizeint = propsInfo.size();
	for (int i = 0; i < sizeint; i++)
	{
		kf.props.push_back(Property(propsInfo[i].name, propsInfo[i].defValue));
	}
	FilterEntry fEnt;
	fEnt.flt = fltName;
	fEnt.keyframes = vector<Keyframe>({kf});
	usedFilters.push_back(fEnt);
}

void ClipCombo::removeFilter(int id)
{
	int sizeint = usedFilters.size();
	if (id >= 0 && id < sizeint)
	{
		usedFilters.erase(usedFilters.begin() + id);
	}
}

void ClipCombo::setFilterProp(int id, wstring propName, float value, int frameId)
{
	int sizeint = usedFilters.size();
	if (id < 0 || id >= sizeint)
		return;
	FilterEntry fEnt = usedFilters[id];
	if (frameId < 0 || frameId >= fEnt.keyframes.size())
		return;
	Keyframe kf = fEnt.keyframes[frameId];
	sizeint = kf.props.size();
	for (int i = 0; i < sizeint; i++)
	{
		if (propName == kf.props[i].name)
		{
			kf.props[i].value = value;
			break;
		}
	}
	fEnt.keyframes[frameId] = kf;
	usedFilters[id] = fEnt;
}

float ClipCombo::getFilterProp(int id, wstring propName, int frameId)
{
	float value = 0.0;
	int sizeint = usedFilters.size();
	if (id < 0 || id >= sizeint)
		return 0.0;
	FilterEntry fEnt = usedFilters[id];
	if (frameId < 0 || frameId >= fEnt.keyframes.size())
		return 0.0;
	Keyframe kf = fEnt.keyframes[frameId];

	for (int i = 0; i < sizeint; i++)
	{
		if (propName == kf.props[i].name)
		{
			return kf.props[i].value;
			break;
		}
	}
	return value;
}

vector<FilterEntry> ClipCombo::getUsedFilters()
{
	return usedFilters;
}

ClipType ClipCombo::getType()
{
	return CLIP_COMBO;
}

int ClipCombo::getFramesLength()
{
	return clipA->getFramesLength() + clipB->getFramesLength() - transFrames;
}

bool ClipCombo::usesSource(ClipSource *src)
{
	return (clipA->usesSource(src) || clipB->usesSource(src));
}

void ClipCombo::setTransition(wstring transName, int frames)
{
	usedTransition = transName;
	transFrames = frames;
}
