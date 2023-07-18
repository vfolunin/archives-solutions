#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    vector<int> fib = { 1, 2 };
    for (int i = 2; fib.back() <= s.size(); i++)
        fib.push_back(fib[i - 2] + fib[i - 1]);

    for (int i = 0; i < fib.size() && fib[i] <= s.size(); i++)
        cout << s[fib[i] - 1];
}