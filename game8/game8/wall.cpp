/////////////////////////////////////
// Include
#include "wall.h"


/////////////////////////////////////
// Class Wall
Wall::Wall()
{
	m_type = GameObjectType_Wall;

	setImage( kBrickWallImage, kBrickWallSymbolColor, kBrickWallBackgroundColor );
}


void Wall::render( RenderSystem* rs )
{
	int row = int( m_y );
	int column = int( m_x ); 

	rs->drawChar( row, column, m_image.symbol, m_image.symbolColor, m_image.backgroundColor );
}

void Wall::setImage( unsigned char symbol, ConsoleColor symbolColor, ConsoleColor bgColor )
{
	m_image.symbol = symbol;
	m_image.symbolColor = symbolColor;
	m_image.backgroundColor = bgColor;
}