#pragma once


/////////////////////////////////////
// Include
#include "renderSystem.h"


/////////////////////////////////////
// Enum
enum GameObjectType
{
	GameObjectType_None,
	GameObjectType_Ship,
	GameObjectType_Bullet,
	GameObjectType_Alien
};


/////////////////////////////////////
// Class GameObject
class GameObject
{
public:
	GameObject();

	void render( RenderSystem* rs );
	void update( float dt );

	bool intersects( GameObject* object );


	void setType( GameObjectType type ){ m_type = type; }
	GameObjectType getType(){ return m_type; }

	void setX( float x ){ m_x = x; }
	float getX(){ return m_x; }

	void setY( float y ){ m_y = y; }
	float getY(){ return m_y; }

	void setXSpeed( float xSpeed ){ m_xSpeed = xSpeed; }
	float getXSpeed(){ return m_xSpeed; }

	void setYSpeed( float ySpeed ){ m_ySpeed = ySpeed; }
	float getYSpeed(){ return m_ySpeed; }

	void setSymbol( char symbol ){ m_symbol = symbol; }
	char getSymbol(){ return m_symbol; }

	void setColor( ConsoleColor color ){ m_color = color; }
	ConsoleColor getColor(){ return m_color; }

	void setBackgroundColor( ConsoleColor backgroundColor ){ m_backgroundColor = backgroundColor; }
	ConsoleColor getBackgroundColor(){ return m_backgroundColor; }

private:
	GameObjectType m_type;

	float m_x;
	float m_y;
	float m_xSpeed;
	float m_ySpeed;

	char m_symbol;
	ConsoleColor m_color;
	ConsoleColor m_backgroundColor;
};