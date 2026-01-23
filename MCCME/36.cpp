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

    int n;
    cin >> n;

    vector<int> res;
    for (int d : { 2, 3, 5, 29, 869, 756029 }) {
        while (n % d == 0) {
            n /= d;
            res.push_back(d);
        }
    }

    if (n == 1) {
        for (int d : res)
            cout << d << " ";
    } else {
        cout << 0;
    }
}