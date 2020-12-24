// �A�N�V�����T���v���v���O����( �⓹���� )
//
// �@�Q�c�A�N�V�����̊�{�A�⓹�̂���}�b�v�Ƃ̓����蔻��ł��B
// �A�N�V�����T���v���v���O�������������č⓹�ɑΉ����������̂ł��B
// �⓹�����������邽�߂Ɂu�⓹�⏕�u���b�N�v��u�㉺����̂݃u���b�N�v���ǉ�����Ă��܂��B
// �@�A���S���Y���̊֌W�ō⓹����肫�����ӏ��ɂ͕K���u�㉺����̂݃u���b�N�v���K�v�ł��B
// �܂��u�㉺����̂݃u���b�N�v�͉����瓖����Ɛ���ɓ��삵�Ȃ��̂ŁA�⓹��o�肫�����ӏ���
// �R�����ꍇ�́u�⓹�u���b�N�v�u�㉺����̂݃u���b�N�v�u�ʏ�u���b�N�v�Ƃ����z�u������
// �K�v������܂��B
// �@���̂悤�ɂ��Ȃ��Ă��ǂ����@������܂����A���̏ꍇ����̏�����⏕�̏�񂪍X�ɑ�����̂ŁA
// ����͂��̂悤�Ȏd�l�ɂ��܂����B
// �@�Γx45���ȊO�̍⓹�̎������A�������X�ɑ����邱�ƂɂȂ�̂ŁA����͎Γx45���̍⓹�݂̂�
// ���܂����B

#include "DxLib.h"

#define SCREEN_WIDTH     (640)                          // ��ʂ̉���
#define SCREEN_HEIGHT    (480)                          // ��ʂ̏c��
#define CHIP_SIZE        (32)                           // ��̃`�b�v�̃T�C�Y
#define MAP_WIDTH        (SCREEN_WIDTH / CHIP_SIZE)     // �}�b�v�̉���
#define MAP_HEIGHT       (SCREEN_HEIGHT / CHIP_SIZE)    // �}�b�v�̏c��

#define G                (0.3F)                         // �L�����Ɋ|����d�͉����x
#define JUMP_POWER       (9.0F)                         // �L�����̃W�����v��
#define SPEED            (5.0F)                         // �L�����̈ړ��X�s�[�h
#define CHAR_SIZE        (30)                           // �v���C���[�̃T�C�Y

// �}�b�v�f�[�^
// 1 : �ʏ�u���b�N
// 2 : �E�����o��n�ʃu���b�N
// 3 : �E��������n�ʃu���b�N
// 4 : �E��������V��u���b�N
// 5 : �E�����o��V��u���b�N
// 6 : �㉺����̂݃u���b�N
// 7 : �⓹�⏕�u���b�N
char MapData[MAP_HEIGHT][MAP_WIDTH] =
{
    0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1,
    1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,2,1,
    1,0,0,1,6, 3,0,0,0,0, 0,0,0,0,0, 0,0,2,7,1,
    1,0,0,4,7, 7,3,0,0,0, 0,0,0,0,0, 0,2,7,7,1,
    1,0,0,0,4, 6,1,0,0,0, 0,0,0,0,0, 1,1,1,1,1,

    1,0,0,0,0, 0,0,0,1,1, 0,0,0,0,0, 0,0,1,0,1,
    1,0,0,0,0, 0,0,0,0,0, 0,0,1,1,0, 0,0,1,0,1,
    1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,1,0,1,
    1,0,1,1,1, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1,
    1,0,0,0,0, 0,0,1,6,3, 0,0,0,0,2, 6,1,0,0,1,

    1,0,0,0,0, 0,0,4,7,1, 0,0,0,2,7, 7,1,0,0,1,
    1,0,0,0,0, 0,0,0,1,1, 0,0,0,1,1, 1,1,0,0,1,
    1,0,0,2,6, 3,0,0,0,0, 0,0,0,1,1, 1,1,0,0,1,
    1,0,2,7,7, 7,3,0,0,0, 0,0,0,0,0, 0,0,0,0,1,
    1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1,
} ;

float PlX, PlY ;            // �v���C���[�̍��W(���S���W)
float PlDownSp ;            // �v���C���[�̗������x
char PlJumpFlag ;           // �v���C���[���W�����v�����A�̃t���O

int Input, EdgeInput ;      // ���͏��
int FrameStartTime ;        // �U�O�e�o�r�Œ�p�A���ԕۑ��p�ϐ�



// �}�b�v�`�b�v�̒l���擾����֐�
int GetChipParam( float X, float Y ) ;

// �⓹�u���b�N���l�������}�b�v�`�b�v�̒l���擾����֐�
int GetChipParam2( float X, float Y ) ;

// �L�����N�^���}�b�v�Ƃ̓����蔻����l�����Ȃ���ړ�����֐�
int CharMove( float *X, float *Y, float *DownSP,
                    float MoveX, float MoveY, float Size, char *JumpFlag ) ;

// �A�N�V�����T���v���v���O�������C���֐�
int ActMain( void ) ;

// �}�b�v�Ƃ̓����蔻��( �ʏ�u���b�N�Ƃ̔���̂� )
// ( �߂�l 0:������Ȃ�����  1:���ӂɓ�������  2:�E�ӂɓ�������
//                            3:��ӂɓ�������  4:���ӂɓ������� )
// ���ӁFMoveX �� MoveY �A�ǂ������Е����O����Ȃ��Ƃ܂Ƃ��ɓ��삵�܂���
int MapHitCheck( float X, float Y, float *MoveX, float *MoveY ) ;

// �}�b�v�Ƃ̓����蔻��( �⓹�u���b�N�A�㉺����u���b�N�Ƃ̔�������� )
// ( �߂�l 0:������Ȃ�����  1:��ӂɓ�������  2:���ӂɓ������� )
int MapHitCheck2( float X, float Y, float *MoveX, float *MoveY ) ;



// WinMain�֐�
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    LPSTR lpCmdLine, int nCmdShow )
{
    ChangeWindowMode( TRUE ) ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() == -1 ) return -1 ;

    // �A�N�V�����Q�[���̃��C���֐����Ă�
    ActMain() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �I��
    return 0 ;
}

// �A�N�V�����T���v���v���O�������C��
int ActMain( void )
{
    // �`���𗠉�ʂɃZ�b�g
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // ���������M����҂��Ȃ�
    SetWaitVSyncFlag( FALSE ) ;

    // �v���C���[�̍��W��������
    PlX = 320.0F ;        PlY = 240.0F ;

    // �v���C���[�̗������x��������
    PlDownSp = 0.0F ;

    // �W�����v���t���O��|��
    PlJumpFlag = FALSE ;

    // ���͏�Ԃ̏�����
    Input = 0 ;
    EdgeInput = 0 ;

    // �U�O�e�o�r�Œ�p�A���ԕۑ��p�ϐ������݂̃^�C���J�E���g�ɃZ�b�g
    FrameStartTime = GetNowCount() ;

    // ���C�����[�v�J�n�A�d�r�b�L�[�ŊO�ɏo��
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
    {
        // ��ʂ̃N���A
        ClsDrawScreen() ;

        // �P/�U�O�b���܂ő҂�
        while( GetNowCount() - FrameStartTime < 1000 / 60 ){ Sleep( 1 ) ; }

        // ���݂̃^�C���J�E���g��ۑ�
        FrameStartTime = GetNowCount() ;

        // ���͏�Ԃ��X�V
        {
            int i ;

            // �p�b�h�P�ƃL�[�{�[�h������͂𓾂�
            i = GetJoypadInputState( DX_INPUT_KEY_PAD1 ) ;

            // �G�b�W����������͂��Z�b�g
            EdgeInput = i & ~Input ;

            // ���͏�Ԃ̕ۑ�
            Input = i ;
        }

        // �v���C���[�̈ړ�����
        {
            float MoveX, MoveY ;

            // �ړ��ʂ̏�����
            MoveX = 0.0F ;
            MoveY = 0.0F ;

            // ���E�̈ړ�������
            if( ( Input & PAD_INPUT_LEFT ) != 0 ) MoveX -= SPEED ;
            if( ( Input & PAD_INPUT_RIGHT ) != 0 ) MoveX += SPEED ;

            // �n�ɑ��������Ă���ꍇ�̂݃W�����v�{�^��(�{�^���P or �y�L�[)������
            if( PlJumpFlag == FALSE && ( EdgeInput & PAD_INPUT_A ) != 0 )
            {
                PlDownSp = -JUMP_POWER ;
                PlJumpFlag = TRUE ;
            }

            // ��������
            PlDownSp += G ;

            // �������x���ړ��ʂɉ�����
            MoveY = PlDownSp ;

            // �ړ��ʂɊ�Â��ăL�����N�^�̍��W���ړ�
            CharMove( &PlX, &PlY, &PlDownSp, MoveX, MoveY, CHAR_SIZE, &PlJumpFlag ) ;
        }

        // �}�b�v�̕`��
        {
            int i, j ;

            for( i = 0 ; i < MAP_HEIGHT ; i ++ )
            {
                for( j = 0 ; j < MAP_WIDTH ; j ++ )
                {
                    // �P�`�V�̓u���b�N�`�b�v��\���Ă���̂łP�`�V�̂Ƃ��낾���`��
                    switch( MapData[i][j] )
                    {
                    case 1 :
                    case 6 :
                    case 7 :
                        DrawBox(
                            j * CHIP_SIZE,                i * CHIP_SIZE,
                            j * CHIP_SIZE + CHIP_SIZE,    i * CHIP_SIZE + CHIP_SIZE,
                            GetColor( 255, 255, 255 ), TRUE ) ;
                        break ;

                    case 2 :
                        DrawTriangle(
                            j * CHIP_SIZE,                i * CHIP_SIZE + CHIP_SIZE,
                            j * CHIP_SIZE + CHIP_SIZE,    i * CHIP_SIZE,
                            j * CHIP_SIZE + CHIP_SIZE,    i * CHIP_SIZE + CHIP_SIZE,
                            GetColor( 255, 255, 255 ), TRUE ) ;
                        break ;

                    case 3 :
                        DrawTriangle(
                            j * CHIP_SIZE,                i * CHIP_SIZE,
                            j * CHIP_SIZE + CHIP_SIZE,    i * CHIP_SIZE + CHIP_SIZE,
                            j * CHIP_SIZE,                i * CHIP_SIZE + CHIP_SIZE,
                            GetColor( 255, 255, 255 ), TRUE ) ;
                        break ;

                    case 4 :
                        DrawTriangle(
                            j * CHIP_SIZE,                i * CHIP_SIZE,
                            j * CHIP_SIZE + CHIP_SIZE,    i * CHIP_SIZE,
                            j * CHIP_SIZE + CHIP_SIZE,    i * CHIP_SIZE + CHIP_SIZE,
                            GetColor( 255, 255, 255 ), TRUE ) ;
                        break ;

                    case 5 :
                        DrawTriangle(
                            j * CHIP_SIZE,                i * CHIP_SIZE + CHIP_SIZE,
                            j * CHIP_SIZE,                i * CHIP_SIZE,
                            j * CHIP_SIZE + CHIP_SIZE,    i * CHIP_SIZE,
                            GetColor( 255, 255, 255 ), TRUE ) ;
                        break ;
                    }
                }
            }
        }

        // �L�����N�^�̕`��
        DrawBox( ( int )( PlX - CHAR_SIZE * 0.5F ),     ( int )( PlY - CHAR_SIZE * 0.5F ),
                 ( int )( PlX + CHAR_SIZE * 0.5F ) + 1, ( int )( PlY + CHAR_SIZE * 0.5F ) + 1,
                    GetColor( 255, 0, 0 ), TRUE ) ;

        // ��ʂ̍X�V
        ScreenFlip() ;
    }

    // �I��
    return 0 ;
}

// �L�����N�^���}�b�v�Ƃ̓����蔻����l�����Ȃ���ړ�����
int CharMove( float *X, float *Y, float *DownSP,
                    float MoveX, float MoveY, float Size, char *JumpFlag )
{
    float Dummy = 0.0F ;
    float hsize ;
    float MoveXBackup = MoveX ;
    float MoveYBackup = MoveY ;

    // �L�����N�^�̍���A�E��A�����A�E�������������蔻��̂���
    // �}�b�v�ɏՓ˂��Ă��邩���ׁA�Փ˂��Ă�����␳����

    // �����̃T�C�Y���Z�o
    hsize = Size * 0.5F ;

    // �܂��㉺�ړ����������Ń`�F�b�N
    {
        // �����̃`�F�b�N�A�����u���b�N�̏�ӂɒ����Ă����痎�����~�߂�
        if( MapHitCheck( *X - hsize, *Y + hsize, &Dummy, &MoveY ) == 3 ) *DownSP = 0.0F ;

        // �E���̃`�F�b�N�A�����u���b�N�̏�ӂɒ����Ă����痎�����~�߂�
        if( MapHitCheck( *X + hsize, *Y + hsize, &Dummy, &MoveY ) == 3 ) *DownSP = 0.0F ;

        // ����̃`�F�b�N�A�����u���b�N�̉��ӂɓ������Ă����痎��������
        if( MapHitCheck( *X - hsize, *Y - hsize, &Dummy, &MoveY ) == 4 && *DownSP < 0.0f ) *DownSP *= -1.0F ;

        // �E��̃`�F�b�N�A�����u���b�N�̉��ӂɓ������Ă����痎��������
        if( MapHitCheck( *X + hsize, *Y - hsize, &Dummy, &MoveY ) == 4 && *DownSP < 0.0f ) *DownSP *= -1.0F ;
    }

    // ���ɍ��E�ړ����������Ń`�F�b�N
    {
        // �����̃`�F�b�N
        MapHitCheck( *X - hsize, *Y + hsize, &MoveX, &Dummy ) ;

        // �E���̃`�F�b�N
        MapHitCheck( *X + hsize, *Y + hsize, &MoveX, &Dummy ) ;

        // ����̃`�F�b�N
        MapHitCheck( *X - hsize, *Y - hsize, &MoveX, &Dummy ) ;

        // �E��̃`�F�b�N
        MapHitCheck( *X + hsize, *Y - hsize, &MoveX, &Dummy ) ;

        // ���E�ړ����������Z
        *X += MoveX ;
        MoveX = 0.0f ;
    }

    // �Ō�ɍ⓹�u���b�N�A�㉺����u���b�N���܂߂ă`�F�b�N
    {
        // ��ӂ̃`�F�b�N�A�����u���b�N�̏�ӂɒ����Ă����痎�����~�߂�
        if( MapHitCheck2( *X, *Y + hsize, &MoveX, &MoveY ) == 1 ) *DownSP = 0.0F ;

        // ���ӂ̃`�F�b�N�A�����u���b�N�̉��ӂɒ����Ă����痎��������
        if( MapHitCheck2( *X, *Y - hsize, &MoveX, &MoveY ) == 2 && *DownSP < 0.0f ) *DownSP *= -1.0f ;

        // �㉺�ړ����������Z
        *Y += MoveY ;
        MoveY = 0.0f ;
    }

    // �ڒn��ԕۑ�
    {
        int ChipL1, ChipC1, ChipR1 ;
        int ChipL2, ChipC2, ChipR2 ;

        // �����Ƀu���b�N�����邩����
        ChipL1 = GetChipParam2( *X - Size * 0.5F, *Y + Size * 0.5F + 2.0F ) ;
        ChipC1 = GetChipParam2( *X,               *Y + Size * 0.5F + 2.0F ) ;
        ChipR1 = GetChipParam2( *X + Size * 0.5F, *Y + Size * 0.5F + 2.0F ) ;
        if( ChipL1 == 1 || ChipC1 != 0 || ChipR1 == 1 )
        {
            // �u���b�N����������ڒn���ɂ���
            *JumpFlag = FALSE ;
        }
        else
        {
            // �u���b�N�������ꍇ

            // �O��W�����v���ł�������A���������ւ̑��x�������ꍇ�͖������ŃW�����v���ɂ���
            if( *JumpFlag == TRUE || MoveYBackup <= 0.0f )
            {
                // �W�����v���ɂ���
                *JumpFlag = TRUE ;
            }
            else
            {
                // �O��ڒn���Ă��āA����ڒn���Ă��Ȃ������ꍇ�A�����ɓ��������𔻒肷��

                // �������ӂɃu���b�N�����邩���ׂ�
                ChipL1 = GetChipParam( *X - Size * 0.5f, *Y + Size * 0.5F ) ;
                ChipC1 = GetChipParam( *X              , *Y + Size * 0.5F ) ;
                ChipR1 = GetChipParam( *X + Size * 0.5f, *Y + Size * 0.5F ) ;
                ChipL2 = GetChipParam( *X - Size * 0.5f, *Y + Size * 0.5F + CHIP_SIZE / 2.0f ) ;
                ChipC2 = GetChipParam( *X              , *Y + Size * 0.5F + CHIP_SIZE / 2.0f ) ;
                ChipR2 = GetChipParam( *X + Size * 0.5f, *Y + Size * 0.5F + CHIP_SIZE / 2.0f ) ;
                if( ChipL1 == 1 || ChipL1 == 2 || ChipL1 == 3 || ChipL1 == 6 || ChipL1 == 7 ||
                    ChipL2 == 1 || ChipL2 == 2 || ChipL2 == 3 || ChipL2 == 6 || ChipL2 == 7 ||
                    ChipC1 == 1 || ChipC1 == 2 || ChipC1 == 3 || ChipC1 == 6 || ChipC1 == 7 ||
                    ChipC2 == 1 || ChipC2 == 2 || ChipC2 == 3 || ChipC2 == 6 || ChipC2 == 7 ||
                    ChipR1 == 1 || ChipR1 == 2 || ChipR1 == 3 || ChipR1 == 6 || ChipR1 == 7 ||
                    ChipR2 == 1 || ChipR2 == 2 || ChipR2 == 3 || ChipR2 == 6 || ChipR2 == 7 )
                {
                    int addcy = 0 ;

                    // �������ӂɃu���b�N���������ꍇ�́A�����̃u���b�N�ɖ������ڒn������
                    if( ChipC1 != 0 || ChipC2 != 0 )
                    {
                        if( ChipC1 == 0 ) addcy = 1 ;
                    }
                    else
                    if( ChipL1 != 0 || ChipL2 != 0 )
                    {
                        if( ChipL1 == 0 ) addcy = 1 ;
                    }
                    else
                    {
                        if( ChipR1 == 0 ) addcy = 1 ;
                    }

                    // �ڒn�����邽�߂ɖ�����葫���̃u���b�N�܂ňړ�������
                    MoveY = ( ( ( int )( *Y + hsize ) / CHIP_SIZE + 1 + addcy ) * CHIP_SIZE - 1.0f ) - ( *Y + hsize ) ;
                    MapHitCheck2( *X, *Y + hsize, &MoveX, &MoveY ) ;
                    *Y += MoveY ;
                    MoveY = 0.0f ;

                    // �������x0�Őڒn���ɂ���
                    *DownSP = 0.0F ;
                    *JumpFlag = FALSE ;
                }
                else
                {
                    // ���ꂪ����������W�����v���ɂ���
                    *JumpFlag = TRUE ;
                }
            }
        }
    }

    // �I��
    return 0 ;
}

// �}�b�v�Ƃ̓����蔻��( �ʏ�u���b�N�Ƃ̔���̂� )
// ( �߂�l 0:������Ȃ�����  1:���ӂɓ�������  2:�E�ӂɓ�������
//                            3:��ӂɓ�������  4:���ӂɓ������� )
// ���ӁFMoveX �� MoveY �A�ǂ������Е����O����Ȃ��Ƃ܂Ƃ��ɓ��삵�܂���
int MapHitCheck( float X, float Y,
                    float *MoveX, float *MoveY )
{
    float afX, afY ;

    // �ړ��ʂ𑫂�
    afX = X + *MoveX ;
    afY = Y + *MoveY ;

    // �����蔻��̂���u���b�N�ɓ������Ă��邩�`�F�b�N
    if( GetChipParam( afX, afY ) == 1 )
    {
        float blx, bty, brx, bby ;

        // �������Ă�����ǂ��痣���������s��

        // �u���b�N�̏㉺���E�̍��W���Z�o
        blx = (float)( (int)afX / CHIP_SIZE ) * CHIP_SIZE ;        // ���ӂ� X ���W
        brx = (float)( (int)afX / CHIP_SIZE + 1 ) * CHIP_SIZE ;    // �E�ӂ� X ���W

        bty = (float)( (int)afY / CHIP_SIZE ) * CHIP_SIZE ;        // ��ӂ� Y ���W
        bby = (float)( (int)afY / CHIP_SIZE + 1 ) * CHIP_SIZE ;    // ���ӂ� Y ���W

        // ��ӂɓ������Ă����ꍇ
        if( *MoveY > 0.0F )
        {
            // �ړ��ʂ�␳����
            *MoveY = bty - Y - 1.0F  ;

            // ��ӂɓ��������ƕԂ�
            return 3 ;
        }

        // ���ӂɓ������Ă����ꍇ
        if( *MoveY < 0.0F )
        {
            // �ړ��ʂ�␳����
            *MoveY = bby - Y + 1.0F ;

            // ���ӂɓ��������ƕԂ�
            return 4 ;
        }

        // ���ӂɓ������Ă����ꍇ
        if( *MoveX > 0.0F )
        {
            // �ړ��ʂ�␳����
            *MoveX = blx - X - 1.0F ;

            // ���ӂɓ��������ƕԂ�
            return 1 ;
        }

        // �E�ӂɓ������Ă����ꍇ
        if( *MoveX < 0.0F )
        {
            // �ړ��ʂ�␳����
            *MoveX = brx - X + 1.0F ;

            // �E�ӂɓ��������ƕԂ�
            return 2 ;
        }

        // �����ɗ�����K���Ȓl��Ԃ�
        return 4 ;
    }

    // �ǂ��ɂ�������Ȃ������ƕԂ�
    return 0 ;
}

// �}�b�v�Ƃ̓����蔻��( �⓹�u���b�N�A�㉺����u���b�N�Ƃ̔�������� )
// ( �߂�l 0:������Ȃ�����  1:��ӂɓ�������  2:���ӂɓ������� )
int MapHitCheck2( float X, float Y, float *MoveX, float *MoveY )
{
    float afX, afY ;
    int Chip ;

    // �ړ��ʂ𑫂�
    afX = X + *MoveX ;
    afY = Y + *MoveY ;

    // �u���b�N�ɓ������Ă��邩�`�F�b�N
    Chip = GetChipParam( afX, afY ) ;
    if( Chip != 0 )
    {
        float blx, bty, brx, bby ;
        float blh ;
        float plx, ply ;

        // �u���b�N�̏㉺���E�̍��W���Z�o
        blx = (float)( (int)afX / CHIP_SIZE ) * CHIP_SIZE ;        // ���ӂ� X ���W
        brx = (float)( (int)afX / CHIP_SIZE + 1 ) * CHIP_SIZE ;    // �E�ӂ� X ���W

        bty = (float)( (int)afY / CHIP_SIZE ) * CHIP_SIZE ;        // ��ӂ� Y ���W
        bby = (float)( (int)afY / CHIP_SIZE + 1 ) * CHIP_SIZE ;    // ���ӂ� Y ���W

        // �v���C���[�̈ʒu���u���b�N�̂ǂ̈ʒu�ɂ��邩�Z�o
        plx = ( afX - blx ) / CHIP_SIZE ;
        ply = ( afY - bty ) / CHIP_SIZE ;

        // �⓹�⏕�u���b�N�������ꍇ�͏㉺�̍⓹�u���b�N�𔻒�Ώۂɂ���
        if( Chip == 7 )
        {
            float addy ;

            // �㉺�̋߂��u���b�N��Ώۂɂ���
            if( ply < 0.5f )
            {
                addy = -CHIP_SIZE ;
            }
            else
            {
                addy =  CHIP_SIZE ;
            }

            // �u���b�N��蒼��
            Chip = GetChipParam( afX, afY + addy ) ;

            // �u���b�N�̏㉺���E�̍��W���ĎZ�o
            bty = (float)( (int)( afY + addy ) / CHIP_SIZE ) * CHIP_SIZE ;        // ��ӂ� Y ���W
            bby = (float)( (int)( afY + addy ) / CHIP_SIZE + 1 ) * CHIP_SIZE ;    // ���ӂ� Y ���W

            // �v���C���[�̈ʒu���u���b�N�̂ǂ̈ʒu�ɂ��邩�Z�o
            ply = ( afY - bty ) / CHIP_SIZE ;
        }

        // �u���b�N�̃^�C�v�ɂ���ď����𕪊�
        switch( Chip )
        {
        case 2 :    // �E�����o��u���b�N
            // �v���C���[�̈ʒu�ł̃u���b�N�̍������Z�o
            blh = bby - plx * CHIP_SIZE ;

            // �u���b�N�ɂ������Ă����ꍇ
            if( afY > blh )
            {
                // �ړ��ʂ�␳����
                *MoveY = blh - Y - 1.0f ;

                // ���ӂɓ��������ƕԂ�
                return 1 ;
            }
            break ;

        case 3 :    // �E��������u���b�N
            // �v���C���[�̈ʒu�ł̃u���b�N�̍������Z�o
            blh = bty + plx * CHIP_SIZE ;

            // �u���b�N�ɂ������Ă����ꍇ
            if( afY > blh )
            {
                // �ړ��ʂ�␳����
                *MoveY = blh - Y - 1.0f ;

                // ���ӂɓ��������ƕԂ�
                return 1 ;
            }
            break ;

        case 4 :    // �E��������V��u���b�N
            // �v���C���[�̈ʒu�ł̃u���b�N�̍������Z�o
            blh = bty + plx * CHIP_SIZE ;

            // �u���b�N�ɂ������Ă����ꍇ
            if( afY < blh )
            {
                // �ړ��ʂ�␳����
                *MoveY = blh - Y + 1.0f ;

                // ��ӂɓ��������ƕԂ�
                return 2 ;
            }
            break ;

        case 5 :    // �E�����o��V��u���b�N
            // �v���C���[�̈ʒu�ł̃u���b�N�̍������Z�o
            blh = bby - plx * CHIP_SIZE ;

            // �u���b�N�ɂ������Ă����ꍇ
            if( afY < blh )
            {
                // �ړ��ʂ�␳����
                *MoveY = blh - Y + 1.0f ;

                // ��ӂɓ��������ƕԂ�
                return 2 ;
            }
            break ;

        case 1 :    // �ʏ�u���b�N
        case 6 :    // �㉺����̂݃u���b�N
            // ��ӂɓ������Ă����ꍇ
            if( *MoveY > 0.0F )
            {
                // �ړ��ʂ�␳����
                *MoveY = bty - Y - 1.0F ;

                // ���ӂɓ��������ƕԂ�
                return 1 ;
            }

            // ���ӂɓ������Ă����ꍇ
            if( *MoveY < 0.0F )
            {
                // �ړ��ʂ�␳����
                *MoveY = bby - Y + 1.0F  ;

                // ��ӂɓ��������ƕԂ�
                return 2 ;
            }

            // �����ɗ�����K���Ȓl��Ԃ�
            return 1 ;
        }
    }

    // �ǂ��ɂ�������Ȃ������ƕԂ�
    return 0 ;
}

// �}�b�v�`�b�v�̒l���擾����֐�
int GetChipParam( float X, float Y )
{
    int x, y ;

    // �����l�֕ϊ�
    x = (int)X / CHIP_SIZE ;
    y = (int)Y / CHIP_SIZE ;

    // �}�b�v����͂ݏo�Ă����� 0 ��Ԃ�
    if( x >= MAP_WIDTH || y >= MAP_HEIGHT || x < 0 || y < 0 ) return 0 ;

    // �w��̍��W�ɊY������}�b�v�̏���Ԃ�
    return MapData[ y ][ x ] ;
}

// �⓹�u���b�N���l�������}�b�v�`�b�v�̒l���擾����֐�
int GetChipParam2( float X, float Y )
{
    int Chip ;

    Chip = GetChipParam( X, Y ) ;

    // �⓹�u���b�N�ł͂Ȃ������炻�̂܂ܒl��Ԃ�
    if( Chip < 2 || Chip > 7 )
    {
        return Chip ;
    }

    // �⓹�u���b�N�̏ꍇ�͍⓹���l�����ē������Ă��邩����
    {
        float blx, bty, brx, bby ;
        float blh ;
        float xr, yr ;

        // �u���b�N�̏㉺���E�̍��W���Z�o
        blx = (float)( (int)X / CHIP_SIZE ) * CHIP_SIZE ;        // ���ӂ� X ���W
        brx = (float)( (int)X / CHIP_SIZE + 1 ) * CHIP_SIZE ;    // �E�ӂ� X ���W

        bty = (float)( (int)Y / CHIP_SIZE ) * CHIP_SIZE ;        // ��ӂ� Y ���W
        bby = (float)( (int)Y / CHIP_SIZE + 1 ) * CHIP_SIZE ;    // ���ӂ� Y ���W

        // �v���C���[�̈ʒu���u���b�N�̂ǂ̈ʒu�ɂ��邩�Z�o
        xr = ( X - blx ) / CHIP_SIZE ;
        yr = ( Y - bty ) / CHIP_SIZE ;

        // �⓹�⏕�u���b�N�������ꍇ�͏㉺�̍⓹�u���b�N�𔻒�Ώۂɂ���
        if( Chip == 7 )
        {
            float addy ;

            // �㉺�̋߂��u���b�N��Ώۂɂ���
            if( yr < 0.5f )
            {
                addy = -CHIP_SIZE ;
            }
            else
            {
                addy =  CHIP_SIZE ;
            }

            // �u���b�N��蒼��
            Chip = GetChipParam( X, Y + addy ) ;

            // �u���b�N�̏㉺���E�̍��W���ĎZ�o
            bty = (float)( (int)( Y + addy ) / CHIP_SIZE ) * CHIP_SIZE ;        // ��ӂ� Y ���W
            bby = (float)( (int)( Y + addy ) / CHIP_SIZE + 1 ) * CHIP_SIZE ;    // ���ӂ� Y ���W

            // �v���C���[�̈ʒu���u���b�N�̂ǂ̈ʒu�ɂ��邩�Z�o
            yr = ( yr - bty ) / CHIP_SIZE ;
        }

        // �u���b�N�̃^�C�v�ɂ���ď����𕪊�
        switch( Chip )
        {
        case 2 :    // �E�����o��u���b�N
            // �v���C���[�̈ʒu�ł̃u���b�N�̍������Z�o
            blh = bby - xr * CHIP_SIZE ;

            // �u���b�N�ɓ������Ă��邩����
            if( Y > blh )
            {
                return Chip ;
            }
            break ;

        case 3 :    // �E��������u���b�N
            // �v���C���[�̈ʒu�ł̃u���b�N�̍������Z�o
            blh = bty + xr * CHIP_SIZE ;

            // �u���b�N�ɓ������Ă��邩����
            if( Y > blh )
            {
                return Chip ;
            }
            break ;

        case 4 :    // �E��������V��u���b�N
            // �v���C���[�̈ʒu�ł̃u���b�N�̍������Z�o
            blh = bty + xr * CHIP_SIZE ;

            // �u���b�N�ɓ������Ă��邩����
            if( Y < blh )
            {
                return Chip ;
            }
            break ;

        case 5 :    // �E�����o��V��u���b�N
            // �v���C���[�̈ʒu�ł̃u���b�N�̍������Z�o
            blh = bby - xr * CHIP_SIZE ;

            // �u���b�N�ɓ������Ă��邩����
            if( Y < blh )
            {
                return Chip ;
            }
            break ;

        case 6 :    // �㉺����̂݃u���b�N
            return Chip ;
        }
    }

    // �������Ă��Ȃ�������u���b�N�Ȃ��̒l��Ԃ�
    return 0 ;
}

