#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int opCount;
    cin >> opCount;

    if (!opCount)
        return 0;

    if (test)
        cout << "\n";

    vector<int> pile(2);
    for (int i = 0; i < opCount; i++) {
        string op;
        int dishCount;
        cin >> op >> dishCount;

        if (op == "DROP") {
            cout << "DROP 1 " << dishCount << "\n";
            pile[0] += dishCount;
        } else {
            while (dishCount) {
                if (!pile[1]) {
                    cout << "MOVE 1->2 " << pile[0] << "\n";
                    swap(pile[0], pile[1]);
                }
                int k = min(pile[1], dishCount);
                pile[1] -= k;
                dishCount -= k;
                cout << "TAKE 2 " << k << "\n";
            }
        }
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}