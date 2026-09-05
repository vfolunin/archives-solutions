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

    vector<int> count(3);
    int totalCount = 0;
    for (int &count : count) {
        cin >> count;
        totalCount += count;
    }

    string s = "MFN";

    string res;
    for (int i = 0; i < totalCount; i++) {
        vector<int> order = { 0, 1, 2 };
        sort(order.begin(), order.end(), [&](int l, int r) {
            return count[l] > count[r];
        });

        bool found = 0;
        for (int index : order) {
            if (count[index] && (res.empty() || res.back() != s[index])) {
                res.push_back(s[index]);
                count[index]--;
                found = 1;
                break;
            }
        }

        if (!found) {
            cout << "O nei!";
            return 0;
        }
    }

    cout << res;
}