#include "Facility.h"
#include "Object.h"
#include "Map.h"
#include "App.h"
#include "Map.h"

Facility::Facility( CHIP_TYPE type, int width, int height, MapPtr map ) :
_chip_type( type ),
_width( width ),
_height( height ), 
_map( map ) {
	_connect_fixation_left = Coord( -1, -1 );
	_connect_fixation_right = Coord( -1, -1 );
}


Facility::~Facility( ) {

}

Coord Facility::getLineFixationLeft( ) const {
	return _connect_fixation_left;
}

Coord Facility::getLineFixationRight( ) const {
	return _connect_fixation_right;
}


void Facility::destroy ( const Coord& coord ) {
	for ( int i = 0; i < _width; i++ ) {
		for ( int j = 0; j < _height; j++ ) {
			Coord install_coord = coord;
			install_coord.x += i;
			install_coord.y += j;
			_map->deleteChip( install_coord );

		}
	}
}

bool Facility::install( const Coord& coord, unsigned char value ) {
	const int RANGE = 2;

	// �}�b�v�͈͊O�����ׂ�
	if ( coord.x - RANGE < 0 ||
		 coord.y < 0 ||
		 coord.x + RANGE + _width  >= COORD_WIDTH ||
		 coord.y + _height >= COORD_HEIGHT ) {
		return false;
	}

	for ( int i = -RANGE; i < _width + RANGE; i++ ) {
		for ( int j = 0; j < _height; j++ ) {
			Coord search_coord = coord;
			search_coord.x += i;
			search_coord.y += j;

			CHIP_TYPE type = _map->getChip( search_coord ).type;
			
			// ���b�h�]�[���𒲂ׂ�
			if ( i > -RANGE && i < _width + RANGE - 1 &&
				 j > -RANGE && j < _height ) {
				if ( type == CHIP_TYPE_LINE ) {
					return false;
				}
			}

			if ( ( type & CHIP_TYPE_FACILITY ) != 0 ) {
				return false;
			}
		}
	}

	// �}�b�v�ɓo�^
	for ( int i = 0; i < _width; i++ ) {
		for ( int j = 0; j < _height; j++ ) {
			Coord install_coord = coord;
			install_coord.x += i;
			install_coord.y += j;
			Map::Chip chip;
			chip.type = _chip_type;
			chip.value = value;
			_map->setChip( install_coord, chip );

		}
	}

	//���C���ڑ��Œ�ʒu�o�^
	_connect_fixation_left = Coord ( coord.x, coord.y + ( ( _height - 1 ) / 2 ) );
	_connect_fixation_right = Coord ( coord.x + _width - 1 , coord.y + ( ( _height - 1 ) / 2 ) );
	setCoord( coord );
	return true;
}

Coord exit_coord;

Coord Facility::getExitCoord( const Coord& coord ) const {
	Coord exit_coord( -1, -1 );
	if ( coord.getIdx( ) == _connect_fixation_left.getIdx( ) ) {
		exit_coord = _connect_fixation_right;
		exit_coord.x++;
	}
	if ( coord.getIdx( ) == _connect_fixation_right.getIdx( ) ) {
		exit_coord = _connect_fixation_left;
		exit_coord.x--;
	} 
	return exit_coord;
}