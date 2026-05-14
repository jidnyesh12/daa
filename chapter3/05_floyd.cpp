#include<bits/stdc++.h>
using namespace std;

int INF = 1e9;

void solve(vector<vector<int>>& graph){
    int n = graph.size();

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if( graph[i][k]!=INF && graph[k][j]!=INF)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int main(){
    vector<vector<int>> graph = {
        {0,   3,  INF, 7},
        {8,   0,   2,   INF},
        {5,   INF, 0,   1},
        {2,   INF, INF, 0}
    };

    solve(graph);
}