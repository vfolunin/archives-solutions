#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string factorial;
    cin >> factorial;

    vector<string> factorials = {
        "", "1", "2", "6", "24", "120", "720", "5040"
    };

    if (auto it = find(factorials.begin(), factorials.end(), factorial); it != factorials.end()) {
        cout << it - factorials.begin();
        return 0;
    }

    double fSize = log10(5040);
    for (int i = 8; 1; i++) {
        fSize += log10(i);
        if (floor(fSize) + 1 >= factorial.size()) {
            cout << i;
            return 0;
        }
    }
}