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
    cin >> a >> b;

    set<string> pairs;
    for (int i = 0; i + 1 < b.size(); i++)
        pairs.insert(b.substr(i, 2));

    int res = 0;
    for (int i = 0; i + 1 < a.size(); i++)
        res += pairs.count(a.substr(i, 2));

    cout << res;
}