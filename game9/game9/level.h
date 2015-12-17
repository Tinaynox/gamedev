#pragma once


/////////////////////////////////////
// Include
#include <SFML/Graphics.hpp>
#include "direction.h"


/////////////////////////////////////
// Extern
extern sf::Texture* g_atlas00;


/////////////////////////////////////
// Level data
const int kScreenRows = 25;
const int kScreenColumns = 80;
const int kLevelRows = kScreenRows;
const int kLevelColumns = 70;
const int kPixelsPerCell = 15;

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


const sf::IntRect kBrickWallImage = sf::IntRect( 0, 3*kPixelsPerCell, kPixelsPerCell, kPixelsPerCell );
const sf::IntRect kSteelWallImage = sf::IntRect( kPixelsPerCell, 3*kPixelsPerCell, kPixelsPerCell, kPixelsPerCell );


/////////////////////////////////////
// Tanks data
const float kTankFireCooldownTime = 0.5;
const int kTankSize = 3;
const sf::IntRect kTankImage = sf::IntRect(	0, 0, kTankSize*kPixelsPerCell, kTankSize*kPixelsPerCell );


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
const sf::IntRect kBaseImage = sf::IntRect(0, 5*kPixelsPerCell, kBaseColumns*kPixelsPerCell, kBaseRows*kPixelsPerCell);


/////////////////////////////////////
// Bullet data
const float kBulletSpeed = 30.0;
const sf::IntRect kBulletImage = sf::IntRect(0, 4*kPixelsPerCell, kPixelsPerCell, kPixelsPerCell);