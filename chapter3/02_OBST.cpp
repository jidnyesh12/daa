#include<bits/stdc++.h>
using namespace std;

#define double long double

int main(){

    int n = 3;

    // Successful search probabilities
    vector<double> p = {0, 0.50, 0.10, 0.05};

    // Unsuccessful search probabilities
    vector<double> q = {0.15, 0.10, 0.05, 0.05};

    vector<vector<double>> w(n + 1, vector<double>(n + 1, 0));
    vector<vector<double>> c(n + 1, vector<double>(n + 1, 0));

    vector<vector<int>> r(n + 1, vector<int>(n + 1, 0));

    for(int i=0;i<=n;i++){
        w[i][i] = q[i];
        c[i][i] = 0;
        r[i][i] = 0;
    }

    for(int len = 1; len<= n; len++){

        for(int i = 0; i <= n-len; i++){

            int j = i + len;

            w[i][j] = w[i][j-1] + p[j] + q[j];
            c[i][j] = 1e18;

            for(int k=i+1;k<=j;k++){
                double cost = c[i][k-1] + c[k][j] + w[i][j];
                if(cost<c[i][j]){
                    c[i][j] = cost;
                    r[i][j] = k;
                }
            }

        }

    }

    cout << fixed << setprecision(2);

    cout << "Weight Matrix W:\n\n";

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(j < i)
                cout << "0\t";
            else
                cout << w[i][j] << "\t";
        }
        cout << "\n";
    }

    cout << "\nCost Matrix C:\n\n";

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(j < i)
                cout << "0\t";
            else
                cout << c[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\nRoot Matrix R:\n\n";

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(j < i)
                cout << "0\t";
            else
                cout << r[i][j] << "\t";
        }
        cout << "\n";
    }
}