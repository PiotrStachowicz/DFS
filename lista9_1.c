#include <stdio.h>
#include <stdbool.h>
#define MAX_HEIGHT 100
#define MAX_WIDTH 100
#define MAX_K 100
int tab[MAX_HEIGHT][MAX_WIDTH];
bool visited[MAX_HEIGHT][MAX_WIDTH][MAX_K][5];
unsigned int w,h,k;
int start_x, start_y;
int koniec_x, koniec_y;
bool dfs(int x, int y, int pozostale_zmiany_kierunku, int kierunek) {
    if (x == koniec_x && y == koniec_y) return true;
    if (visited[x][y][pozostale_zmiany_kierunku][kierunek] || tab[x][y] == '#') return false;
    visited[x][y][pozostale_zmiany_kierunku][kierunek] = true;
    if (x > 0&& pozostale_zmiany_kierunku >= 0 && dfs(x - 1, y, kierunek == 4 ? pozostale_zmiany_kierunku : pozostale_zmiany_kierunku - 1, 4)) return true;
    if (x < w-1 && pozostale_zmiany_kierunku >= 0 && dfs(x + 1, y, kierunek == 2 ? pozostale_zmiany_kierunku : pozostale_zmiany_kierunku - 1, 2)) return true;
    if (y > 0 && pozostale_zmiany_kierunku >= 0 && dfs(x, y - 1, kierunek == 1 ? pozostale_zmiany_kierunku : pozostale_zmiany_kierunku - 1, 1)) return true;
    if (y < h-1 && pozostale_zmiany_kierunku >= 0 && dfs(x, y + 1, kierunek == 3 ? pozostale_zmiany_kierunku : pozostale_zmiany_kierunku - 1, 3)) return true;
    return false;
}
int main(void){
    if (scanf("%u %u %u", &w, &h, &k) != 3 || w > MAX_WIDTH || h > MAX_HEIGHT || k>MAX_K) return 1;
    for (unsigned int y = 0; y < h; y++){
        for (unsigned int x = 0; x < w; x++) {
            char c;
            if (scanf(" %c",&c) != 1) return 1;
            switch (c) {
                case '.': tab[x][y] = c; break;
                case '#': tab[x][y] = c; break;
                case 'A': tab[x][y] = c; start_y = y; start_x = x; break;
                case 'B': tab[x][y] = c; koniec_y = y; koniec_x = x; break;
            }
        }
    }
    bool result = dfs(start_x,start_y,k,0); // 1-góra 2-prawo 3-dół 4-lewo
    if(result==true){
        printf("TAK");
    } else{
        printf("NIE");
    }
    return 0;
}