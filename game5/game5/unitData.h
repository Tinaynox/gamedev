#pragma once

/////////////////////////////////////
// Include
#include "unitType.h"
#include "weaponType.h"


struct UnitData
{
	UnitType type;
	int row;
	int column;
	int health;
	WeaponType weapon;
};
