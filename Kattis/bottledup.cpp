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

    int volume, a, b;
    cin >> volume >> a >> b;

    for (int kb = 0; b * kb <= volume; kb++) {
        if ((volume - b * kb) % a == 0) {
            cout << (volume - b * kb) / a << " " << kb;
            return 0;
        }
    }

    cout << "Impossible";
}