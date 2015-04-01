#ifndef __ONLINE_SCENE_H__
#define __ONLINE_SCENE_H__

#include "cocos2d.h"

class OnLineScene : public cocos2d::Layer
{
public:

	static cocos2d::Scene* createScene();

	virtual bool init();

	void menuBackCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(OnLineScene);
};

#endif // __ONLINE_SCENE_H__
