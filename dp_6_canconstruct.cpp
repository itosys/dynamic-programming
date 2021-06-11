#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

unordered_map<string, bool> memo;

bool can_construct(string target, vector<string> words) {
    if (memo.find(target) != memo.end()) return memo[target];
    if (target == "") return true;
    for (string w : words) {
        if (target.find(w) == 0) {
            string remainder = target.substr(w.size(), target.size() - w.size());
            if (can_construct(remainder, words)) return memo[target] = true;
        }
    }
    return memo[target] = false;
}

int main() {
    cout << can_construct("abcdef", {"ab", "abc", "cd", "ef", "abcd"}) << endl;
    cout << can_construct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}) << endl;
}
