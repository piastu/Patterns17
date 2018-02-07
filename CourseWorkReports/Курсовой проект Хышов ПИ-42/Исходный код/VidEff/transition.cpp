#include "transition.h"

Transition::Transition()
{

}

TransitionFade::TransitionFade() : Transition()
{

}

wstring TransitionFade::getName()
{
	return L"fade";
}

wstring TransitionFade::getDisplayName()
{
	return L"Simple fade";
}

Frame *TransitionFade::use(Frame *inpA, Frame *inpB, float pos)
{
	Frame *result = new Frame(inpA->width(), inpA->height(), nullptr);
	uint32_t *data = result->getData(),
			*dataA = inpA->getData(),
			*dataB = inpB->getData();
	int sizeInt = result->width() * result->height();
	for (int i = 0; i < sizeInt; i++)
	{
		Color cA, cB, c;
		cA.rgba = dataA[i];
		cB.rgba = dataB[i];
		c.setR((int)(cA.r() * (1.0f - pos) + cB.r() * pos));
		c.setG((int)(cA.g() * (1.0f - pos) + cB.g() * pos));
		c.setB((int)(cA.b() * (1.0f - pos) + cB.b() * pos));
		c.setA((int)(cA.a() * (1.0f - pos) + cB.a() * pos));
		data[i] = c.rgba;
	}

	if (inpA->isTemporary())
		delete inpA;
	if (inpB->isTemporary())
		delete inpB;

	return result;
}
