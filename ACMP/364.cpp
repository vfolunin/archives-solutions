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

    vector<long long> perfect = { 6, 28, 496, 8128, 33550336, 8589869056, 137438691328, 2305843008139952128 };

    long long l, r;
    cin >> l >> r;

    int found = 0;
    for (long long p : perfect) {
        if (l <= p && p <= r) {
            cout << p << "\n";
            found = 1;
        }
    }

    if (!found)
        cout << "Absent";
}