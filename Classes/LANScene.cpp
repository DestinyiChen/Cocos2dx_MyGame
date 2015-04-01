#include "HomeScene.h"
#include "LANScene.h"

USING_NS_CC;

Scene* LANScene::createScene()
{
	auto scene = Scene::create();

	auto layer = LANScene::create();

	scene->addChild(layer);

	return scene;
}

bool LANScene::init()
{
	if ( !Layer::init() )
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backItem = MenuItemImage::create(
		"BackButtonNormal.png",
		"BackButtonSelected.png",
		CC_CALLBACK_1(LANScene::menuBackCallback, this));

	backItem->setPosition(Vec2(origin.x + visibleSize.width - backItem->getContentSize().width/2 ,
		origin.y + backItem->getContentSize().height/2));

	auto menu = Menu::create(backItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	auto label = Label::createWithTTF("LAN Scene", "fonts/Marker Felt.ttf", 24);

	label->setPosition(Vec2(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height - label->getContentSize().height));

	this->addChild(label, 1);

	auto sprite = Sprite::create("LANSceneBG.jpg");

	sprite->setScaleX(visibleSize.width/sprite->getContentSize().width);
	sprite->setScaleY(visibleSize.height/sprite->getContentSize().height);

	sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	this->addChild(sprite, 0);

	return true;
}

void LANScene::menuBackCallback(Ref* pSender)
{
	auto director = Director::getInstance();
	auto scene = HomeScene::createScene();
	director->replaceScene(scene);
}
