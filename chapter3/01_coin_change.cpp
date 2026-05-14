#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& coins, int amount, vector<int>& dp){
    dp[0] = 0;
    for(int i=1;i<=amount;i++){
        for(int coin: coins){
            if(i>=coin) dp[i] = min(dp[i], 1 + dp[i-coin]);
        }
    }
}

int main(){
    
    vector<int> coins = {1, 2, 5, 10, 20, 50};
    int amount = 93;

    vector<int> dp(amount+1, 1e9);
    
    solve(coins, amount, dp);
    cout << dp[amount] << endl;
}