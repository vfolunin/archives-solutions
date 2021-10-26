#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getNum(vector<string> &a, int i) {
    int res = 0;
    for (string &row : a)
        res = res * 10 + row[i] - '0';
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> a(4);
    for (string &row : a)
        cin >> row;

    int f = getNum(a, 0), l = getNum(a, a[0].size() - 1), mod = 257;
    for (int i = 1; i + 1 < a[0].size(); i++)
        cout << (char)((f * getNum(a, i) + l) % 257);
    cout << "\n";
}