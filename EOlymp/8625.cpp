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

    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        string cur = s;
        cur.erase(i, 1);
        res = max(res, stoi(cur));
    }

    cout << res;
}