#include<bits/stdc++.h>
using namespace std;

bool validate(string text, string pattern, int index){
    int i = 0;
    for(int j=index;j<text.size() && i<pattern.size(); i++,j++){
        if(text[j]!=pattern[i]) return false;
    }
    return true;
}

vector<int> solve(string text, string pattern){
    if(pattern.size()>text.size()) return {};
    vector<int> ans;
    int n = pattern.size();
    int val = 0, power = pow(10, n-1);
    for(int i=0;i<n;i++){
        int v = pattern[i] - 'A' + 1;
        val = val*10 + v;
    }
    int curr = 0;
    for(int i=0;i<pattern.size();i++){
        int v = text[i] - 'A' + 1;
        curr = curr*10 + v;
    }
    if(curr == val && validate(text, pattern, 0)){
        ans.push_back(0);
    }
    int i = 0;
    for(int j = n;j<text.size(); j++){
        curr -= (text[i] - 'A' + 1) * power;
        curr = curr*10;
        curr += text[j] - 'A' + 1;
        i++;
        if(curr == val && validate(text, pattern, i)){
            ans.push_back(i);
        }
    }
    return ans;
}

int main(){
    string text = "ABCDABCDAB";
    string pattern = "DAB";

    vector<int> ans = solve(text, pattern);

    for(int x: ans){
        cout << x << " ";
    }
}