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

    map<int, int> count;
    for (int i = 0; i < 10 * n * 5; i++) {
        int value;
        cin >> value;

        count[value]++;
    }

    bool found = 0;
    for (auto &[value, count] : count) {
        if (count > 2 * n) {
            found = 1;
            cout << value << " ";
        }
    }

    if (!found)
        cout << -1;
}