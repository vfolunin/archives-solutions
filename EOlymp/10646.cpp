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

    vector<int> res(s.size() + 1);
    for (int size = 1; size <= s.size(); size++) {
        res[size] = res[size - 1] + 1;

        for (int prefixSize = size - 1, suffixSize = 1; prefixSize >= suffixSize; prefixSize--, suffixSize++) {
            string prefix = s.substr(0, prefixSize);
            string suffix = s.substr(prefixSize, suffixSize);
            if (prefix.find(suffix) != -1)
                res[size] = min(res[size], res[prefixSize]);
        }
    }

    cout << res.back();
}