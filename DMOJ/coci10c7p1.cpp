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

    vector<int> res(size + 1, 1e9);
    res[0] = 0;
    for (int i = 1; i < res.size(); i++)
        for (int j : { 3, 5 })
            if (i >= j)
                res[i] = min(res[i], res[i - j] + 1);

    cout << (res.back() != 1e9 ? res.back() : -1);
}