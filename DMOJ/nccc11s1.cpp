#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> getFib() {
    vector<int> fib = { 0, 1 };
    for (int i = 2; fib.back() < 1e5; i++)
        fib.push_back(fib[i - 1] + fib[i - 2]);
    
    vector<string> res;
    for (int value : fib)
        res.push_back(to_string(value));
    return res;
}

void solve() {
    string s;
    cin >> s;

    static vector<string> parts = getFib();

    vector<int> maxPartCount(s.size() + 1, -1);
    maxPartCount[0] = 0;
    for (int size = 1; size <= s.size(); size++)
        for (string &part : parts)
            if (size >= part.size() && s.substr(size - part.size(), part.size()) == part &&
                maxPartCount[size - part.size()] != -1 && maxPartCount[size] < maxPartCount[size - part.size()] + 1)
                maxPartCount[size] = maxPartCount[size - part.size()] + 1;

    cout << (maxPartCount.back() > 1 ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}