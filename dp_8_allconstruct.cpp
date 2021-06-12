#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i > b; i--)

unordered_map<string, vector<vector<string>>> memo;

vector<vector<string>> all_construct(string target, vector<string> words) {
    if (memo.find(target) != memo.end()) return memo[target];
    if (target == "") return vector<vector<string>>{{}};
    vector<vector<string>> result;
    for (string w : words) {
        if (target.find(w) == 0) {
            string remainder = target.substr(w.size(), target.size() - w.size());
            vector<vector<string>> combs = all_construct(remainder, words);
            for (vector<string> comb : combs) {
                comb.push_back(w);
                result.push_back(comb);
            }
        }
    }
    return memo[target] = result;
}

int main() {
    vector<vector<string>> combs = all_construct("purple", {"purp", "p", "ur", "le", "purpl"});
    for (vector<string> comb : combs) {
        rrep(i, comb.size() - 1, -1) cout << comb[i] << ' ';
        cout << endl;
    }
}
