#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> read() {
    string s;
    cin >> s;

    int bar = s.find('|');
    return { bar, s.size() - 1 - bar };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    auto [a, b] = read();
    auto [c, d] = read();

    cout << (a == c || a == d || b == c || b == d ? "Yes" : "No");
}