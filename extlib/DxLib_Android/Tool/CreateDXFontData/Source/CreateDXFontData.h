#ifndef CREATEFONTDATA_H
#define CREATEFONTDATA_H

#include <windows.h>

/* �o�[�W�������

0      �����o�[�W����
1      �J�[�j���O���ǉ�

*/

/* �f�[�^�}�b�v

FONTDATAFILEHEADER

���k����Ċi�[
	FONTDATAFILEPRESSHEADER
	FONTDATAFILECHARADATA �~ �����̐�
	FONTDATAFILEKERNINGPAIRDATA �~ �J�[�j���O�y�A�̐�	

�t�H���g�C���[�W�f�[�^

*/

// �o�[�W����
#define DX_FONTDATAFILE_VERSION						(1)

// �����Z�b�g
#define DX_CHARSET_DEFAULT							(0)					// �f�t�H���g�����Z�b�g
#define DX_CHARSET_SHFTJIS							(1)					// ���{�ꕶ���Z�b�g
#define DX_CHARSET_HANGEUL							(2)					// �؍��ꕶ���Z�b�g
#define DX_CHARSET_BIG5								(3)					// �ɑ̕����Z�b�g
#define DX_CHARSET_GB2312							(4)					// �ȑ̕����Z�b�g
#define DX_CHARSET_WINDOWS_1252						(5)					// ����(���e�������̕����R�[�h)
#define DX_CHARSET_ISO_IEC_8859_15					(6)					// ����(���e�������̕����R�[�h)
#define DX_CHARSET_UTF8								(7)					// UTF8

// �t�H���g�̌��C���[�W�̃f�[�^�^�C�v
#define DX_FONT_SRCIMAGETYPE_1BIT					(0)					// 1�s�N�Z��1�r�b�g
#define DX_FONT_SRCIMAGETYPE_1BIT_SCALE4			(1)					// 1�s�N�Z��1�r�b�g�A�摜�𑜓x4�{
#define DX_FONT_SRCIMAGETYPE_1BIT_SCALE8			(2)					// 1�s�N�Z��1�r�b�g�A�摜�𑜓x8�{
#define DX_FONT_SRCIMAGETYPE_1BIT_SCALE16			(3)					// 1�s�N�Z��1�r�b�g�A�摜�𑜓x16�{
#define DX_FONT_SRCIMAGETYPE_4BIT_MAX15				(4)					// 1�s�N�Z��4�r�b�g�A�l�͈̔͂�0�`15
#define DX_FONT_SRCIMAGETYPE_8BIT_ON_OFF			(5)					// 1�s�N�Z��8�r�b�g�A�l�͈̔͂�0����0�ȊO
#define DX_FONT_SRCIMAGETYPE_8BIT_MAX16				(6)					// 1�s�N�Z��8�r�b�g�A�l�͈̔͂�0�`16
#define DX_FONT_SRCIMAGETYPE_8BIT_MAX64				(7)					// 1�s�N�Z��8�r�b�g�A�l�͈̔͂�0�`64
#define DX_FONT_SRCIMAGETYPE_8BIT_MAX255			(8)					// 1�s�N�Z��8�r�b�g�A�l�͈̔͂�0�`255

// �t�H���g�摜�̊K���r�b�g��
#define DX_FONTIMAGE_BIT_1							(0)
#define DX_FONTIMAGE_BIT_4							(1)
#define DX_FONTIMAGE_BIT_8							(2)

#define DEFAULT_FONT_SIZE							(16)				// �t�H���g�̃f�t�H���g�̃T�C�Y
#define DEFAULT_FONT_THINCK							(6)					// �t�H���g�̃f�t�H���g�̑���

// �t�H���g�񋓎��p�f�[�^�\����
struct ENUMFONTDATA
{
	wchar_t *				FontBuffer ;
	int						FontNum ;
	int						BufferNum ;
	const wchar_t *			EnumFontName ;
} ;

// �t�H���g�̊�{���
struct FONTBASEINFO
{
	WORD					FontThickness ;						// �t�H���g�̑���
	WORD					FontSize ;							// �`�悷��t�H���g�̃T�C�Y
	WORD					FontHeight ;						// �`�悷��t�H���g�̍ő�c��
	WORD					FontAddHeight ;						// �T�C�Y�����ׂ̈ɑ���������
	BYTE					Italic ;							// �C�^���b�N�t�H���g���ǂ���(TRUE:�C�^���b�N FALSE:��C�^���b�N)
	BYTE					Padding ;
	WORD					MaxWidth ;							// �t�H���g�̍ő啝
	WORD					CharSet ;							// �L�����N�^�Z�b�g
	WORD					CharCodeFormat ;					// �R�[�h�y�[�W
	WORD					Ascent ;							// �����̃x�[�X���C�������ԏ�܂ł̍���
	WORD					Padding2 ;
	DWORD					KerningPairNum ;					// �J�[�j���O�y�A�̐�
	DWORD					Padding3[ 10 ] ;
} ;

// �t�H���g�t�@�C���̃w�b�_���̈��k���镔��
struct FONTDATAFILEPRESSHEADER
{
	WORD					FontName[ 128 ] ;	// �t�H���g�̖��O( UTF-16LE )
	FONTBASEINFO			BaseInfo ;			// ��{���
	BYTE					ImageBitDepth ;		// �摜�̃r�b�g�[�x( DX_FONTIMAGE_BIT_1 �� )
	BYTE					Padding[ 3 ] ;
	DWORD					Padding2[ 16 ] ;
} ;

// �t�H���g�t�@�C���̃w�b�_���
struct FONTDATAFILEHEADER
{
	BYTE					Magic[ 4 ] ;		// FNTF
	WORD					Version ;			// �o�[�W����
	WORD					Padding ;
	DWORD					ImageAddress ;		// �摜�f�[�^���ۑ�����Ă���擪�A�h���X
	DWORD					MaxImageBytes ;		// �摜�f�[�^�̍ő�T�C�Y
	DWORD					CharaNum ;			// �������̐�
	DWORD					CharaExNum ;		// �������̓��A�����R�[�h�� 0x10000 �ȏ�̕����̐�
	FONTDATAFILEPRESSHEADER	Press ;				// �w�b�_�t�@�C�����̈��k�Ώۂ̕���
} ;

// �J�[�j���O�y�A���
struct FONTDATAFILEKERNINGPAIRDATA
{
	DWORD					First ;				// �y�A�̂P������
	DWORD					Second ;			// �y�A�̂Q������
	int						KernAmount ;		// ���炷�h�b�g��
	DWORD					Padding ;
} ;

// �t�@�C���ۑ��p�̃t�H���g�P�����̏��
struct FONTDATAFILECHARADATA
{
	DWORD					CodeUnicode ;		// Unicode �̕����R�[�h
	BYTE					Press ;				// ���k���Ă��邩�ǂ���( 1:���k���Ă���  0:���k���Ă��Ȃ� )
	BYTE					Padding ;
	short					DrawX ;				// �����摜��`�悷�ׂ��w���W
	short					DrawY ;				// �����摜��`�悷�ׂ��x���W
	short					AddX ;				// ���̕�����`�悷�ׂ����΂w���W
	WORD					SizeX ;				// �����̂w�T�C�Y
	WORD					SizeY ;				// �����̂x�T�C�Y
	DWORD					ImageAddress ;		// �摜�f�[�^���ۑ�����Ă���A�h���X( FONTDATAFILEHEADER.ImageAddress �̎����A�h���X�� 0 �Ƃ��� )
	DWORD					ImagePitch ;		// �摜�f�[�^�̂P���C��������̃o�C�g��
	DWORD					Padding2[ 2 ] ;
} ;

// �t�H���g�L���b�V���̊Ǘ��f�[�^
struct FONTMANAGE
{
	wchar_t					FontName[ 128 ] ;					// �t�H���g��
	FONTBASEINFO			BaseInfo ;							// ��{���
	int						ImageBitDepth ;						// �t�H���g�摜�̃r�b�g�[�x( DX_FONTIMAGE_BIT_1 �Ȃ� )

	int						UseTextOut ;						// TextOut ���g�p����^�C�v�̃t�H���g���ǂ���( TRUE:TextOut���g�p����  FALSE:GetGlyphOutline ���g�p���� )
	HFONT					FontObj ;							// �t�H���g�̃I�u�W�F�N�g�f�[�^
	HBITMAP					CacheBitmap ;						// �e�L�X�g�L���b�V���p�r�b�g�}�b�v
	unsigned char			*CacheBitmapMem ;					// �e�L�X�g�L���b�V���p�r�b�g�}�b�v�̃�����
	int						CacheBitmapMemPitch ;				// �e�L�X�g�L���b�V���p�r�b�g�}�b�v�̃s�b�`

	FONTDATAFILECHARADATA	CharaData ;							// �P�������̃f�[�^

	FONTDATAFILEKERNINGPAIRDATA * KerningPairData ;				// �J�[�j���O�y�A���

	void *					GetGlyphOutlineBuffer ;				// GetGlyphOutline �̃f�[�^�擾�p�Ɏg�p����o�b�t�@
	DWORD					GetGlyphOutlineBufferSize ;			// GetGlyphOutline �̃f�[�^�擾�p�Ɏg�p����o�b�t�@�̃T�C�Y

	unsigned char			*CacheMem ;							// �e�L�X�g�L���b�V��������
	int						CachePitch ;						// �e�L�X�g�L���b�V���������̃s�b�`	
	int						CacheDataBitNum ;					// �e�L�X�g�L���b�V����̂P�s�N�Z���̃r�b�g��
} ;

// Windows�p �t�H���g�V�X�e���p�\����
struct FONTSYSTEM_WIN
{
	HDC						Devicecontext ;						// FontCacheCharAddToHandle �̏����Ŏg�p����f�o�C�X�R���e�L�X�g
	HFONT					OldFont ;							// FontCacheCharAddToHandle �̏����Ŏg�p����t�H���g
	HBITMAP					OldBitmap ;							// FontCacheCharAddToHandle �̏����Ŏg�p����r�b�g�}�b�v
	TEXTMETRIC				TextMetric ;						// FontCacheCharAddToHandle �̏����Ŏg�p����t�H���g�̏��
} ;

// �t�H���g�V�X�e���p�\����
struct FONTSYSTEM
{
	BYTE					BitCountTable[ 256 ] ;				// �r�b�g�J�E���g�e�[�u��
} ;

// �t�H���g�����̏�����
extern int InitializeFont( void ) ;

// �t�H���g�f�[�^�̍쐬
extern FONTMANAGE *CreateFontManageData(
	const wchar_t *	FontName,
	int				Size,
	int				ImageBitDepth /* DX_FONTIMAGE_BIT_1�� */ , 
	int				Thick,
	int				Italic = FALSE ,
	int				CharSet = -1,
	int				CharCodeFormat = -1
) ;

// �t�H���g�f�[�^�̌�n��
extern int DeleteFontManageData( FONTMANAGE *ManageData ) ;

// �����L���b�V���̕�����ύX����
extern int FontCacheCharChange( FONTMANAGE *ManageData, const wchar_t *CharCode ) ;

// �t�H���g�f�[�^�t�@�C���̍쐬
extern int CreateFontDataFile(
	const wchar_t *	SaveFilePath,
	const wchar_t *	FontName,
	int				Size,
	int				ImageBitDepth /* DX_FONTIMAGE_BIT_1�� */ , 
	int				Thick,
	int				Italic = FALSE ,
	int				CharSet = -1,
	int				CharCodeFormat = -1,
	const wchar_t *	SaveCharaList = NULL
) ;

#endif // CREATEFONTDATA_H

