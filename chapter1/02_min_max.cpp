#include<bits/stdc++.h>
using namespace std;

pair<int,int> solve(vector<int> arr, int low, int high){
    // if(low>high) return {INT_MAX, INT_MIN};
    if(low==high){
        return {arr[low], arr[low]};
    }
    if(low==high+1){
        return {min(arr[low], arr[high]), max(arr[low], arr[high])};
    }

    int mid = low + (high-low)/2;
    pair<int,int> left, right, res;
    left = solve(arr, low, mid);
    right = solve(arr, mid+1, high);
    res = {min(left.first, right.first), max(left.second, right.second)};
    return res;
}

int main(){

    vector<int> arr = {50, 70, 60, 90, 40, 80, 10};
    pair<int,int> pr = solve(arr, 0, arr.size()-1);
    cout << pr.first << " " << pr.second << endl;

}