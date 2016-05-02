#pragma once


/////////////////////////////////////
// Include
#include "renderSystem.h"
#include "direction.h"


/////////////////////////////////////
// Level data
const int kLevelRows = kScreenRows;
const int kLevelColumns = 70;

const unsigned char	CellSymbol_Player1		 = '1';
const unsigned char	CellSymbol_Player2		 = '2';
const unsigned char	CellSymbol_Tank			 = 'T';
const unsigned char	CellSymbol_BrickWall	 = '#';
const unsigned char	CellSymbol_SteelWall	 = '@';
const unsigned char	CellSymbol_Base			 = 'B';
const unsigned char	CellSymbol_EnemySpawner	 = 'S';

const unsigned char kLevelData0[kLevelRows][kLevelColumns + 1] =		
{
	"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
	"@S                                @@                              S  @",
	"@                                 @@                                 @",
	"@                                 @@                                 @",
	"@   ##   ##   @@@###### S   @@@        @@@ S   ######@@@   ##   ##   @",
	"@   #######   @@@######     @@@        @@@     ######@@@   #######   @",
	"@   #######                 @@@        @@@                 #######   @",
	"@   ##   ##                 @@@@@@@@@@@@@@                 ##   ##   @",
	"@                                 @@                                 @",
	"@                @@@              @@              @@@                @",
	"@                @@@              @@              @@@                @",
	"@@@   @@@#####   ############            ############   #####@@@   @@@",
	"@@@   @@@#####   ######@@######        ######@@######   #####@@@   @@@",
	"@@@   @@@#####   ######@@@#####        #####@@@######   #####@@@   @@@",
	"@                   ###@@@@@###@@    @@###@@@@@###                   @",
	"@                     #########@@@@@@@@#########                     @",
	"@                           ##############                           @",
	"@   ##   ##                    ########                    ##   ##   @",
	"@   #######                                                #######   @",
	"@   #######   @@@######                        ######@@@   #######   @",
	"@   ##   ##   @@@######                        ######@@@   ##   ##   @",
	"@                        2   ############ 1                          @",
	"@                            ##B       ##                            @",
	"@                            ##        ##                            @",
	"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
};

const unsigned char	kBrickWallImage	 = 177;
const ConsoleColor kBrickWallSymbolColor = ConsoleColor_DarkYellow;
const ConsoleColor kBrickWallBackgroundColor = ConsoleColor_Red;

const unsigned char	kSteelWallImage	 = 254;
const ConsoleColor kSteelWallSymbolColor = ConsoleColor_Gray;
const ConsoleColor kSteelWallBackgroundColor = ConsoleColor_DarkGray;


/////////////////////////////////////
// Tanks data
const float kTankFireCooldownTime = 0.5;
const int kTankSize = 3;

enum TankColor
{
	TankColor_0,
	TankColor_1,
	TankColor_2
};

struct TankImageCell
{
	unsigned char symbol;
	TankColor symbolColor;
	TankColor backgroundColor;
};

const TankImageCell kTankImage[Direction_MAX][kTankSize][kTankSize] =
{
	// Left
	{
		{ {220, TankColor_1, TankColor_0}, {220, TankColor_1, TankColor_0}, {220, TankColor_1, TankColor_0} },
		{ {196, TankColor_2, TankColor_0}, {  4, TankColor_2, TankColor_1}, {221, TankColor_1, TankColor_0} },
		{ {223, TankColor_1, TankColor_0}, {223, TankColor_1, TankColor_0}, {223, TankColor_1, TankColor_0} }
	},
	// Up
	{
		{ {220, TankColor_1, TankColor_0}, {179, TankColor_2, TankColor_0}, {220, TankColor_1, TankColor_0} },
		{ {219, TankColor_1, TankColor_1}, {  4, TankColor_2, TankColor_1}, {219, TankColor_1, TankColor_1} },
		{ {223, TankColor_1, TankColor_0}, {  0, TankColor_0, TankColor_0}, {223, TankColor_1, TankColor_0} } 
	},
	//Right
	{
		{ {220, TankColor_1, TankColor_0}, {220, TankColor_1, TankColor_0}, {220, TankColor_1, TankColor_0} },
		{ {222, TankColor_1, TankColor_0}, {  4, TankColor_2, TankColor_1}, {196, TankColor_2, TankColor_0} },
		{ {223, TankColor_1, TankColor_0}, {223, TankColor_1, TankColor_0}, {223, TankColor_1, TankColor_0} }
	},
	// Down
	{
		{ {220, TankColor_1, TankColor_0}, {  0, TankColor_0, TankColor_0}, {220, TankColor_1, TankColor_0} },
		{ {219, TankColor_1, TankColor_1}, {  4, TankColor_2, TankColor_1}, {219, TankColor_1, TankColor_1} },
		{ {223, TankColor_1, TankColor_0}, {179, TankColor_2, TankColor_0}, {223, TankColor_1, TankColor_0} }
	}
};


/////////////////////////////////////
// Player data
const int kPlayerHealth = 16;
const int kPlayerSpeed = 10;


/////////////////////////////////////
// Enemy data
const int kEnemiesPerLevel = 24;
const int kEnemiesPerLevelInOneMoment = 6;
const int kEnemyHealth = 5;
const int kEnemySpeed = 5;
const float kEnemySpawnerSpawnTime = 10.0;
const float kEnemyAIAnalizeTime = 0.5;


/////////////////////////////////////
// Base data
const int kBaseColumns = 8;
const int kBaseRows = 2;
const int kBaseHealth = 3;

const ConsoleColor bc0 = ConsoleColor_Black;
const ConsoleColor bc1 = ConsoleColor_Gray;
const ConsoleColor bc2 = ConsoleColor_Red;
const ConsoleColor bc3 = ConsoleColor_DarkRed;

const ConsoleSymbolData kBaseImageNormal[kBaseRows][kBaseColumns] =
{
	{ { 17, bc2, bc0}, {221, bc1, bc0}, {254, bc0, bc3}, {254, bc0, bc3}, {254, bc0, bc3}, {254, bc0, bc3}, {222, bc1, bc0}, { 16, bc2, bc0} },
	{ {  0, bc0, bc0}, {221, bc1, bc0}, {254, bc0, bc3}, {176, bc0, bc1}, {176, bc0, bc1}, {254, bc0, bc3}, {222, bc1, bc0}, {  0, bc0, bc0} }
};

const ConsoleSymbolData kBaseImageDamaged[kBaseRows][kBaseColumns] =
{
	{ {  0, bc0, bc0}, {  0, bc0, bc0}, {254, bc0, bc3}, {254, bc0, bc3}, {  0, bc0, bc0}, {254, bc0, bc3}, {222, bc1, bc0}, { 16, bc2, bc0} },
	{ {  0, bc0, bc0}, {221, bc1, bc0}, {254, bc0, bc3}, {176, bc1, bc0}, {176, bc1, bc0}, {254, bc0, bc3}, {222, bc1, bc0}, {  0, bc0, bc0} }
};

const ConsoleSymbolData kBaseImageBroken[kBaseRows][kBaseColumns] =
{
	{ {  0, bc0, bc0}, {  0, bc0, bc0}, {  0, bc0, bc0}, {254, bc0, bc3}, {'_', bc3, bc0}, {254, bc0, bc3}, {  0, bc0, bc0}, {  0, bc0, bc0} },
	{ {  0, bc0, bc0}, {  0, bc0, bc0}, {254, bc0, bc3}, {  0, bc0, bc0}, {'/', bc1, bc0}, {254, bc0, bc3}, {222, bc1, bc0}, {  0, bc0, bc0} }
};


/////////////////////////////////////
// Bullet data
const float kBulletSpeed = 30.0;
const char kBulletImage = '*';


