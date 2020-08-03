#include<bits/stdc++.h>
using namespace std;

int A[5][5];
bool visited[5][5];

int dx[] = {-1, 1,  0, 0, -1, -1,  1, 1};
int dy[] = {0,  0, -1, 1, -1,  1, -1, 1};

bool valid(int x, int y){
    return (x >= 0 && x < 5 && y >= 0 && y < 5 && !visited[x][y]);
}

void dfs(int x, int y){
    // visit the cell
//    if (visited[x][y]) return;
    visited[x][y] = 1;
//    if (!(x == 2 && y == 2)) return;

    for (int i = 0; i < 8; i++){
       int next_x = x + dx[i];
       int next_y = y + dy[i];

        if (valid(next_x, next_y)){
            dfs(next_x, next_y);
        }
   }
}

struct node{
    int x;
    int y;
};

void bfs(int sx, int sy){
    queue < node > Q;
    Q.push({sx, sy});
    visited[sx][sy] = 1;

    while(!Q.empty()){
        int x = Q.front().x;
        int y = Q.front().y;
        Q.pop();

        for (int i = 0; i < 8; i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            cout << next_x << " " << next_y << endl;

       }
    }
}


int main()
{
    dfs(2, 2);
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}











//    for (int i = 0; i < 8; i++){
//       int next_x = x + dx[i];
//       int next_y = y + dy[i];
//
//       dfs(next_x, next_y);
//   }

//int dx[] = {-1, 1,  0, 0, -1, -1,  1, 1};
//int dy[] = {0,  0, -1, 1, -1,  1, -1, 1};
