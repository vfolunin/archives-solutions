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

    double sum = 0;
    for (int i = 0; i < n; i++) {
        int id, count;
        cin >> id >> count;
        sum += (id - 1000 + 0.5) * count;
    }

    cout.precision(2);
    cout << fixed << sum << "\n";
}