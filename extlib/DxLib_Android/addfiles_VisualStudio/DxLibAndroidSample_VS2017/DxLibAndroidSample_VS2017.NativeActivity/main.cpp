// ここにサンプルプログラムをペーストしてください
// 初期状態では LoadGraphScreen のサンプルプログラムが入力されています。
#include "DxLib.h"

int android_main( void )
{
	int GrHandle ;

	// ＤＸライブラリ初期化処理
	if( DxLib_Init() == -1 )
	{
		// エラーが起きたら直ちに終了
		 return -1 ;
	}

	// ＢＭＰ画像の読み込み
	GrHandle = LoadGraph( "test1.bmp" ) ;

	// 描画先を裏画面に変更
	SetDrawScreen( DX_SCREEN_BACK ) ;
	
	// 背景色をグレーに変更
	SetBackgroundColor( 128, 128, 128 ) ;

	// メインループ
	while( ProcessMessage() == 0 )
	{
		// 画面をクリア
		ClearDrawScreen() ;
		
		// ＢＭＰ画像の描画
		DrawGraph( 0, 0, GrHandle, TRUE ) ;

		// 裏画面の内容を表画面に反映
		ScreenFlip() ;
	}

	// ＤＸライブラリ使用の終了処理
	DxLib_End() ;

	// ソフトの終了
	return 0 ;
}
