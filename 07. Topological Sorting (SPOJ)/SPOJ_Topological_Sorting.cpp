#include<bits/stdc++.h>
using namespace std;

#define MX 10005
vector < int > graph[MX];
int color[MX];

#define WHITE 0
#define GRAY 1
#define BLACK 2

bool cycle;
vector < int > result;

// 1-> 2 4 3, 2 3 4

void dfs(int node){

    color[node] = GRAY;
    sort(graph[node].begin(), graph[node].end());

    for (int i = graph[node].size() - 1; i >= 0; i--){
        int next = graph[node][i];
        if (color[next] == WHITE){
            dfs(next);
        }
        else if (color[next] == GRAY){
            cycle = true;
            return ;
        }
    }

    color[node] = BLACK;
    result.push_back(node);
}

int main()
{
    cycle = false;
    int nodes, edges;
    scanf("%d%d", &nodes, &edges);
    for (int i = 1; i <= edges; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
    }

    for (int i = nodes; i >= 1; i--){
        if (color[i] == WHITE)
            dfs(i);
    }

    if (cycle == true){
        printf("Sandro fails.\n");
    }
    else{
        for (int i = result.size() - 1; i >= 0; i--){
            if (i == 0){
                printf("%d\n", result[i]);
            }
            else{
                printf("%d ", result[i]);
            }
        }
    }
    return 0;
}
