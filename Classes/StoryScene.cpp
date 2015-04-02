#include "HomeScene.h"
#include "StoryScene.h"
#include "StageScene.h"

USING_NS_CC;

Scene* StoryScene::createScene()
{
	auto scene = Scene::create();

	auto layer = StoryScene::create();

	scene->addChild(layer);

	return scene;
}

bool StoryScene::init()
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
		CC_CALLBACK_1(StoryScene::menuBackCallback, this));

	backItem->setPosition(Vec2(origin.x + visibleSize.width - backItem->getContentSize().width/2 ,
		origin.y + backItem->getContentSize().height/2));

	// Stage
	auto stageItem = MenuItemImage::create(
		"Menus/StageButtonNormal.png",
		"Menus/StageButtonSelected.png",
		CC_CALLBACK_1(StoryScene::menuStageCallback, this));

	stageItem->setPosition(Vec2(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height/2));

	//

	auto menu = Menu::create(backItem, stageItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	auto label = Label::createWithTTF("Story Scene", "fonts/Marker Felt.ttf", 24);

	label->setPosition(Vec2(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height - label->getContentSize().height));

	this->addChild(label, 1);

	auto sprite = Sprite::create("BGs/StorySceneBG.jpg");

	sprite->setScaleX(visibleSize.width/sprite->getContentSize().width);
	sprite->setScaleY(visibleSize.height/sprite->getContentSize().height);

	sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	this->addChild(sprite, 0);

	return true;
}

void StoryScene::menuBackCallback(Ref* pSender)
{
	auto director = Director::getInstance();
	auto scene = HomeScene::createScene();
	director->replaceScene(scene);
}

void StoryScene::menuStageCallback(Ref* pSender)
{
	auto director = Director::getInstance();
	auto scene = StageScene::createScene();
	director->pushScene(scene);
}
