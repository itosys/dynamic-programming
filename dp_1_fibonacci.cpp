#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, a, b) for (int i = a; i < b; i++)

ll n;
ll memo[1000];

int fib(ll n) {
    if (n <= 2) return 1;
    if (memo[n] != 0) return memo[n];
    else {
        memo[n] = fib(n - 1) + fib(n - 2);
        return memo[n];
    }
}

int main() {
    memo[1] = 1;
    memo[2] = 1;
    cin >> n;
    cout << fib(n) << endl;
}
