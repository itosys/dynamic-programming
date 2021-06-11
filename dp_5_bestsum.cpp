#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, a, b) for (int i = a; i < b; i++)

unordered_map<int, vector<int>> memo;

vector<int> bestsum(int target, vector<int> numbers) {
    if (memo.find(target) != memo.end()) return memo[target];
    if (target == 0) return {};
    if (target < 0) return {-1};
    vector<int> shortest_comb = {-1};

    for (int num : numbers) {
        int remainder = target - num;
        vector<int> comb = bestsum(remainder, numbers);
        if (comb != vector<int>{-1}) {
            comb.push_back(num);
            if (shortest_comb == vector<int>{-1} || shortest_comb.size() > comb.size()) shortest_comb = comb;
        }
    }
    memo[target] = shortest_comb;
    return shortest_comb;
}

int main() {
    vector<int> res = bestsum(7, {2, 3, 5});
    if (res[0] != -1) {
        rep(i, 0, res.size()) cout << res[i] << ' ';
    } else cout << "No";
    cout << endl;
}
