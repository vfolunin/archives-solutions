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

    int h, limit;
    cin >> h >> limit;

    for (int i = 1; i <= limit; i++) {
        if (-6 * i * i * i * i + h * i * i * i + 2 * i * i + i <= 0) {
            cout << "The balloon first touches ground at hour:\n" << i;
            return 0;
        }
    }

    cout << "The balloon does not touch ground in the given time.";
}