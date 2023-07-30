#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getDiff(string &a, string &b) {
    int diff = 0;
    for (int i = 0; i < a.size(); i++)
        diff += a[i] != b[i];
    return diff;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a;
    int queryCount;
    cin >> a >> queryCount;

    int resDiff = a.size() + 1;
    vector<int> res;

    for (int i = 1; i <= queryCount; i++) {
        string b;
        cin >> b;

        int diff = getDiff(a, b);
        if (resDiff > diff) {
            resDiff = diff;
            res = { i };
        } else if (resDiff == diff) {
            res.push_back(i);
        }
    }

    cout << res.size() << "\n";
    for (int value : res)
        cout << value << " ";
}