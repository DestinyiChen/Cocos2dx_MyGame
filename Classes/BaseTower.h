#ifndef __BASE_TOWER_H__
#define __BASE_TOWER_H__

#include "cocos2d.h"

class BaseTower
{

public:
	float physicalAttackPoint;
	float magicAttackPoint;
	float attackRange;
	float attackSpeed;

	int dPAP;
	int dMAP;
	int dAR;
	int dAS;

	cocos2d::Action idelAction;
	cocos2d::Action attackAction;
	cocos2d::Action skillAction;

public:

	virtual void idel();
	virtual void attack();
	virtual void skill();

};

#endif // __BASE_TOWER_H__
