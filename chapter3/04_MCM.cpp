#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>& s, int i, int j){
    if(i==j){
        cout << "M" << i;
        return;
    }
    cout << "(";
    print(s, i, s[i][j]);
    print(s, s[i][j]+1, j);
    cout << ")";
}   

int main(){

    vector<int> p = {10, 20, 30, 40, 30};

    int n = p.size() - 1;

    vector<vector<int>> m(n+1, vector<int>(n+1, 0));
    vector<vector<int>> r(n+1, vector<int>(n+1, 0));

    for(int l=2;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){
            int j=i+l-1;
            m[i][j] = 1e9;
            for(int k=i;k<=j-1;k++){
                int c = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(c<m[i][j]){
                    m[i][j] = c;
                    r[i][j] = k;
                }
            }

        }
    }
      
}