#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int sum, product;
    if (!(cin >> sum >> product))
        return 0;
    
    if (sum == product) {
        cout << "1\n";
        return 1;
    }

    for (int count = 2; count <= sum; count++) {
        if (pow((double)sum / count, count) >= product) {
            cout << count << "\n";
            return 1;
        }
    }

    cout << "-1\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}