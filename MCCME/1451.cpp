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

    vector<int> parity(2);

    for (int i = 0; i < 3; i++) {
        int value;
        cin >> value;

        parity[value % 2 != 0] = 1;
    }

    cout << (parity[0] && parity[1] ? "YES" : "NO");
}