/////////////////////////////////////
// Include
#include "game.h"
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include "level.h"
#include "input.h"


/////////////////////////////////////
// Class Game
Game::Game()
{
	m_isGameActive = true;
	m_clockLastFrame = 0;

	for( int i = 0; i < gameObjectsCountMax; i++ )
		m_objects[i] = 0;

	m_shipFireCooldownTime = 0.0;
	m_alienAmplitudeTime = 0.0;
}

void Game::setupSystem()
{
	srand( time( 0 ) );

	m_renderSystem.initialize();
}

void Game::initialize()
{
	m_shipFireCooldownTime = 0.0;
	m_alienAmplitudeTime = 0.0;

	// Load level
	for( int r = 0; r < levelRows; r++ )
	{
		for( int c = 0; c < levelColumns; c++ )
		{
			unsigned char cellSymbol = levelData0[r][c];

			switch( cellSymbol )
			{
				// Create Ship
				case CellSymbol_Ship:
				{
					createObject(	GameObjectType_Ship,
									(c + 0.5),
									r,
									GetRenderCellSymbol( cellSymbol ),
									GetRenderCellSymbolColor( cellSymbol ),
									GetRenderCellSymbolBackgroundColor( cellSymbol ) );
					break;
				}

				// Create Alien
				case CellSymbol_Alien:
				{
					GameObject* alien = createObject(	GameObjectType_Alien,
														(c + 0.5),
														r,
														GetRenderCellSymbol( cellSymbol ),
														GetRenderCellSymbolColor( cellSymbol ),
														GetRenderCellSymbolBackgroundColor( cellSymbol ) );

					alien->setXSpeed( alienAmplitude * cos( m_alienAmplitudeTime ) );
					alien->setYSpeed( alienSpeed );
					break;
				}
			}

		}
	}
}

bool Game::frame()
{
	// Calculate delta time
	clock_t clockNow = clock();
	clock_t deltaClock = clockNow - m_clockLastFrame;
	float deltaTime = float(deltaClock) / CLOCKS_PER_SEC;
	m_clockLastFrame = clockNow;

	render();
	update( deltaTime );

	return m_isGameActive;
}

void Game::shutdown()
{
	for( int i = 0; i < gameObjectsCountMax; i++ )
		if( m_objects[i] != 0 )
		{
			delete m_objects[i];
			m_objects[i] = 0;
		}
}

void Game::render()
{
	// Start frame
	m_renderSystem.clear();

	// Deaw all game objects
	int objectsCount = 0;
	for( int i = 0; i < gameObjectsCountMax; i++ ) 
		if( m_objects[i] != 0 )
		{
			 m_objects[i]->render( &m_renderSystem );
			 objectsCount++;
		}

	// Draw objects count
	char buff[64];
	sprintf_s(buff, "Objs: %d", objectsCount);
	m_renderSystem.drawText(0, 0, buff, ConsoleColor_Gray, ConsoleColor_Black);

	// End frame
	m_renderSystem.flush();
}

void Game::update( float dt )
{
	bool haveAliveAliens = false;

	// Update all game objects
	for( int i = 0; i < gameObjectsCountMax; i++ ) 
	{
		GameObject* object = m_objects[i];

		if( object != 0 )
		{
			 object->update( dt );

			 switch( object->getType() )
			 {
				 // Hero ship
				 case GameObjectType_Ship:
				 {
					 // Borders
					 if( object->getX() < 0 )
						 object->setX( 0 );
					 else
					 if( object->getX() > screenColumns - 1 )
						 object->setX( screenColumns - 1 );

					// Move
					if( IsKeyDown( VK_LEFT ) )
						object->setXSpeed( -shipSpeed );
					else
					if( IsKeyDown( VK_RIGHT ) )
						object->setXSpeed( shipSpeed );
					else
						object->setXSpeed( 0.0 );
	 
					// Fire
					if( IsKeyDown( VK_SPACE ) )
					{
						if( m_shipFireCooldownTime <= 0.0 )
						{
							m_shipFireCooldownTime = shipFireCooldown;

							// Create bullet
							{
								GameObject* bullet = createObject(	GameObjectType_Bullet,
																	object->getX(),
																	object->getY() - 1,
																	GetRenderCellSymbol( CellSymbol_Bullet ),
																	GetRenderCellSymbolColor( CellSymbol_Bullet ),
																	GetRenderCellSymbolBackgroundColor( CellSymbol_Bullet ) );
								bullet->setYSpeed( -bulletSpeed );
							}
						}
					}
				 }

				 // Bullet
				 case GameObjectType_Bullet:
				 {
					 if( object->getY() < 0 )
					 {
						destroyObject( object );
					 }
					 else
					 {
						for( int e = 0; e < gameObjectsCountMax; e++ ) 
						{
							GameObject* anotherObject = m_objects[e];

							if( anotherObject != 0 )
							{
								if( anotherObject->getType() == GameObjectType_Alien )
								{
									if( anotherObject->intersects( object ) )
									{
										destroyObject( anotherObject );
										destroyObject( object );
										break;
									}
								}
							}
						}
					 }

					 break;
				 }

				 // Alien ship
				 case GameObjectType_Alien:
				 {
					 haveAliveAliens = true;

					 if( object->getY() >= screenRows )
						m_isGameActive = false;
					 else
						 object->setXSpeed( alienAmplitude * cos( m_alienAmplitudeTime ) );

					 break;
				 }
			 }
		}
	}

	// Ship cooldown time
	if( m_shipFireCooldownTime > 0.0 )
		m_shipFireCooldownTime -= dt;

	// Alien amplitude time
	m_alienAmplitudeTime += dt;

	// Victory
	if( !haveAliveAliens )
		m_isGameActive = false;
}

GameObject* Game::createObject( GameObjectType type, float x, float y, char symbol, ConsoleColor color, ConsoleColor bgColor )
{
	// Find free pointer and create object
	for( int i = 0; i < gameObjectsCountMax; i++ )
	{	
		if( m_objects[i] == 0 )
		{
			GameObject* object = new GameObject();

			object->setType( type );
			object->setX( x );
			object->setY( y );
			object->setSymbol( symbol );
			object->setColor( color );
			object->setBackgroundColor( bgColor );

			m_objects[i] = object;
			return object;
		}
	}

	return 0;
}

void Game::destroyObject( GameObject* object )
{
	for( int i = 0; i < gameObjectsCountMax; i++ )
	{	
		if( m_objects[i] == object )
		{
			delete m_objects[i];
			m_objects[i] = 0;
			return;
		}
	}
}