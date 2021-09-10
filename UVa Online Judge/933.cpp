#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int depositCount;
    cin.ignore(2);
    cin >> depositCount;

    map<char, int> deposit;
    int totalAmount = 0;
    for (int i = 0; i < depositCount; i++) {
        char name;
        cin >> name;
        cin.ignore();
        cin >> deposit[name];
        totalAmount += deposit[name];
        if (i + 1 < depositCount)
            cin.ignore();
    }

    map<char, int> pipe;
    for (int i = 0; i < depositCount; i++) {
        char name;
        cin >> name;
        cin.ignore();
        cin >> pipe[toupper(name)];
        if (i + 1 < depositCount)
            cin.ignore();
    }

    cout << setw(3) << "t";
    for (auto &[name, _] : deposit)
        cout << setw(4) << name;
    cout << "\n";

    cout << string(4 * deposit.size() + 3, '-') << "\n";

    for (int t = 0; 1; t++) {
        cout << setw(3) << t;
        for (auto &[_, amount] : deposit)
            cout << setw(4) << amount;
        cout << "\n";

        if ((--deposit.end())->second == totalAmount)
            break;

        for (char i = deposit.size() - 2; i >= 0; i--) {
            int amount = min(deposit['A' + i], pipe['A' + i]);
            deposit['A' + i] -= amount;
            deposit['B' + i] += amount;
        }
    }
}