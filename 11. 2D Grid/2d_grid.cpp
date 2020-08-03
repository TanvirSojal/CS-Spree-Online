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
    if (visited[x][y]) return; // this line is not necessary anymore since we are checking validity before calling the function
    visited[x][y] = 1;

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

            if (valid(next_x, next_y)){
                visited[next_x][next_y] = 1;
                Q.push({next_x, next_y});
            }
       }
    }
}


int main()
{
    bfs(2, 2);
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
