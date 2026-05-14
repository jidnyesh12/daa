#include<bits/stdc++.h>
using namespace std;



int solve(int x, int y){
    if(x<10 || y<10) {
        return x*y;
    }

    int m = max(to_string(x).size(), to_string(y).size()) / 2;
    int power = pow(10, m);
    
    int A = x / power;
    int B = x % power;
    
    int C = y / power;
    int D = y % power;

    int p1 = solve(A, C);
    int p2 = solve(B, D);
    int p3 = solve(A + B, C + D);

    int res = p1 * pow(10, 2*m) + (p3 - p1 - p2) * power + p2;

    return res;
}

int main(){
    int x = 1234;
    int y = 5678;

    cout <<  solve(x, y);
}