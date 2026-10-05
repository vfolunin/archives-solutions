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

    int i, j;
    string s;
    cin >> i >> i >> j >> s;

    cout << (s[i - 1] != s[j - 1]);
}