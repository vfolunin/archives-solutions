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

    int count;
    cin >> count;

    int cutCount = 0;
    while (count > 1)
        count -= ++cutCount;

    cout << cutCount << "\n";
    for (int i = 1; i <= cutCount; i++)
        cout << "-5000 " << -5000 + i << " " << 5000 - i << " -5000\n";
}