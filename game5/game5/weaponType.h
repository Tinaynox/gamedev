#pragma once

/////////////////////////////////////
// Include
#include "level.h"


enum WeaponType
{
	WeaponType_None,
	WeaponType_Fist,
	WeaponType_Stick,
	WeaponType_Club,
	WeaponType_Spear,
	WeaponType_Saber
};


const char* WeaponName_None			= "None";
const char* WeaponName_Fist			= "Fist";
const char* WeaponName_Stick		= "Stick";
const char* WeaponName_Club			= "Club";
const char* WeaponName_Spear		= "Spear";
const char* WeaponName_Saber		= "Saber";


const char* GetWeaponName( WeaponType weaponType )
{
	switch( weaponType )
	{
		case WeaponType_Fist:			return WeaponName_Fist;
		case WeaponType_Stick:			return WeaponName_Stick;
		case WeaponType_Club:			return WeaponName_Club;
		case WeaponType_Spear:			return WeaponName_Spear;
		case WeaponType_Saber:			return WeaponName_Saber;
	}
	
	return WeaponName_None;
}

int GetWeaponDamage( WeaponType weaponType )
{
	switch( weaponType )
	{
		case WeaponType_Fist:			return 2;
		case WeaponType_Stick:			return 16;
		case WeaponType_Club:			return 24;
		case WeaponType_Spear:			return 32;
		case WeaponType_Saber:			return 40;
	}
	
	return 0;
}

WeaponType GetWeaponTypeFromCell( unsigned char cellSymbol )
{
	switch( cellSymbol )
	{
		case CellSymbol_Stick:			return WeaponType_Stick;
		case CellSymbol_Club:			return WeaponType_Club;
		case CellSymbol_Spear:			return WeaponType_Spear;
		case CellSymbol_Saber:			return WeaponType_Saber;
	}

	return WeaponType_None;
}
