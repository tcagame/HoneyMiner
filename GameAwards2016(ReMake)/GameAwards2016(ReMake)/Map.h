#pragma once

#include "Coord.h"
#include "Chip.h"
#include "smart_ptr.h"
#include <array>

PTR( Map );

class Map {
public:
	static Coord convScreenToPos( int sx, int sy );
public:
	struct Chip {
		CHIP_TYPE	type;
		unsigned char value;
	};
public:
	Map( );
	virtual ~Map( );
public:
	Chip getChip( const Coord& coord ) const;
	void setChip( const Coord& coord, const Chip& chip );
private:
	std::array< Chip, COORD_WIDTH * COORD_HEIGHT > _data;
};