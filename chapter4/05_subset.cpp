#include <bits/stdc++.h>
using namespace std;

int n = 6;
int target = 9;

vector<int> arr = {3, 34, 4, 12, 5, 2};

bool found = false;

void solve(vector<int>& curr_set, vector<bool>& visited, int curr_sum, int level, int rem_sum) {

    if (curr_sum == target) {
        found = true;
        cout << "Subset found: ";
        for (int i = 0; i < level; i++) {
            if (visited[i]) cout << curr_set[i] << " ";
        }
        cout << "\n";
        return;
    }

    if (level == n || curr_sum > target || curr_sum + rem_sum < target)
        return;

    // include current element
    visited[level] = true;
    curr_set[level] = arr[level];

    solve(curr_set, visited, curr_sum + arr[level], level + 1, rem_sum - arr[level]);

    // exclude current element
    visited[level] = false;

    solve(curr_set, visited, curr_sum, level + 1, rem_sum - arr[level]);
}

int main() {

    vector<int> curr_set(n);
    vector<bool> visited(n, false);

    int total_sum = accumulate(arr.begin(), arr.end(), 0);

    solve(curr_set, visited, 0, 0, total_sum);

    if (!found)
        cout << "No subset found\n";

    return 0;
}