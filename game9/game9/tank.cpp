/////////////////////////////////////
// Include
#include "tank.h"
#include "bullet.h"


/////////////////////////////////////
// Class GameObject
Tank::Tank()
{
	m_type = GameObjectType_Tank;

	m_width = kTankSize;
	m_height = kTankSize;

	m_speed = 0;
	m_fireCooldownTime = 0.0;
}

void Tank::update( float dt )
{
	GameObject::update( dt );

	if( m_fireCooldownTime > 0 )
		m_fireCooldownTime -= dt;
}

void Tank::render( sf::RenderWindow* rw )
{
	sf::IntRect texRect = kTankImage;
	texRect.left += m_width * kPixelsPerCell * m_direction;
	setTextureRect( texRect );

	GameObject::render( rw );
}

void Tank::move( Direction direction )
{
	setDirection( direction );

	setXSpeed( 0 );
	setYSpeed( 0 );

	switch( m_direction )
	{
		case Direction_Left: setXSpeed( -m_speed ); break;
		case Direction_Right: setXSpeed( m_speed ); break;
		case Direction_Up: setYSpeed( -m_speed ); break;
		case Direction_Down: setYSpeed( m_speed ); break;
	}
}

void Tank::fire()
{
	if( m_fireCooldownTime > 0 )
		return;

	m_fireCooldownTime = kTankFireCooldownTime;

	float x = 0.0;
	float y = 0.0;
	float xSpeed = 0.0;
	float ySpeed = 0.0;

	calculateFrontCellPosition( &x, &y );

	switch( m_direction )
	{
		case Direction_Left: xSpeed = -kBulletSpeed; break;
		case Direction_Right: xSpeed = kBulletSpeed; break;
		case Direction_Up: ySpeed = -kBulletSpeed; break;
		case Direction_Down: ySpeed = kBulletSpeed; break;
	}

	Bullet* bullet = (Bullet*)m_game->createObject( GameObjectType_Bullet, x, y );
	if( bullet )
	{
		bullet->setOwnerType( m_type );
		bullet->setXSpeed( xSpeed );
		bullet->setYSpeed( ySpeed );
	}
}

void Tank::calculateFrontCellPosition( float* x, float* y )
{
	switch( m_direction )
	{
	case Direction_Left: 
		(*x) = int(getX()) - 0.01;
		(*y) = int(getY()) + (getHeight()/2.0);
		
		break;
	case Direction_Right: 
		(*x) = int(getX()) + getWidth() + 0.01;
		(*y) = int(getY()) + (getHeight()/2.0);
		break;
	case Direction_Up: 
		(*y) = int(getY()) - 0.01;
		(*x) = int(getX()) + (getWidth()/2.0);
		break;
	case Direction_Down: 
		(*y) = int(getY()) + getHeight() + 0.01;
		(*x) = int(getX()) + (getWidth()/2.0);
		break;
	}
}
