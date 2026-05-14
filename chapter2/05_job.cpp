#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<pair<int, pair<int,int>>>& jobs){

    int n = jobs.size();
    int max_dead = INT_MIN;
    for(auto i: jobs){
        max_dead = max(max_dead, i.second.first);
    }

    vector<int> ans(max_dead, -1);
    vector<bool> flag(max_dead, false);

    sort(jobs.begin(), jobs.end(), [&](const pair<int, pair<int,int>>&a, const pair<int, pair<int,int>>&b){
        return a.second.second > b.second.second;
    });

    for(auto i: jobs){
        int id = i.first;
        int deadline = i.second.first;
        for(int j=deadline-1;j>=0;j--){
            if(!flag[j]){
                ans[j] = id;
                flag[j] = true;
                break;
            }
        }
    }

    return ans;

}

int main(){
    vector<pair<int, pair<int,int>>> jobs = {
        {1, {2, 100}},
        {2, {1, 19}},
        {3, {2, 27}},
        {4, {1, 25}},
        {5, {3, 15}}
    };

    vector<int> ans = solve(jobs);
    for(int x: ans){
        cout << x << " ";
    }

}