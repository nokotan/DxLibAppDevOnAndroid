#!/bin/bash

export Arch="x86_64"

echo "Compiling..."

clang -o libmain.so --shared -fPIC \
    Main.cpp \
    -I./extlib/DxLib_Android/addfiles/$Arch \
    -L./extlib/DxLib_Android/addfiles/$Arch \
    -landroid -lGLESv1_CM -lEGL -lstdc++ -lGLESv2 \
    -lOpenSLES -lm -lDxLib -lDxUseCLib -ljpeg -lpng \
    -lzlib -ltiff -ltheora_static -lvorbis_static -lvorbisfile_static \
    -logg_static -lbullet -lopus -llog -ldl

echo "done."

echo "Packaging..."

cp libmain.so lib/$Arch
cp $PREFIX/lib/libc++_shared.so lib/$Arch

aapt package -M AndroidManifest.xml -F app.apk -f
aapt add app.apk lib/$Arch/libmain.so
aapt add app.apk lib/$Arch/libc++_shared.so

echo "done."

echo "Signing..."

apksigner sign --key ~/.ssh/key.pk8 --cert ~/.ssh/key.x509.pem app.apk

echo "done."
