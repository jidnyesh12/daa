#include<bits/stdc++.h>
using namespace std;

int totalCities = 4;
vector<vector<int>> costMat = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int final_cost = INT_MAX;
vector<int> best_path;

void solve(vector<int>& curr_path, vector<bool> &visited, int curr_cost, int level){
    if(level==totalCities){
        if(costMat[curr_path[level-1]][0]!=0){
            int total = curr_cost + costMat[curr_path[level-1]][0];
            if(total<final_cost){
                final_cost = total;
                best_path =  curr_path;
            }
        }
        return;
    }
    for(int city=0;city<totalCities;city++){
        if(!visited[city] && costMat[curr_path[level - 1]][city] != 0){
            int newcost = curr_cost + costMat[curr_path[level - 1]][city];
            if(newcost<final_cost){
                curr_path[level] = city;
                visited[city] = true;
                solve(curr_path, visited, newcost, level+1);
                visited[city] = false; 
            }
        }
    }
}

int main(){

    vector<int> curr_path(totalCities);
    vector<bool> visited(totalCities, false);

    curr_path[0] = 0;
    visited[0] = true;
    solve(curr_path, visited, 0, 1);
    cout << "\nOptimal Path: ";
    for(int i = 0; i < totalCities; i++) {
        cout << best_path[i] << " -> ";
    }
    cout << best_path[0];

    cout << "\nMinimum Cost: " << final_cost << endl;

}