#ifndef __HOME_SCENE_H__
#define __HOME_SCENE_H__

#include "cocos2d.h"

class HomeScene : public cocos2d::Layer
{
public:

	static cocos2d::Scene* createScene();

	virtual bool init();

	void menuStoryCallback(cocos2d::Ref* pSender);
	void menuLANCallback(cocos2d::Ref* pSender);
	void menuOnLineCallback(cocos2d::Ref* pSender);
	void menuCloseCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(HomeScene);
};

#endif // __HOMEPAGE_SCENE_H__
