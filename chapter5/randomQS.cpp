#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high){
    int random = low + rand()%(high-low);
    swap(arr[low], arr[random]);

    int pivot = arr[low];
    int i = low, j = high;
    do{
        do {
            i++;
        }while(pivot>=arr[i]);

        do{
            j--;
        }while(pivot<arr[j]);

        if(i<j){
            swap(arr[i], arr[j]);
        }
    }while(i<j);

    swap(arr[low], arr[j]);

    return j;
}

void quickSort(vector<int>& arr, int low, int high){
    if(low<high){
        int id = partition(arr, low, high);
        quickSort(arr, low, id);
        quickSort(arr, id+1, high);
    }
}

int main(){
    vector<int> arr = {50, 70, 60, 90, 40, 80, 10, INT_MAX};
    quickSort(arr, 0, arr.size()-1);
    for(int x: arr){
        cout << x << " ";
    }
}