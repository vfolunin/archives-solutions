#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void addDigits(int n, vector<int> &digits) {
    while (n) {
        digits[n % 10]++;
        n /= 10;
    }
}

void solve() {
    string streetName;
    cin.ignore();
    getline(cin, streetName);
    cout << streetName << "\n";

    int addressCount;
    string addressNoun;
    cin >> addressCount >> addressNoun;
    cout << addressCount << " " << addressNoun << "\n";

    vector<int> digits(10);
    while (addressCount) {
        string token;
        cin >> token;

        if (token == "+") {
            int l, r, step;
            cin >> l >> r >> step;

            for (int i = l; i <= r; i += step) {
                addDigits(i, digits);
                addressCount--;
            }
        } else {
            addDigits(stoi(token), digits);
            addressCount--;
        }
    }

    int totalDigits = 0;
    for (int d = 0; d < 10; d++) {
        cout << "Make " << digits[d] << " digit " << d << "\n";
        totalDigits += digits[d];
    }

    cout << "In total " << totalDigits << " digit" << (totalDigits > 1 ? "s\n" : "\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}