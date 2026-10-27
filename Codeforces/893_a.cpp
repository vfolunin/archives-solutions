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

    int gameCount;
    cin >> gameCount;

    int p1 = 1, p2 = 2, p3 = 3;
    for (int i = 0; i < gameCount; i++) {
        int winner;
        cin >> winner;

        if (p1 != winner && p2 != winner) {
            cout << "NO";
            return 0;
        }

        if (winner == p1)
            swap(p2, p3);
        else
            swap(p1, p3);
    }

    cout << "YES";
}