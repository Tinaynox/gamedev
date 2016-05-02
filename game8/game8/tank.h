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
	virtual void render( RenderSystem* rs );

	void setColor( ConsoleColor tankColor1, ConsoleColor tankColor2 );

	void move( Direction direction );
	void fire();


protected:
	void calculateFrontCellPosition( float* x, float* y );

protected:
	ConsoleSymbolData m_tankImage[Direction_MAX][kTankSize][kTankSize];

	float m_fireCooldownTime;
	float m_speed;
};
