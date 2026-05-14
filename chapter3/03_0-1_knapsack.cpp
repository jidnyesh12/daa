#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& profit, vector<int>& weight, int capacity){

    int n = profit.size();
    vector<vector<int>> dp(n+1, vector<int>(capacity+1, 0));

    for(int i = 1; i<=n; i++){
        for(int w=0;w<=capacity; w++){
            dp[i][w] = dp[i-1][w];
            if(w-weight[i-1]>=0)
                dp[i][w] = max(dp[i][w], profit[i-1] + dp[i-1][w-weight[i-1]]);
        }
    }

    int w = capacity;
    for(int i=n;i>0;i--){
        if(dp[i][w]!=dp[i-1][w]){
            w-=weight[i-1];
        }
    }
}

int main(){
    vector<int> profit = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int capacity = 50;
    solve(profit, weight, capacity);
}