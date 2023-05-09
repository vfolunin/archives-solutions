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

    vector<long long> res(max(4, size + 1));
    res[0] = 1;
    res[1] = 2;
    res[2] = 4;
    res[3] = 8;

    for (int i = 4; i < res.size(); i++)
        res[i] = res[i - 1] + res[i - 2] + res[i - 3] + res[i - 4];

    cout << res[size];
}