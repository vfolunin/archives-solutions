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

    double sum;
    cin >> sum;

    for (int i = 0; i < 3; i++) {
        double value;
        cin >> value;

        sum += value;
        cout << fixed << sum << "\n";
    }
}