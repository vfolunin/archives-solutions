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

    long long sum, count, delta;
    cin >> sum >> count >> delta;

    while (1) {
        if (sum <= count) {
            cout << sum;
            break;
        }
        sum -= count;
        count += delta;
    }
}