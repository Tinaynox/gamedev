#pragma once


/////////////////////////////////////
// Include
#include "gameObject.h"
#include "level.h"


/////////////////////////////////////
// Class Tank
class Tank
	: public GameObject
{
public:
	Tank();

	virtual void update( float dt );
	virtual void render( sf::RenderWindow* rw );

	void move( Direction direction );
	void fire();


protected:
	void calculateFrontCellPosition( float* x, float* y );

protected:
	float m_fireCooldownTime;
	float m_speed;
};
