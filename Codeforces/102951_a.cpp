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

    vector<int> x(size);
    for (int &x : x)
        cin >> x;

    vector<int> y(size);
    for (int &y : y)
        cin >> y;

    int res = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            res = max(res, (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));

    cout << res;
}