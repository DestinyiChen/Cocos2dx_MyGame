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

	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

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

	initMap();
	initSpriteFrameCache();

	round = 0;
	this->schedule(schedule_selector(StageScene::startRound), 3.0f);

	return true;
}

void StageScene::menuBackCallback(Ref* pSender)
{
	auto director = Director::getInstance();
	director->popScene();
}

void StageScene::initMap()
{
	map = TMXTiledMap::create("Maps/map.tmx");

	pathLayer = map->getLayer("PathLayer");
	pathLayer->setAnchorPoint(Vec2(0.5f, 0.5f));
	pathLayer->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	path = map->getObjectGroup("path");
	Node* pathNode = NULL;
	int count = 0;
	auto point = path->getObject("p" + count);

	while(point.begin() != point.end())
	{
		float x = point.at("x").asFloat();
		float y = point.at("y").asFloat();

		pathNode = Node::create();
		pathNode->setPosition(x, y);

		this->pathVector.pushBack(pathNode);
	}

	pathNode = NULL;

	this->addChild(map, 1);
}

void StageScene::initSpriteFrameCache()
{
	stageSpriteFrameCache = SpriteFrameCache::getInstance();

	// Towers
	stageSpriteFrameCache->addSpriteFramesWithFile("Towers/TArrow-hd.plist", "Towers/TArrow-hd.png");

	// Monsters
	stageSpriteFrameCache->addSpriteFramesWithFile("Monsters/Monsters01-hd.plist", "Monsters/Monsters01-hd.png");
}

void StageScene::startRound(float dt)
{
	if (++round > 10) {
		this->unschedule(schedule_selector(StageScene::startRound));
		return;
	}

	auto towerSprite = Sprite::createWithSpriteFrameName("Arrow00.png");
	towerSprite->setPosition(Vec2(round*visibleSize.width/11, round*visibleSize.height/11));
	this->addChild(towerSprite, 1);

	auto monsterSprite = Sprite::createWithSpriteFrameName("boss_big01.png");
	monsterSprite->setPosition(Vec2(round*visibleSize.width/11 + 50, round*visibleSize.height/11 + 50));
	this->addChild(monsterSprite, 1);

	this->schedule(schedule_selector(StageScene::startRound), 1.0f);
}