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

    vector<int> a(size);
    int d = 0;
    for (int &value : a) {
        cin >> value;
        d = gcd(d, value);
    }

    int res = 0;
    for (int value : a)
        res += value / d;

    cout << res;
}