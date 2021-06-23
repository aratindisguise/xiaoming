#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<share.h>
#include<time.h>
#include<ctype.h>
#include<conio.h>
#include "chess.h"


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
void drawM() {
	int i;
	gotoxy(X, Y);
	for (i = 0; i < CHESS_HIGHT; i++) {
		gotoxy(X, Y + 1 + i);
		printf("©§");
	}
	for (i = 0; i < CHESS_HIGHT; i++) {
		gotoxy(X + CHESS_WIDTH, Y + 1 + i);
		printf("©§");

	}
	gotoxy(X, Y + CHESS_HIGHT);
	printf("©»");
	for (i = 0; i < CHESS_WIDTH-1; i++) {
		printf("©¥");
	}
	printf("©¿");
}
void InitChessData() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			cdata[i][j].xy.X = X;
			cdata[i][j].xy.Y = Y;

		}
	}
	cdata[0][0].data[2][1] = 1;
	cdata[0][0].data[2][2] = 1;
	cdata[0][0].data[1][2] = 1;
	cdata[0][0].data[1][1] = 1;
	cdata[0][1] = cdata[0][2] = cdata[0][3] = cdata[0][0];
	cdata[1][0].data[2][1] = 1;
	cdata[1][0].data[2][2] = 1;
	cdata[1][0].data[2][3] = 1;
	cdata[1][0].data[1][2] = 1;
	cdata[1][1].data[1][3] = 1;
	cdata[1][1].data[3][2] = 1;
	cdata[1][1].data[2][2] = 1;
	cdata[1][1].data[2][1] = 1;

	cdata[1][2].data[2][1] = 1;
	cdata[1][2].data[2][2] = 1;
	cdata[1][2].data[2][3] = 1;
	cdata[1][2].data[3][2] = 1;
	
	cdata[1][3].data[1][2] = 1;
	cdata[1][3].data[2][2] = 1;
	cdata[1][3].data[3][2] = 1;
	cdata[1][3].data[2][3] = 1;

	cdata[2][0].data[1][1] = 1;
	cdata[2][0].data[0][1] = 1;
	cdata[2][0].data[2][1] = 1;
	cdata[2][0].data[3][1] = 1;
	
	cdata[2][1].data[1][0] = 1;
	cdata[2][1].data[1][1] = 1;
	cdata[2][1].data[1][2] = 1;
	cdata[2][1].data[1][3] = 1;
	cdata[2][2] = cdata[2][0];
	cdata[2][3] = cdata[2][1];

	cdata[3][0].data[0][1] = 1;
	cdata[3][0].data[1][1] = 1;
	cdata[3][0].data[2][1] = 1;
	cdata[3][0].data[2][2] = 1;
	cdata[3][0].data[2][3] = 1;

	cdata[3][1].data[1][0] = 1;
	cdata[3][1].data[1][1] = 1;
	cdata[3][1].data[2][2] = 1;
	cdata[3][1].data[2][3] = 1;
	cdata[3][2] = cdata[3][0];
	cdata[3][3] = cdata[3][1];

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
void checkbase(chess_data chess) {
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			if (chess.data[x][y]) {
				if (chess.xy.Y >= Y + CHESS_HIGHT - 2) {
					gotoxy(chess.xy.X + x * 2, chess.xy.Y + y);
					printf("¡ö");
				}
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
}int leftcheckchess(chess_data chess) {
	for (int x=0; x < 3; x++) {
		for (int y=0; y < 3; y++) {
			if (chess.data[x][y]) {
				if (chess.xy.X <= X) {
					return 0;
				}
			}
		}
	}
	return 1;
}
int rightcheckchess(chess_data chess) {
	for (int x=0; x < 3; x++) {
		for (int y=0; y < 3; y++) {
			if (chess.data[x][y]) {
				if (chess.xy.X >= X +CHESS_WIDTH-6) {
					return 0;
				}
			}
		}
	}return 1;
}
int downcheckchess(chess_data chess) {
	for (int x=0; x < 3; x++) {
		for (int y=0; y < 3; y++) {
			if (chess.data[x][y]) {
				if (chess.xy.Y >= Y+CHESS_HIGHT-4) {
					return 0;
				}
			}
		}
	}return 1;
}
void downmove(chess_data* chess) {
	if (downcheckchess(*chess))
	{
		clearchess(*chess);
		chess->xy.Y += 1;
		showchess(*chess);
	}
}
void leftmove(chess_data *chess) {
	if (leftcheckchess(*chess)) {
		clearchess(*chess);
		chess->xy.X -= 2;
		showchess(*chess);
	}
}
void rightmove(chess_data *chess) {
	if (rightcheckchess(*chess)) {
		clearchess(*chess);
		chess->xy.X += 2;
		showchess(*chess);
	}
}

void upmove(chess_data* chess) {
	clearchess(*chess);
	chess->xy.Y -= 1;
	showchess(*chess);
}
void ratate(chess_data* chess) {
	clearchess(*chess);
	//chess->data[X][Y];
	showchess(*chess);
	
}
void playgame(void) {
	InitChessData();	

	
}
void move() {
	int p;   
	chess_data o;
	o = cdata[1][0];
	while (1) {
		p = _getch();
		gotoxy(0, 0);
		printf("%d",o.xy.X);
		gotoxy(0, 1);
		printf("%d", o.xy.Y);
		//gotoxy(0, 3);
		//printf("%d", p);
		switch (p) {
		case 75:
			leftmove(&o);
			break;
		case 80:
			downmove(&o);
			checkbase(o);
			break;
		case 77:
			rightmove(&o);
			break;
		case 72:
			upmove(&o);
			break;
		case 32:
			ratate(&o);
			break;
		}
	}
}



int main() {
	drawM();
	playgame();
	move();
}
	