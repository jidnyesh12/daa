#include<bits/stdc++.h>
using namespace std;

int median(vector<int>& temp){
    sort(temp.begin(), temp.end());
    return temp[temp.size()/2];
}

int findMoM(vector<int>& arr, int low, int high){
    int n = high - low + 1;
    
    if(n<=5){
        vector<int> temp;
        for(int i=low;i<=high;i++){
            temp.push_back(arr[i]);
        }
        return median(temp);
    }

    vector<int> medians;
    for(int i=low;i<=high;i+=5){
        vector<int> temp;
        for(int j=i;j < min(i+5, high+1); j++){
            temp.push_back(arr[j]);
        }
        medians.push_back(median(temp));
    }   
    return findMoM(medians, 0, medians.size() - 1);
}

int partition(vector<int>& arr, int low,int high, int val){
    for(int i=low;i<=high;i++){
        if(arr[i]==val){
            swap(arr[i], arr[low]);
            break;
        }
    }

    int i = low+1, j = high, pivot = arr[low];
    
    while(true){
        while(i <= high && arr[i] <= pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i >= j)
            break;
        swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;

}

void QS(vector<int>& arr, int low, int high){
    if(low>=high) return;
    int pivot = findMoM(arr, low, high);
    int part = partition(arr, low, high, pivot);
    QS(arr, low, part-1);
    QS(arr, part+1, high);
}

int main(){
    vector<int> arr = {9, 4, 7, 2, 1, 8, 5, 3, 6};
    QS(arr, 0, arr.size() - 1);
    for(int x : arr)
        cout << x << " ";
}