// テトリス（カラーグラフィック液晶版） Tetris for Raspberry Pi Pico by K.Tanaka

#define SCENECLEARLINE 20 //ステージクリアの消去ライン数

//各種キャラクターコード定義
#define CODE_BLOCK 0x01
#define CODE_WALL 0x02
#define CODE_BRICK 0x03
#define CODE_SPACE 0
#define CODE_CLEARBLOCK 0x61

//カラー定義
#define COLOR_IBLOCK 2
#define COLOR_JBLOCK 1
#define COLOR_LBLOCK 8
#define COLOR_ZBLOCK 4
#define COLOR_SBLOCK 3
#define COLOR_OBLOCK 6
#define COLOR_TBLOCK 5
#define COLOR_WALL 9
#define COLOR_BITMAP 10
#define COLOR_BRICK 11
#define COLOR_FRAME 4
#define COLOR_SPACE 0
#define COLOR_CLEARBLOCK 7

#define SOUNDDONGLENGTH 7

//_Block構造体定義
typedef struct {
	//各ブロックの位置は、(0,0)と残り3個分の相対位置で定義
	int8_t x1,y1;
	int8_t x2,y2;
	int8_t x3,y3;
	int8_t color;//色
	int8_t rot; //回転可能回数、これを越えると初期位置に戻す
} _Block;

//_Music構造体定義
typedef struct {
	unsigned char *p; //曲配列の演奏中の位置
	unsigned char *startp; //曲配列のリピート位置
	unsigned char count; //発音中の音カウンタ
	unsigned short pr; //発音中の音（タイマ周期）
	unsigned char stop; //0:演奏中、1:終了
} _Music;

extern const unsigned char FontData[256*8];
