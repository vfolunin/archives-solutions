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

    int sum = 0;
    for (int i = 0; i < 9; i++) {
        int x;
        cin >> x;
        sum += x;
    }

    vector<string> names = {
        "Dasher", "Dancer", "Prancer", "Vixen", "Comet",
        "Cupid", "Donner", "Blitzen", "Rudolph"
    };

    cout << names[(sum + 8) % 9] << "\n";
}