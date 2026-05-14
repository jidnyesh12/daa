#include<bits/stdc++.h>
using namespace std;

double solve(vector<int>& profit, vector<int>& weight, int x){

    vector<pair<double, pair<int,int>>> vec;

    int n = profit.size();
    for(int i=0;i<n;i++){
        double c = (profit[i]*1.0)/weight[i];
        vec.push_back({c, {profit[i], weight[i]}});
    }

    sort(vec.begin(), vec.end(), greater<pair<double, pair<int,int>>>());
    
    double ans = 0;

    for(int i=0;i<n;i++){

        double val = vec[i].first;
        int profit = vec[i].second.first;
        int weight = vec[i].second.second;

        if(x>=weight){
            ans += profit;
            x -= weight;
        }else{
            ans += (val*x);
            break;
        }

    }

    return ans;
}

int main(){
    vector<int> profit = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int capacity = 50;
    cout << solve(profit, weight, capacity);
}