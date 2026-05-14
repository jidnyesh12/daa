#include<bits/stdc++.h>
using namespace std;

struct Item{
    int weight;
    int profit;
    double ratio;
};

struct Node{
    int level;
    int profit;
    int weight;
    double bound;
};

bool cmp(Item a, Item b){
    return a.ratio > b.ratio;
}

// Upper bound using fractional knapsack
double bound(Node u, int n, int capacity, vector<Item>& items){

    if(u.weight >= capacity)
        return 0;

    double profitBound = u.profit;
    int totalWeight = u.weight;
    int j = u.level + 1;

    // take full items
    while(j < n && totalWeight + items[j].weight <= capacity){
        totalWeight += items[j].weight;
        profitBound += items[j].profit;
        j++;
    }

    // take fraction
    if(j < n){
        profitBound += (capacity - totalWeight) * items[j].ratio;
    }

    return profitBound;
}


int knapsack(int capacity, vector<int>& profit, vector<int>& weight){

    int n = profit.size();
    vector<Item> items(n);
    for(int i = 0; i < n; i++){
        items[i].profit = profit[i];
        items[i].weight = weight[i];
        items[i].ratio = profit[i] * 1.0 / weight[i];
    }

    sort(items.begin(), items.end(), cmp);
    queue<Node> q;
    Node u, v;
    v.level = -1;
    v.profit = 0;
    v.weight = 0;
    v.bound = bound(v, n, capacity, items);

    q.push(v);

    int maxProfit = 0;

    while(!q.empty()){
        v = q.front();
        q.pop();

        // prune
        if(v.bound <= maxProfit)
            continue;

        u.level = v.level + 1;
        if(u.level >= n)
            continue;

        // INCLUDE item
        u.weight = v.weight + items[u.level].weight;
        u.profit = v.profit + items[u.level].profit;
        if(u.weight <= capacity && u.profit > maxProfit){
            maxProfit = u.profit;
        }

        u.bound = bound(u, n, capacity, items);
        if(u.bound > maxProfit)
            q.push(u);

        // EXCLUDE item
        u.weight = v.weight;
        u.profit = v.profit;
        u.bound =bound(u, n, capacity, items);
        if(u.bound > maxProfit)
            q.push(u);
    }

    return maxProfit;
}


int main(){

    vector<int> profit = {60, 100, 120};

    vector<int> weight = {10, 20, 30};

    int capacity = 50;

    cout << "Maximum Profit = "<< knapsack(capacity,profit, weight);
}