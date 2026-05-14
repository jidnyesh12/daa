#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& coins, int amt){

    int ans = 0;
    int rem = amt;
    sort(coins.begin(), coins.end(), greater<int>());
    
    for(int val: coins){
        while(rem>=val){
            rem -= val;
            ans++;
        }
    }

    return ans;

}

int main(){
    vector<int> coins = {10, 20, 50, 100, 500};
    cout << solve(coins, 490);
}