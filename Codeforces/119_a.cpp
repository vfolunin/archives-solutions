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

    vector<int> value(2);
    int count;
    cin >> value[0] >> value[1] >> count;

    for (int i = 0; 1; i++) {
        int delta = gcd(value[i % 2], count);
        if (count >= delta) {
            count -= delta;
        } else {
            cout << 1 - i % 2;
            break;
        }
    }
}