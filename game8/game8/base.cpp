/////////////////////////////////////
// Include
#include "base.h"


/////////////////////////////////////
// Class GameObject
Base::Base()
{
	m_type = GameObjectType_Base;

	m_width = kBaseColumns;
	m_height = kBaseRows;

	m_health = kBaseHealth;
	m_destroyAfterDeath = false;
}


void Base::render( RenderSystem* rs )
{
	int row = int( m_y );
	int column = int( m_x ); 

	for( int r = 0; r < kBaseRows; r++ )
		for( int c = 0; c < kBaseColumns; c++ )
		{
			ConsoleSymbolData sd;
			
			switch( m_health )
			{
				case 3: sd = kBaseImageNormal[r][c]; break;
				case 2: sd = kBaseImageDamaged[r][c]; break;
				default: sd = kBaseImageBroken[r][c]; break;
			}

			rs->drawChar( row + r, column + c, sd.symbol, sd.symbolColor, sd.backgroundColor );
		}
}