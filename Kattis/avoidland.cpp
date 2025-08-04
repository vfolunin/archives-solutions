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

    vector<int> x(size), y(size);
    for (int i = 0; i < size; i++)
        cin >> x[i] >> y[i];

    int res = 0;
    for (vector<int> a : { x, y }) {
        sort(a.begin(), a.end());
        for (int i = 0; i < a.size(); i++)
            res += abs(i + 1 - a[i]);
    }

    cout << res;
}