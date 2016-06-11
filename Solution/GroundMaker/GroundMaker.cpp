#include "GroundMaker.h"

GroundMaker::GroundMaker( ) {
	_height = 0;
	_width = 0;
	_file_name = "map1-2.csv";
	loadToCSV( );
	save( );
}

GroundMaker::~GroundMaker( ) {
}

void GroundMaker::loadToCSV(  ) {
	//�t�@�C���̓ǂݍ���
	_file_name = "../" + _file_name;
	FILE* fp;
	fopen_s( &fp, _file_name.c_str( ), "r" );
	if ( fp == NULL ) {
		return;
	}
    //csv�t�@�C����1�s���ǂݍ���
	char buf[ 2048 ];
	while ( fgets( buf, 2048, fp ) != NULL ) {
		std::string str = buf;
		while ( true ) {
			if ( _height == 0 ) {
				_width++;
			}
			std::string::size_type index = str.find( "," );
			if ( index == std::string::npos ) {
				_data.push_back( atoi( str.c_str( ) ) );
				break;
			}
			std::string substr = str.substr( 0, index );
			_data.push_back( atoi( substr.c_str( ) ) );
			str = str.substr( index + 1 );
		}
		_height++;
	}
}

void GroundMaker::save( ) {
	FILE* fp;
	fopen_s( &fp,"../map.grd", "w" );
	fprintf( fp, "%d\n", _width );
	fprintf( fp, "%d\n", _height );
	for ( int i = 0; i < _width * _height; i++ ) {
		fprintf( fp, "%d\n", _data[ i ] );
	}
	fclose( fp );
}