#include<iostream>

using namespace std;
struct Point {
    int y;
    int x;
};
int n;
int A[500][500];
int tmp[500][500];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int xdx[4][10] = {{1,  1,  0,  0, 0,  0, -1, -1, -2, -1},
                  {-1, 1,  -1, 1, -1, 1, -2, 2,  0,  0},
                  {-1, -1, 0,  0, 1,  1, 0,  0,  2,  1},
                  {-1, 1,  -1, 1, -1, 1, -2, 2,  0,  0}};
int ydy[4][10] = {{-1, 1,  -1, 1, -1, 1,  -2, 2, 0, 0},
                  {-1, -1, 0,  0, 1,  1,  0,  0, 2, 1},
                  {-1, 1,  -1, 1, -1, 1,  -2, 2, 0, 0},
                  {1,  1,  0,  0, -1, -1, 0,  0, 2, 1}};
int val[] = {1, 1, 7, 7, 10, 10, 2, 2, 5};

int result;

int main() {
    cin >> n;
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            cin >> A[y][x];
        }
    }
    int go_cnt = 1;
    int dir = 0;
    bool flag = false;
    Point cur = {n / 2 + 1, n / 2 + 1};
    while (1) {
        for (int i = 0; i < go_cnt; i++) {
            cur.x += dx[dir];
            cur.y += dy[dir];
            if (A[cur.y][cur.x]) {
                int sum = 0;
                for (int j = 0; j < 9; j++) {// 확률 대로 뿌릴거
                    int ny = cur.y + ydy[dir][j];
                    int nx = cur.x + xdx[dir][j];
                    if (ny > n || ny < 1 || nx > n || nx < 1) {//만약 범위 넘어가면
                        result += (A[cur.y][cur.x] * val[j] / 100);
                        sum += (A[cur.y][cur.x] * val[j] / 100);
                    } else {// 범위 안넘어가면
                        sum += (A[cur.y][cur.x] * val[j] / 100);
                        A[ny][nx] = A[cur.y][cur.x] * val[j] / 100;
                    }
                }
                

            }
            if (cur.x == 1 && cur.y == 1) {
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    cout << result;

}
