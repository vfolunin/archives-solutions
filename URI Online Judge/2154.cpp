#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int summandCount;
    if (!(cin >> summandCount))
        return 0;

    int coeff, pow;
    char buf;
    
    for (int i = 0; i < summandCount; i++) {
        if (i)
            cin >> buf;
        cin >> coeff >> buf >> pow;

        if (i)
            cout << " + ";
        cout << coeff * pow << "x";
        if (pow > 2)
            cout << pow - 1;
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}