#ifndef __BASE_MONSTER_H__
#define __BASE_MONSTER_H__

#include "cocos2d.h"

class BaseMonster : public cocos2d::Sprite
{
public:

	virtual bool init();
	CREATE_FUNC(BaseMonster);

	cocos2d::Node* curPoint();
	cocos2d::Node* nextPoint();

	cocos2d::Animation* createAnimation();

public:

	int pointIndex;
	cocos2d::Vector<cocos2d::Node*> pathVector;

	cocos2d::Animation *animationLeft;
	cocos2d::Animation *animationRight;

	CC_SYNTHESIZE(float, speed, Speed);
};

#endif // __BASE_MONSTER_H__
