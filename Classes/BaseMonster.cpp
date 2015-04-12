#include "BaseMonster.h"

USING_NS_CC;

Node* BaseMonster::curPoint()
{
	return pathVector.at(pointIndex);
}

Node* BaseMonster::nextPoint()
{
	pointIndex++;
	if(pointIndex < pathVector.size())
	{
		return pathVector.at(pointIndex);
	}else
	{
		pointIndex = pathVector.size() - 1;
	}
	return NULL;
}

Animation* BaseMonster::createAnimation()
{
	Vector<SpriteFrame*> frames;

	for(int i = 0; i < 2; i++)
	{
		auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("boss_big01.png");
		frames.pushBack(frame);
	}

	return Animation::createWithSpriteFrames(frames);
}
