#pragma once


/////////////////////////////////////
// Include
#include "renderSystem.h"
#include <ctime>
#include "gameObject.h"
#include "gameObjectType.h"


/////////////////////////////////////
// Constants
const int kObjectsCountMax = 1024;


/////////////////////////////////////
// Forward declaration
class GameObject;


/////////////////////////////////////
// Class Game
class Game
{
public:
	Game();

	void setupSystem();
	void initialize();
	bool loop();
	void shutdown();

	GameObject* createObject( GameObjectType type, float x, float y );
	void destroyObject( GameObject* object );
	GameObject* checkIntersects( float x, float y, float width, float height, GameObject* exceptObject );
	bool moveObjectTo( GameObject* object, float x, float y );
	int getObjectsCount( GameObjectType type );

	int getDiedEnemiesCount(){ return m_diedEnemiesCount; }
	void increaseDiedEnemiesCount();

private:
	void render();
	void update( float dt );

private:
	bool m_isGameActive;
	clock_t m_clockLastFrame;

	RenderSystem m_renderSystem;

	GameObject* m_objects[kObjectsCountMax];

	GameObject* m_base;
	GameObject* m_player1;
	GameObject* m_player2;

	int m_diedEnemiesCount;
};