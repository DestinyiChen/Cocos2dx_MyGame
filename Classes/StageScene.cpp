#include "StoryScene.h"
#include "StageScene.h"

USING_NS_CC;

Scene* StageScene::createScene()
{
	auto scene = Scene::create();

	auto layer = StageScene::create();

	scene->addChild(layer);

	return scene;
}

bool StageScene::init()
{
	if ( !Layer::init() )
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backItem = MenuItemImage::create(
		"Menus/BackButtonNormal.png",
		"Menus/BackButtonSelected.png",
		CC_CALLBACK_1(StageScene::menuBackCallback, this));

	backItem->setPosition(Vec2(origin.x + visibleSize.width - backItem->getContentSize().width/2 ,
		origin.y + backItem->getContentSize().height/2));

	auto menu = Menu::create(backItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	auto label = Label::createWithTTF("Stage Scene", "fonts/Marker Felt.ttf", 24);

	label->setPosition(Vec2(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height - label->getContentSize().height));

	this->addChild(label, 1);

	auto sprite = Sprite::create("BGs/StageSceneBG.jpg");

	sprite->setScaleX(visibleSize.width/sprite->getContentSize().width);
	sprite->setScaleY(visibleSize.height/sprite->getContentSize().height);

	sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	this->addChild(sprite, 0);

	SpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Towers/TArrow-hd.plist", "Towers/TArrow-hd.png");
	auto towerSprite = Sprite::createWithSpriteFrameName("Arrow00.png");
	towerSprite->setPosition(ccp(200,200));
	this->addChild(towerSprite, 1);

	return true;
}

void StageScene::menuBackCallback(Ref* pSender)
{
	auto director = Director::getInstance();
	director->popScene();
}
