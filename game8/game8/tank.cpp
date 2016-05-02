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

	setColor( ConsoleColor_DarkGray, ConsoleColor_Gray );
}

void Tank::update( float dt )
{
	GameObject::update( dt );

	if( m_fireCooldownTime > 0 )
		m_fireCooldownTime -= dt;
}

void Tank::render( RenderSystem* rs )
{
	GameObject::render( rs );

	int row = int( m_y );
	int column = int( m_x ); 

	for( int r = 0; r < kTankSize; r++ )
		for( int c = 0; c < kTankSize; c++ )
		{
			ConsoleSymbolData sd = m_tankImage[m_direction][r][c];
			rs->drawChar( row + r, column + c, sd.symbol, sd.symbolColor, sd.backgroundColor );
		}
}

void Tank::setColor( ConsoleColor tankColor1, ConsoleColor tankColor2 )
{
	for( int d = Direction_Left; d < Direction_MAX; d++ )
		for( int r = 0; r < kTankSize; r++ )
			for( int c = 0; c < kTankSize; c++ )
			{
				// Symbol
				m_tankImage[d][r][c].symbol = kTankImage[d][r][c].symbol;

				// Symbol color
				switch( kTankImage[d][r][c].symbolColor )
				{
					case TankColor_0: 
						m_tankImage[d][r][c].symbolColor = ConsoleColor_Black; 
						break;

					case TankColor_1: 
						m_tankImage[d][r][c].symbolColor = tankColor1; 
						break;

					case TankColor_2: 
						m_tankImage[d][r][c].symbolColor = tankColor2; 
						break;
				}

				// Background color
				switch( kTankImage[d][r][c].backgroundColor )
				{
					case TankColor_0: 
						m_tankImage[d][r][c].backgroundColor = ConsoleColor_Black; 
						break;

					case TankColor_1: 
						m_tankImage[d][r][c].backgroundColor = tankColor1; 
						break;

					case TankColor_2: 
						m_tankImage[d][r][c].backgroundColor = tankColor2; 
						break;
				}
			}
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
