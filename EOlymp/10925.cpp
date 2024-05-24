#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size + 1, 1e9);
    cin >> a[0];
    a[1] = a[0];

    for (int i = 2; i <= size; i++) {
        cin >> a[i];
        a[i - 1] = min(a[i - 1], a[i]);
    }

    cout << accumulate(a.begin(), a.end(), 0);
}