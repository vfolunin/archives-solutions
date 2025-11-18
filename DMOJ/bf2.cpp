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
    int size;
    cin >> s >> size;

    string res = s.substr(0, size);
    for (int l = 0; l < s.size(); l++)
        for (int r = l + size - 1; r < s.size(); r++)
            res = min(res, s.substr(l, r - l + 1));

    cout << res;
}