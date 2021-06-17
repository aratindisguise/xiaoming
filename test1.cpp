#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<share.h>
#include<time.h>
#include<ctype.h>
#include<conio.h>

constexpr auto X = 60;
constexpr auto Y = 4;
constexpr auto  CHESS_X = 60;
constexpr auto  CHESS_Y = 4;

struct XH {
	int X;
	int Y;
};
typedef struct _chess_data {
	char chessflag;
	char data[4][4];
	COORD xy;
}chess_data;

void gotoxy(int x,int y) 
{
	COORD XY = { 0,0 };
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	XY.X = x;
	XY.Y = y;
	SetConsoleCursorPosition(H, XY);
}
chess_data cdata[5][4] = { 0 };
void InitChessData() {
	cdata[0][0].xy.Y = CHESS_Y + 4;
	cdata[0][0].xy.X= CHESS_X + 4;
	cdata[0][0].data[0][0] = 1;
	cdata[0][0].data[1][0] = 1;
	cdata[0][0].data[0][1] = 1;
	cdata[0][0].data[1][1] = 1;
	cdata[0][1] = cdata[0][2] = cdata[0][3] = cdata[0][0];
}
void showchess(chess_data chess) {
	int x, y = {0};
	for (x = 0; x <= 3; x++) {
		for (y=0;y<=3;y++)
		{

		if (chess.data[x][y]){
			gotoxy(chess.xy.X+x*2,chess.xy.Y+y);
			printf("¡õ");
			}
		}

		}
}
void clearchess(chess_data chess) {
	int x, y;
	for (x = 0; x <= 3; x++) {
		for (y = 0; y <= 3; y++) {
			if (chess.data[x][y]) {
				gotoxy(chess.xy.X + x * 2, chess.xy.Y + y);
				printf("  ");
			}
		}
	}
}
void downmove(chess_data *chess) {
	clearchess(*chess);
	chess->xy.Y += 1;
	showchess(*chess);
}
void leftmove(chess_data *chess) {
	clearchess(*chess);
	chess->xy.X -= 2;
	showchess(*chess);
}
void rightmove(chess_data *chess) {
	clearchess(*chess);
	chess->xy.X += 2;
	showchess(*chess);
}
void upmove(chess_data* chess) {
	clearchess(*chess);
	chess->xy.Y -= 1;
	showchess(*chess);
}
void playgame(void) {
	InitChessData();

	showchess(cdata[0][0]);	
	
}
void drawM() {
	int i;
	gotoxy(X, Y);
	printf("©³");
	for (i = 0; i < 62; i++) {
		printf("©¥");
	}
	printf("©·");
	for (i = 0; i < 15; i++) {
		gotoxy(X,Y+1+i);
		printf("©§");
	}
	for (i = 0; i < 15; i++) {
		gotoxy(X + 63, Y + 1 + i);
		printf("©§");

	}
	gotoxy(X, Y +16);
	printf("©»");
	for (i = 0; i < 62; i++) {
		printf("©¥");
	}
	printf("©¿");
}
int leftcheckchess(chess_data chess) {
	for (int x : x < 3; x++) {
		for (int y; y < 3; y++) {
			if (chess.data[x][y]) {
				if (chess.xy.X  <= CHESS_X + 2) {
					return 1;
				}
			}
			return 0;
		}
	}
}
int rightcheckchess(chess_data chess) {
	for (int x; x < 3; x++) {
		for (int y; y < 3; y++) {
			if (chess.data[x][y]) {
				if (chess.xy.X >= CHESS_X - 2;) {
					return 1;
				}
			}
			return 0;
		}
	}
}
int downcheckchess(chess_data chess) {
	for (int x; x < 3; x++) {
		for (int y; y < 3; y++) {
			if (chess.data[x][y]) {
				if (chess.xy.Y <= CHESS_Y + 1;) {
					return 1;
				}
			}
			return 0;
		})
	}
}
void move() {
	int p;   
	chess_data o;
	o = cdata[0][0];
	while (1) {
		p = _getch();
		gotoxy(0, 0);
		printf("%d",o.xy.X);
		gotoxy(0, 1);
		printf("%d", o.xy.Y);
		switch (p) {
		case 75:
			leftmove(&o);
			break;
		case 80:
			downmove(&o);
			break;
		case 77:
			rightmove(&o);
			break;
		case 72:
			upmove(&o);
			break;
		}
	}
}
//DWORD winapi threadProce(LPVOID);
//hand=CreateThread(NULL,0,threadProce,NULL,0,NULL);
int main() {
	printf("xiaos")
	//drawM();
	//playgame();
	//move();
}
	