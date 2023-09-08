#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int hasOne(int n) {
    while (n) {
        if (n % 10 == 1)
            return 1;
        n /= 10;
    }
    return 0;
}

int getCode(int n) {
    int res = n;
    while (n) {
        res *= n % 10;
        n /= 10;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    map<int, vector<int>> res;
    for (int i = 1; i < 10000; i++)
        if (!hasOne(i))
            res[getCode(i)].push_back(i);

    int n;
    cin >> n;

    if (res[n].size() == 1)
        cout << res[n][0];
    else
        cout << "ERROR";
}