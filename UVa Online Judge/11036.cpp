#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long evaluate(vector<string> &postfix, long long x, long long mod) {
    vector<long long> stack;
    for (string &token : postfix) {
        if (token == "x") {
            stack.push_back(x % mod);
        } else if (token == "+") {
            long long b = stack.back();
            stack.pop_back();
            long long a = stack.back();
            stack.back() = (a + b) % mod;
        } else if (token == "*") {
            long long b = stack.back();
            stack.pop_back();
            long long a = stack.back();
            stack.back() = a * b % mod;
        } else {
            stack.push_back(stoll(token) % mod);
        }
    }
    return stack.back();
}

bool solve() {
    long long mod, x;
    cin >> mod >> x;

    if (!mod)
        return 0;

    vector<string> postfix;
    while (cin.peek() == ' ') {
        postfix.emplace_back();
        cin >> postfix.back();
    }
    postfix.pop_back();
    postfix.pop_back();

    map<long long, int> seen;
    for (int i = 0; 1; i++) {
        x = evaluate(postfix, x, mod);
        if (seen.count(x)) {
            cout << i - seen[x] << "\n";
            return 1;
        }
        seen[x] = i;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}