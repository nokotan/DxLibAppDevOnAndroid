# DxLibAppDevOnAndroid

Develop Android Native apps with DxLib on Android 

## Requirements

- termux (available on [Google Play](https://play.google.com/store/apps/details?id=com.termux) or [F-Droid](https://f-droid.org/en/packages/com.termux/))

## Setup

```sh
pkg install curl build-essential aapt openssl-tool apksigner
# And install your favorite text editor
pkg install vim
```

## Gerenating Singing Key

```sh
# Build.sh expects that keys are in ~/.ssh/
openssl genrsa -3 -out key.pem 2048
openssl req -new -x509 -key key.pem -out key.x509.pem -days 10000 -subj '/'
openssl pkcs8 -in key.pem -topk8 -outform DER -out key.pk8 -nocrypt
```

## Build APK

```sh
bash Build.sh
```

## Installing APK

### On Android 11

Go on `File App`, then Select `Termux`

### On Android 10 and earlier

Now Preparing...


