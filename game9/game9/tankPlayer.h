#pragma once


/////////////////////////////////////
// Include
#include "tank.h"


/////////////////////////////////////
// Class TankPlayer
class TankPlayer
	: public Tank
{
public:
	TankPlayer();

	void update( float dt );

	void setKeys( int keyLeft, int keyRight, int keyUp, int keyDown, int keyFire );

protected:
	int m_keyLeft;
	int m_keyRight;
	int m_keyUp;
	int m_keyDown;
	int m_keyFire;
};
