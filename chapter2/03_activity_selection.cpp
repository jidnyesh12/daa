#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<pair<int, pair<int,int>>>& arr){
    sort(arr.begin(), arr.end(), [&](const pair<int, pair<int,int>>&a, const pair<int, pair<int,int>>&b){
        return a.second.second < b.second.second;
    });

    vector<int> ans;

    int curr = 0, i = 0, n = arr.size();
    while(i<n){
        if(curr<=arr[i].second.first){
            curr = arr[i].second.second;
            ans.push_back(arr[i].first);
        }
        i++;
    }
    return ans;
}

int main(){
    vector<pair<int, pair<int,int>>> activities = {
        {1, {1, 4}},
        {2, {3, 5}},
        {3, {0, 6}},
        {4, {5, 7}},
        {5, {8, 9}},
        {6, {5, 9}}
    };

    vector<int> ans = solve(activities);
    for(int x: ans){
        cout << x << " ";
    }

}