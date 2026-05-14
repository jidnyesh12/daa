#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high){

    vector<int> temp;
    int i = low, j = mid+1;

    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
        }else{
            temp.push_back(arr[j++]);
        }
    }

    while(i<=mid) 
        temp.push_back(arr[i++]);
    while(j<=high) 
        temp.push_back(arr[j++]);   
    
    for(int i=low;i<=high;i++){
        arr[i] = temp[i-low];
    }

}

void MS(vector<int>& arr, int low, int high){
    if(low>=high) return;
    int mid = low + (high-low)/2;
    MS(arr, low, mid);
    MS(arr, mid+1, high);
    merge(arr, low, mid, high);
}

int main(){
    vector<int> arr = {9, 4, 7, 2, 1, 8, 5, 3, 6};
    MS(arr, 0, arr.size() - 1);
    for(int x : arr)
        cout << x << " ";
}