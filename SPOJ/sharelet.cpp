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

    string a, b;
    getline(cin, a);
    getline(cin, b);

    int res = 0;
    for (char c = 'a'; c <= 'z'; c++)
        res += a.find(c) != -1 && b.find(c) != -1;

    cout << res;
}