#include<bits/stdc++.h>
using namespace std;

#define MX 100010

vector < int > graph[MX];
bool vis[MX];

void dfs(int node){
    vis[node] = 1;
    for (int i = 0; i < graph[node].size(); i++){
        int next = graph[node][i];
        if (vis[next]==0)
            dfs(next);
    }
}

int main()
{
    int n, t;
    scanf("%d%d", &n, &t);
    for (int i = 1; i < n; i++){
        int a;
        scanf("%d", &a);
        // i -> (i+a)
        graph[i].push_back(i+a);
    }

    dfs(1);

    if (vis[t] == 1){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }

    return 0;
}
