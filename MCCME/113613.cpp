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

    int count, sum;
    cin >> count >> sum;

    cout << "YES\n";

    if (sum) {
        cout << sum << " ";
        count--;
    }

    if (count % 2) {
        cout << "0 ";
        count--;
    }

    for (int i = 0, value = 1; i < count; i += 2, value++) {
        value += value == abs(sum);
        cout << value << " " << -value << " ";
    }
}