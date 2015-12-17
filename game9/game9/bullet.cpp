/////////////////////////////////////
// Include
#include "bullet.h"
#include "wall.h"


/////////////////////////////////////
// Class Bullet
Bullet::Bullet()
{
	m_type = GameObjectType_Bullet;
	m_ownerType = GameObjectType_None;

	setTextureRect( kBulletImage );
}


void Bullet::render( sf::RenderWindow* rw )
{
	GameObject::render( rw );
}

void Bullet::intersect( GameObject* object )
{
	// Destroy self
	setHealth( 0 );

	// Do damage to target
	object->doDamage( 1 );
}