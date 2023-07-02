#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int commonSuffix(string &a, string &b) {
    int res = 0;
    while (res < a.size() && res < b.size() && *(a.rbegin() + res) == *(b.rbegin() + res))
        res++;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> a(4);
    for (string &s : a)
        cin >> s;

    cout << max(commonSuffix(a[0], a[2]), commonSuffix(a[1], a[3]));
}