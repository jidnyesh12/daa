#include <bits/stdc++.h>
using namespace std;

int n = 6;
int target = 9;

vector<int> arr = {3, 34, 4, 12, 5, 2};

bool found = false;

void solve(int index, int curr_sum, int rem_sum, vector<int>& path) {

    // success condition
    if (curr_sum == target) {
        found = true;
        cout << "Subset found: ";
        for (int x : path)
            cout << x << " ";
        cout << "\n";
        return;
    }

    // bounding conditions
    if (index == n || curr_sum > target || curr_sum + rem_sum < target)
        return;

    // ---- INCLUDE ----
    path.push_back(arr[index]);
    solve(index + 1,
          curr_sum + arr[index],
          rem_sum - arr[index],
          path);

    path.pop_back();

    // ---- EXCLUDE ----
    solve(index + 1,
          curr_sum,
          rem_sum - arr[index],
          path);
}

int main() {

    vector<int> path;
    int total_sum = accumulate(arr.begin(), arr.end(), 0);

    solve(0, 0, total_sum, path);

    if (!found)
        cout << "No subset found\n";

    return 0;
}
