#ifndef CTEXT_H
#define CTEXT_H

#include "CTexture.h"

/*
文字の描画
*/
class CText {
public:
	//テクスチャのインスタンス
	static CTexture mFont;
	//文字の描画
	static void DrawChar(char ch, int x, int y, int w, int h);
	//文字列の描画
	//DrawString(文字列, 画面X座標, 画面Y座標, 文字幅, 文字高さ)
	static void DrawString(char *s, int x, int y, int w, int h);
};

#endif
