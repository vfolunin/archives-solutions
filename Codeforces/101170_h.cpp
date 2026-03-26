#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long grayCodeIndex(string &s, int i) {
    if (i == s.size())
        return 0;
    if (s[i] == '0')
        return grayCodeIndex(s, i + 1);
    return (1LL << (s.size() - i)) - 1 - grayCodeIndex(s, i + 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a, b;
    cin >> a >> a >> b;

    cout << grayCodeIndex(b, 0) - grayCodeIndex(a, 0) - 1;
}