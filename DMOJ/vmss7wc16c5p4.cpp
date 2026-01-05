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

    vector<int> parts(3);
    for (int &part : parts)
        cin >> part;

    vector<int> res(size + 1, -1e9);
    res[0] = 0;
    for (int size = 1; size < res.size(); size++)
        for (int part : parts)
            if (size >= part && res[size - part] != -1e9)
                res[size] = max(res[size], res[size - part] + 1);

    cout << res.back();
}