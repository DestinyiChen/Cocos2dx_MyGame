#ifndef __STAGE_SCENE_H__
#define __STAGE_SCENE_H__

#include "cocos2d.h"

class StageScene : public cocos2d::Layer
{

public:

	static cocos2d::Scene* createScene();

	virtual bool init();

	void menuBackCallback(cocos2d::Ref* pSender);

	void initMap();
	void initSpriteFrameCache();

	void startRound(float dt);

	CREATE_FUNC(StageScene);

public:

	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;

	cocos2d::TMXTiledMap* map;
	cocos2d::TMXLayer* pathLayer;
	cocos2d::TMXObjectGroup* path;
	cocos2d::Vector<cocos2d::Node*> pathVector;

	cocos2d::SpriteFrameCache* stageSpriteFrameCache;

	int round;

};

#endif // __STAGE_SCENE_H__
