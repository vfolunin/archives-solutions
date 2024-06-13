#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int sum;
    cin >> sum;

    vector<int> cost = { 6, 2, 5, 6, 4, 5, 6, 3, 7, 6 };
    for (int h = 0; h < 24; h++) {
        for (int m = 0; m < 60; m++) {
            if (cost[h / 10] + cost[h % 10] + cost[m / 10] + cost[m % 10] == sum) {
                cout << setw(2) << setfill('0') << h << ":";
                cout << setw(2) << setfill('0') << m;
                return 0;
            }
        }
    }

    cout << "Impossible";
}