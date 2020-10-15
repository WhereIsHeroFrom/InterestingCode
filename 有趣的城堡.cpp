#include <iostream>

using namespace std;

// charBlock 横向长度
const int CHAR_MAX_LR = 11;
// charBlock 纵向高度
const int CHAR_MAX_TB = 6;

// charBlock - Left -> Right 字符数
const int CHAR_MAX_LR_RECT = 9;
// charBlock - Top -> Bottom 字符数
const int CHAR_MAX_TB_RECT = 4;
// charBlock - Front -> Back 字符数
const int CHAR_MAX_FB_RECT = 3;

// charBlock 每一行的起始有效（非空格）字符的位置 （0-based）
const int CHAR_START[CHAR_MAX_TB] = { 2, 1, 0, 0, 0, 0 };
// charBlock 每一行的有效字符长度
const int CHAR_LEN[CHAR_MAX_TB] = { CHAR_MAX_LR, CHAR_MAX_LR, CHAR_MAX_LR, CHAR_MAX_LR, CHAR_MAX_LR - 1, CHAR_MAX_LR - 2 };
// 整个 Block 的宽高
const int MAX_MAP = 500;


char charBlock[][CHAR_MAX_LR + 1] = {
    "  +-------+", 
    " /       /|", 
    "+-------+ |", 
    "|       | +", 
    "|       |/",
    "+-------+"
};

char retMap[MAX_MAP][MAX_MAP];
short H[100][100];

void fill(int x, int y) {
	for (int i = 0; i < CHAR_MAX_TB; i++) {
		for (int j = CHAR_START[i]; j < CHAR_LEN[i]; j++) {
			retMap[x + i][y + j] = charBlock[i][j];
		}
    }
}

#include <windows.h>

int main()
{
	printf("%u\n", GetTickCount());
    int w, h, i, j, k;
	int n, m;
	int nowh;
    while(scanf("%d %d", &n, &m) != EOF) {
		w = (CHAR_MAX_LR_RECT - 1) * m + 1 + (CHAR_MAX_FB_RECT - 1) * n;
		h = 0;

        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
				int v;
                scanf("%d", &v);
				H[i][j] = v;

				if (!v) continue;
				nowh = (CHAR_MAX_FB_RECT - 1) * (n - i - 1) + (CHAR_MAX_TB_RECT - 1) * (v + 1);

				if (nowh > h) {
					h = nowh;
                }
            }
        }

		memset(retMap, '\0', sizeof(retMap));
        for(i = 0; i < h; i++) {
            for(j = 0; j < w; j++)
				retMap[i][j] = '*';
        }

        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                for(k = 0; k < H[i][j]; k++) {
					fill(
						h + 4 - (CHAR_MAX_LR_RECT + (CHAR_MAX_TB_RECT - 1) * k + (CHAR_MAX_FB_RECT - 1) * (n - i - 1) + 1), 
						(CHAR_MAX_FB_RECT - 1) * (n - i - 1) + j * (CHAR_MAX_LR_RECT - 1)
					);
                }
            }
        }

        for(i = 0; i < h; i++)
			puts(retMap[i]);
    }
    return 0;
}


/*
6 7
16 15 14 13 12 11 11
16 15 14 13 12 11 11 
15 6  7  8  9 10 10
14 6  7  8  9 10 10
13 6  5  4  3  2  1
12 6  5  4  3  2  1
*/