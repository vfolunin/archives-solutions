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

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> res(size + 1, -1e9);
    res[0] = 0;

    for (int i = 2; i <= size; i++)
        for (int step : { 2, 3 })
            if (i >= step && res[i - step] != -1e9)
                res[i] = max(res[i], res[i - step] + a[i - 1]);

    cout << res.back();
}