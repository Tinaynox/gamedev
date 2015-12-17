/////////////////////////////////////
// Include
#include "tankEnemy.h"
#include "utils.h"
#include "wall.h"
#include "bullet.h"


/////////////////////////////////////
// Class GameObject
TankEnemy::TankEnemy()
{
	m_type = GameObjectType_TankEnemy;
	m_analizeTime = kEnemyAIAnalizeTime;
	m_analizeTimer = GetRandomFloat( 0.0, m_analizeTime);
	m_lastAnalizeX = 0.0;
	m_lastAnalizeY = 0.0;

	m_health = kEnemyHealth;
	m_speed = kEnemySpeed;

	setSpriteColor( sf::Color( 0, 165, 226 ) );
}

TankEnemy::~TankEnemy()
{
	m_game->increaseDiedEnemiesCount();
}

void TankEnemy::update( float dt )
{
	Tank::update( dt );

	m_analizeTimer += dt;
	if( m_analizeTimer >= m_analizeTime )
	{
		m_analizeTimer = 0;
		analize();
	}
}

void TankEnemy::analize()
{
	float x = 0.0;
	float y = 0.0;
	calculateFrontCellPosition( &x, &y );

	float xDelta = 0.0;
	float yDelta = 0.0;

	switch( m_direction )
	{
		case Direction_Left: xDelta = -1.0; break;
		case Direction_Right: xDelta = 1.0; break;
		case Direction_Up: yDelta = -1.0; break;
		case Direction_Down: yDelta = 1.0; break;
	}


	// Find closest object and distance
	GameObject* object = 0;
	int distance = 0;
	do
	{
		object = m_game->checkIntersects( x, y, 1, 1, 0 );

		x += xDelta;
		y += yDelta;
		++distance;
	}
	while( object == 0 );


	// Defend from bullet
	if( object->getType() == GameObjectType_Bullet )
	{
		if( ((Bullet*)object)->getOwnerType() == GameObjectType_TankPlayer )
			fire();

		return;
	}

	// Attack!!
	if(    object->getType() == GameObjectType_TankPlayer
		|| object->getType() == GameObjectType_Base )
	{
		fire();
		return;
	}

	// 20% change direction
	if( 0 == rand()%5 )
	{
		// Move to random direction
		moveRandomDirection();
		return;
	}

	
	switch( object->getType() )
	{
	case GameObjectType_Wall:
		if( ((Wall*)object)->getInvulnerable() == false )
		{
			fire();
			return;
		}
		break;
	}


	// Change direction
	if(    distance == 1 
		|| ((int)m_lastAnalizeX == (int)getX() && (int)m_lastAnalizeY == (int)getY()) )
	{
		// Move to random direction
		moveRandomDirection();
		return;
	}

	m_lastAnalizeX = getX();
	m_lastAnalizeY = getY();
}

void TankEnemy::moveRandomDirection()
{
	Direction prevDirection = getDirection();
	Direction newDirection;
	do
	{
		newDirection = (Direction)( rand()%((int)Direction_MAX) );
	}
	while( prevDirection == newDirection );

	move( newDirection );
}