#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, a, b) for (int i = a; i < b; i++)

int memo[10000];

bool cansum(int target, vector<int> &a) {
    if (target == 0) return true;
    if (target < 0) return false;
    if (memo[target] == 1) return true;
    if (memo[target] == -1) return false;
    rep(i, 0, a.size()) {
        int remainder = target - a[i];
        if (cansum(remainder, a)) {
            memo[target] = 1;
            return true;
        } else
            memo[target] = -1;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i, 0, m) cin >> a[i];

    if (cansum(n, a))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
