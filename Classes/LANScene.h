#ifndef __LAN_SCENE_H__
#define __LAN_SCENE_H__

#include "cocos2d.h"

class LANScene : public cocos2d::Layer
{
public:

	static cocos2d::Scene* createScene();

	virtual bool init();

	void menuBackCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(LANScene);
};

#endif // __LAN_SCENE_H__
