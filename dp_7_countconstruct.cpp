#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

unordered_map<string, int> memo;

int count_construct(string target, vector<string> words) {
    if (memo.find(target) != memo.end()) return memo[target];
    int count = 0;
    if (target == "") return 1;
    for (string w : words) {
        if (target.find(w) == 0) {
            string remainder = target.substr(w.size(), target.size() - w.size());
            count += count_construct(remainder, words);
        }
    }
    return memo[target] = count;
}

int main() {
    cout << count_construct("purple", {"purp", "p", "ur", "le", "purpl"}) << endl;
    cout << count_construct("abcdef", {"abc", "p", "ur", "le", "def"}) << endl;
}
