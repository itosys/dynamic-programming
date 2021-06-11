#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, a, b) for (int i = a; i < b; i++)

vector<int> v;
int memo[10000];

bool howsum(int target, vector<int> numbers) {
    if (target == 0) return true;
    if (target < 0) return false;
    if (memo[target] == 1) return true;
    if (memo[target] == -1) return false;
    for(int num : numbers) {
        int remainder = target - num;
        if (howsum(remainder, numbers)) {
            v.push_back(num);
            memo[target] = 1;
            return true;
        } else
            memo[target] = -1;
    }
    return false;
}

int main() {
    if (howsum(7, {2, 3, 5})) {
        cout << "Yes" << endl;
        rep(i, 0, v.size()) cout << v[i] << ' ';
        cout << endl;
    } else
        cout << "No" << endl;
}
