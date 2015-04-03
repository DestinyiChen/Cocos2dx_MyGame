#ifndef __STAGE_SCENE_H__
#define __STAGE_SCENE_H__

#include "cocos2d.h"

class StageScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void menuBackCallback(cocos2d::Ref* pSender);

	void startRound(float dt);

	CREATE_FUNC(StageScene);

public:
	int round;

};

#endif // __STAGE_SCENE_H__
