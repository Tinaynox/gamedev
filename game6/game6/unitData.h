#pragma once


/////////////////////////////////////
// Include
#include "unitType.h"
#include "unitOrder.h"


struct UnitData
{
	UnitType type;

	int health;

	float x;
	float y;

	float xSpeed;
	float ySpeed;

	UnitOrder xOrder;
	UnitOrder yOrder;
};
