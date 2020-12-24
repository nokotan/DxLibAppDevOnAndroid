# include <DxLib.h>

int android_main() {
  if (DxLib_Init() == -1) {
    return 0;
  }

  while (ProcessMessage() == 0) {
    ClearDrawScreen();
    DrawBox(0, 0, 300, 300, GetColor(255, 0, 0), TRUE);
    ScreenFlip();
  }

  DxLib_End();
  return 0;
}
