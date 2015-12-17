/////////////////////////////////////
// Include
#include "tankPlayer.h"
#include "utils.h"


/////////////////////////////////////
// Class GameObject
TankPlayer::TankPlayer()
{
	m_type = GameObjectType_TankPlayer;

	m_keyLeft = 0;
	m_keyRight = 0;
	m_keyUp = 0;
	m_keyDown = 0;
	m_keyFire = 0;

	m_health = kPlayerHealth;
	m_speed = kPlayerSpeed;

	m_destroyAfterDeath = false;
}

void TankPlayer::update( float dt )
{
	Tank::update( dt );

	if( IsKeyDown( m_keyLeft ) )
		move( Direction_Left );
	else
	if( IsKeyDown( m_keyRight ) )
		move( Direction_Right );
	else
	if( IsKeyDown( m_keyUp ) )
		move( Direction_Up );
	else
	if( IsKeyDown( m_keyDown ) )
		move( Direction_Down );
	else
	{
		setXSpeed( 0 );
		setYSpeed( 0 );
	}

	if( IsKeyDown( m_keyFire ) )
		fire();
}

void TankPlayer::setKeys( int keyLeft, int keyRight, int keyUp, int keyDown, int keyFire )
{ 
	m_keyLeft = keyLeft; 
	m_keyRight = keyRight; 
	m_keyUp = keyUp;
	m_keyDown = keyDown; 
	m_keyFire = keyFire; 
}