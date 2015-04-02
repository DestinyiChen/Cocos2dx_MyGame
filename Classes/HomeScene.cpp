#include "HomeScene.h"
#include "StoryScene.h"
#include "LANScene.h"
#include "OnLineScene.h"

USING_NS_CC;

Scene* HomeScene::createScene()
{
	auto scene = Scene::create();

	auto layer = HomeScene::create();

	scene->addChild(layer);

	return scene;
}

bool HomeScene::init()
{
	if ( !Layer::init() )
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto storyItem = MenuItemImage::create(
		"Menus/StoryButtonNormal.png",
		"Menus/StoryButtonSelected.png",
		CC_CALLBACK_1(HomeScene::menuStoryCallback, this));

	auto LANItem = MenuItemImage::create(
		"Menus/LANButtonNormal.png",
		"Menus/LANButtonSelected.png",
		CC_CALLBACK_1(HomeScene::menuLANCallback, this));

	auto onLineItem = MenuItemImage::create(
		"Menus/OnLineButtonNormal.png",
		"Menus/OnLineButtonSelected.png",
		CC_CALLBACK_1(HomeScene::menuOnLineCallback, this));

	storyItem->setPosition(Vec2(origin.x + visibleSize.width - storyItem->getContentSize().width/2 ,
		origin.y + visibleSize.height/2 + storyItem->getContentSize().height/2 + LANItem->getContentSize().height));

	LANItem->setPosition(Vec2(origin.x + visibleSize.width - LANItem->getContentSize().width/2 ,
		origin.y + visibleSize.height/2 + LANItem->getContentSize().height/2));

	onLineItem->setPosition(Vec2(origin.x + visibleSize.width - onLineItem->getContentSize().width/2 ,
		origin.y + visibleSize.height/2 + onLineItem->getContentSize().height/2 - LANItem->getContentSize().height));

	auto menu = Menu::create(storyItem, LANItem, onLineItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	auto label = Label::createWithTTF("Home Scene", "fonts/Marker Felt.ttf", 24);

	label->setPosition(Vec2(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height - label->getContentSize().height));

	this->addChild(label, 1);

	auto sprite = Sprite::create("BGs/HomeSceneBG.jpg");

	sprite->setScaleX(visibleSize.width/sprite->getContentSize().width);
	sprite->setScaleY(visibleSize.height/sprite->getContentSize().height);

	sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	this->addChild(sprite, 0);

	return true;
}

void HomeScene::menuStoryCallback(Ref* pSender)
{
	auto director = Director::getInstance();
	auto scene = StoryScene::createScene();
	director->replaceScene(scene);
}

void HomeScene::menuLANCallback(Ref* pSender)
{
	auto director = Director::getInstance();
	auto scene = LANScene::createScene();
	director->replaceScene(scene);
}

void HomeScene::menuOnLineCallback(Ref* pSender)
{
	auto director = Director::getInstance();
	auto scene = OnLineScene::createScene();
	director->replaceScene(scene);
}