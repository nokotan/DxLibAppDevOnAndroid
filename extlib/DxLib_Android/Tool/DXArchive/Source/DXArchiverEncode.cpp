// ============================================================================
//
//			�c�w�`�t�@�C���쐬�\�t�g
//
//	Creator			: �R�c�@�I
//	Creation Date	: 2003/09/13
//	Version			: 1.08
//
// ============================================================================

// include ----------------------------
#include "DXArchive.h"
#include "FileLib.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <direct.h>

// define -----------------------------
#define VERSION			"1.08"				// �o�[�W����
#define FILETYPE		"dxa"				// �g���q

// code -------------------------------

// ���C���֐�
int main( int argc, char *argv[] )
{
	char SrcPath[256], DestPath[256], *KeyString, *SrcDirectoryPath, *DestFilePath ;
	bool Press ;
	bool NoOutput ;
	bool NoKey ;
	bool AlwaysHuffman ;
	int HuffmanSize ;
	int i ;

	printf( "�c�w�`�t�@�C���ȈՍ쐬�\�t�g  Ver%s\n", VERSION ) ;

	// ���������������w���v���o��
	if( argc == 1 ) goto ERR ;

	Press = true ;
	NoOutput = false ;
	NoKey = false ;
	HuffmanSize = 10 ;
	AlwaysHuffman = false ;
	SrcDirectoryPath = NULL ;
	DestFilePath = NULL ;
	KeyString = NULL ;
	for( i = 1 ; i < argc ; i ++ )
	{
		if( argv[i][0] == '-' && argv[i][1] == 'K' && argv[i][2] == ':' )
		{
			KeyString = argv[i] + 3 ;
		}
		else
		if( argv[i][0] == '-' && argv[i][1] == 'N' && argv[i][2] == 'P' && argv[i][3] == '\0' )
		{
			Press = false ;
		}
		else
		if( argv[i][0] == '-' && argv[i][1] == 'N' && argv[i][2] == 'S' && argv[i][3] == '\0' )
		{
			NoOutput = true ;
		}
		else
		if( argv[i][0] == '-' && argv[i][1] == 'N' && argv[i][2] == 'K' && argv[i][3] == '\0' )
		{
			NoKey = true ;
		}
		else
		if( argv[i][0] == '-' && argv[i][1] == 'H' && argv[i][2] == ':' )
		{
			HuffmanSize = atoi( argv[i] + 3 ) ;
			if( HuffmanSize < 0 )
			{
				HuffmanSize = 0 ;
			}
			else
			if( HuffmanSize > 255 )
			{
				HuffmanSize = 255 ;
			}
		}
		else
		if( argv[i][0] == '-' && argv[i][1] == 'A' && argv[i][2] == 'H' && argv[i][3] == '\0' )
		{
			AlwaysHuffman = true ;
		}
		else
		if( SrcDirectoryPath == NULL )
		{
			SrcDirectoryPath = argv[i] ;
		}
		else
		{
			DestFilePath = argv[i] ;
		}
	}

	if( SrcDirectoryPath == NULL )
		goto ERR ;

	// �\�[�X�p�X�̃t���p�X���쐬����
	ConvertFullPath__( SrcDirectoryPath, SrcPath ) ;

	// �o�̓t�@�C���p�X�̍쐬
	{
		if( DestFilePath != NULL )
		{
			char temp[256] ;

			strcpy( temp, DestFilePath ) ;
			ConvertFullPath__( temp, DestPath ) ;
		}
		else
		{
			// �\�[�X�p�X����o�̓t�@�C�������쐬����
			sprintf( DestPath, "%s.%s", SrcPath, FILETYPE ) ;
		}
	}

	// �A�[�J�C�u�t�@�C�����쐬����
	DXArchive::EncodeArchiveOneDirectory( DestPath, SrcPath, Press, AlwaysHuffman, ( u8 )HuffmanSize, KeyString, NoKey, NoOutput ? false : true ) ;

	// �I��
	return 0 ;

ERR:

	printf( "DxaEncode.exe [Option] SrcDirectoryPath  [DestFilePath]\n\n" ) ;
	printf( "�E�c�w�`�t�@�C���ɂ������t�H���_���h���b�O���h���b�v���邾���ł��쐬�\�ł�\n" ) ; 
	printf( "�E-K  �I�v�V�����Ō���ݒ�o���܂�(�ő唼�p63����) �@��  -K:KeyCode \n" ) ; 
	printf( "�E-NP �A�[�J�C�u���Ɉ��k���s��Ȃ�\n" ) ;
	printf( "�E-NS �i�s�󋵂�\�����Ȃ�\n" ) ;
	printf( "�E-NK �Í����������{���Ȃ�\n" ) ;
	printf( "�E-H  �t�@�C���̐�[�Ɩ��[���n�t�}�����k����T�C�Y(�P��:�L���o�C�g)( 0 �` 255 )\n" ) ;
	printf( "      �f�t�H���g��10�@�@��  -H:20  ( ���A-H:255 �Ńt�@�C���S�̂��n�t�}�����k )\n" ) ;
	printf( "�E-AH �S�Ẵt�@�C���t�H�[�}�b�g���n�t�}�����k�̑ΏۂƂ���\n" ) ;
	printf( "      ( �f�t�H���g�ł� png �� wav �Ȃǃ��W���[�ȃt�@�C���t�H�[�}�b�g�̂ݑΏ� )\n" ) ;
	return -1; 
}


