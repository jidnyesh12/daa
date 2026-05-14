#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int n = graph.size();

int VISITED_ALL = (1<<n) - 1;

vector<vector<int>> dp((1<<n), vector<int>(n, -1));
vector<vector<int>> parent((1<<n), vector<int>(n, -1));

int tsp(int mask, int pos){
    if(mask==VISITED_ALL){
        return graph[pos][0];
    }
    if(dp[mask][pos]!=-1) return dp[mask][pos];
    int ans = INT_MAX;
    for(int city=0;city<n;city++){
        if((mask&(1<<city))==0){
            int newans = graph[pos][city] + tsp(mask | (1<<city), city);
            if(newans<ans){
                ans = newans;
                parent[mask][pos] = city;
            }
        }
    }

    return dp[mask][pos] = ans;
}

void trace(){
    int mask = 1, pos = 0;
    while(true){
        cout << pos << " ";
        int next = parent[mask][pos];
        if(next==-1) break;
        mask = mask | (1<<next);
        pos = next;
    }
}

int main(){
    cout << tsp(1, 0);
    trace();
}