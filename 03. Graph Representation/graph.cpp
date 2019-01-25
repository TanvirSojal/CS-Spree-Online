#include<bits/stdc++.h>
using namespace std;

vector <int> graph[5];

void printGraph(vector<int>graph[], int n){
    cout << "The graph is:" << endl;
    for (int i = 0; i < n; i++){
        cout << i << " -> ";
        for (int j = 0; j < graph[i].size(); j++){
            cout << graph[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    printGraph(graph, 5);
    return 0;
}
