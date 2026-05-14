#include<bits/stdc++.h>
using namespace std;

int LS(vector<int>& arr, int target){
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]==target) return i;
    }
    return -1;
}

int BS(vector<int>& arr, int target, int low, int high){
    
    if(low>high) return -1;
    int mid = low + (high-low)/2;

    if(arr[mid]==target) return mid;

    if(arr[mid] < target) return BS(arr, target, mid+1, high);
    return BS(arr, target, low, mid-1);
}

int main(){


    vector<int> arr = {50, 70, 60, 90, 40, 80, 10, INT_MAX};
    cout << LS(arr, 50) << endl;
    sort(arr.begin(), arr.end());
    cout << BS(arr, 50, 0, arr.size()-1);
}