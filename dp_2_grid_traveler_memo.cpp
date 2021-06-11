#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, a, b) for (int i = a; i < b; i++)

vector<vector<ll> > memo(1000, vector<ll>(1000, -1));

int grid_traveler(int n, int m) {
    if (n == 0 || m == 0) return 0;
    if (memo[n][m] != -1) return memo[n][m];
    return memo[n][m] = grid_traveler(n - 1, m) + grid_traveler(n, m - 1);
}

int main() {
    int n, m;
    cin >> n >> m;
    memo[1][1] = 1;
    cout << grid_traveler(n, m) << endl;
}
