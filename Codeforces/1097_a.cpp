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

    char valueA, suitA;
    cin >> valueA >> suitA;

    for (int i = 0; i < 5; i++) {
        char valueB, suitB;
        cin >> valueB >> suitB;

        if (valueA == valueB || suitA == suitB) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}