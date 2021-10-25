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

    string teams;
    for (int c = 'A'; c <= 'P'; c++)
        teams += c;

    for (int i = 0, j = 0; i < 15; i++, j += 2) {
        int a, b;
        cin >> a >> b;
        teams += teams[a > b ? j : j + 1];
    }

    cout << teams.back() << "\n";
}