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

    long long aCount = 0, res = 0;
    for (char c : s)
        if (c == 'a')
            aCount++;
        else
            res += aCount;

    cout << res;
}