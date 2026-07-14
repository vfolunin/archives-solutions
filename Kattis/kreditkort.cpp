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

    int value;
    cin >> value;

    vector<int> a = { 500, 1000, 2000, 5000, 10000, 20000 };
    vector<int> b = { 500, 1000, 2000, 5250, 11000, 24000 };

    cout << a[lower_bound(b.begin(), b.end(), value) - b.begin()];
}