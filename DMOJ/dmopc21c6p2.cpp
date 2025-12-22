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

    int size, partCount;
    string s;
    cin >> size >> partCount >> s;

    vector<int> parts;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            if (parts.empty() || s[i - 1] == '1')
                parts.push_back(1);
            else
                parts.back()++;
        }
    }

    sort(parts.rbegin(), parts.rend());

    int res = 0;
    for (int i = 0; i < partCount && i < parts.size(); i++)
        res += parts[i];

    cout << res;
}