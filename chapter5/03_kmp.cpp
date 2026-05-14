#include<bits/stdc++.h>
using namespace std;

vector<int> findLPS(string pattern){
    int sz = pattern.size();
    vector<int> LPS(sz, 0);

    int i = 0, j = 1;
    while(j<sz){
        if(pattern[i]==pattern[j]){
            LPS[j] = i+1;
            i++;
            j++;
        }else if(i==0){
            LPS[j] = 0;
            j++;
        }else{
            i = LPS[i-1];
        }
    }
    return LPS;
}

vector<int> solve(string text, string pattern){

    vector<int> LPS(1, -1); 
    vector<int> tmp = findLPS(pattern);
    for(int x: tmp) LPS.push_back(x);

    vector<int> ans;

    int i = 0, j = 0;
    
    while(i<text.size()){
        if(pattern[j]==text[i]) {
            i++;
            j++;
        }else if(j==0){
            i++;
        }else{
            j = LPS[j];
        }

        if(j==pattern.size()) {ans.push_back(i-pattern.size()); j = LPS[j];}
    }

    return ans;
    
}

int main(){
    string text = "ABCDABCDABAJDSKNJDABSJKNDSDJ";
    string pattern = "DAB";


    vector<int> ans = solve(text, pattern);

    for(int x: ans){
        cout << x << " ";
    }
}