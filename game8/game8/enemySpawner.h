#pragma once


/////////////////////////////////////
// Include
#include "gameObject.h"
#include "level.h"


/////////////////////////////////////
// Class Tank
class EnemySpawner
	: public GameObject
{
public:
	EnemySpawner();


	virtual void update( float dt );

private:
	float m_spawnTimer;
	float m_spawnTime;
};
