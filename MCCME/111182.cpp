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

    string sa;
    cin >> sa;

    vector<int> countA(10);
    for (char c : sa)
        countA[c - '0']++;

    string sb;
    cin >> sb;

    vector<int> countB(10);
    for (char c : sb)
        countB[c - '0']++;

    bool found = 0;
    for (int i = 9; i; i--) {
        if (countA[i] && countB[i]) {
            for (int j = 0; j < countA[i] && j < countB[i]; j++)
                cout << i;
            found = 1;
        }
    }

    if (countA[0] && countB[0]) {
        if (found) {
            for (int i = 0; i < countA[0] && i < countB[0]; i++)
                cout << 0;
        } else {
            cout << 0;
            found = 1;
        }
    }

    if (!found)
        cout << -1;
}