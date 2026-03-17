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

    int size;
    cin >> size;

    vector<int> digitRes = { 19, 17, 15, 13, 11, 9, 11, 13, 15, 17 };
    int res = 0;

    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < s.size(); j++)
            res += digitRes[s[j] - '0'] + (j + 1 < s.size() ? 3 : 0);
        res += i + 1 < size ? 7 : 0;
    }

    cout << res << "\n";
}