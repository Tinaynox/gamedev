/////////////////////////////////////
// Include
#include "enemySpawner.h"
#include "tankEnemy.h"
#include "utils.h"


/////////////////////////////////////
// Class EnemySpawner
EnemySpawner::EnemySpawner()
{
	m_type = GameObjectType_EnemySpawner;

	
	m_spawnTime = kEnemySpawnerSpawnTime;
	m_spawnTimer = GetRandomFloat( 0.0, m_spawnTime );

	m_physical = false;
}


void EnemySpawner::update( float dt )
{
	GameObject::update( dt );
	
	m_spawnTimer += dt;

	if( m_spawnTimer > m_spawnTime )
	{
		m_spawnTimer = 0.0f;

		int enemiesOnLevel = m_game->getObjectsCount( GameObjectType_TankEnemy );
		int enemiesStorageLeft = kEnemiesPerLevel - enemiesOnLevel - m_game->getDiedEnemiesCount();

		if( enemiesStorageLeft > 0 && enemiesOnLevel < kEnemiesPerLevelInOneMoment )
			m_game->createObject( GameObjectType_TankEnemy, getX(), getY() );
	}
}