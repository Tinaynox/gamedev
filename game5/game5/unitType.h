#pragma once

/////////////////////////////////////
// Include
#include "level.h"
#include "weaponType.h"


enum UnitType
{
	UnitType_None,
	UnitType_Hero,
	UnitType_Orc,
	UnitType_Skeleton
};

const char* UnitName_None			= "None";
const char* UnitName_Hero			= "Hero";
const char* UnitName_Orc			= "Orc";
const char* UnitName_Skeleton		= "Skeleton";


const char* GetUnitName( UnitType unitType )
{
	switch( unitType )
	{
		case UnitType_Hero:		return UnitName_Hero;
		case UnitType_Orc:		return UnitName_Orc;
		case UnitType_Skeleton:	return UnitName_Skeleton;
	}
	
	return UnitName_None;
}

WeaponType GetUnitDefaultWeapon( UnitType unitType )
{
	switch( unitType )
	{
		case UnitType_Hero:				return WeaponType_Fist;
		case UnitType_Orc:				return WeaponType_Club;
		case UnitType_Skeleton:			return WeaponType_Saber;
	}
	
	return WeaponType_None;
}

int GetUnitDefaultHealth( UnitType unitType )
{
	switch( unitType )
	{
		case UnitType_Hero:			return 400;
		case UnitType_Orc:			return 60;
		case UnitType_Skeleton:		return 80;
	}
	
	return 0;
}

UnitType GetUnitTypeFromCell( unsigned char cellSymbol )
{
	switch( cellSymbol )
	{
		case CellSymbol_Hero:				return UnitType_Hero;
		case CellSymbol_Orc:				return UnitType_Orc;
		case CellSymbol_Skeleton:			return UnitType_Skeleton;
	}

	return UnitType_None;
}