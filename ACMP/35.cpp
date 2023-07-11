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

    int pairCount;
    cin >> pairCount;

    for (int i = 0; i < pairCount; i++) {
        int a, b;
        cin >> a >> b;

        cout << 19 * b + (a + 239) * (a + 366) / 2 << "\n";
    }
}