#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int num, den;
    char slash;
    if (!(cin >> num >> slash >> den))
        return 0;

    int res = 0;
    for (int denA = den + 1; 1; denA++) {
        int numB = denA - den;
        int denB = den * denA;

        if (denB < denA * numB)
            break;

        res += denB % numB == 0;
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}