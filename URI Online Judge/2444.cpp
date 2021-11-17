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

    int volume, changeCount;
    cin >> volume >> changeCount;

    for (int i = 0; i < changeCount; i++) {
        int change;
        cin >> change;
        volume = min(max(0, volume + change), 100);
    }

    cout << volume << "\n";
}