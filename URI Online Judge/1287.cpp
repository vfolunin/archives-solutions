#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string line;
    if (!getline(cin, line))
        return 0;

    string num;
    for (char c : line) {
        if (isdigit(c)) {
            num += c;
        } else if (c == 'o' || c == 'O') {
            num += '0';
        } else if (c == 'l') {
            num += '1';
        } else if (c != ',' && c != ' ') {
            cout << "error\n";
            return 1;
        }
    }

    reverse(num.begin(), num.end());
    while (num.size() > 1 && num.back() == '0')
        num.pop_back();
    reverse(num.begin(), num.end());

    if (num.size() == 0 || num.size() > 10) {
        cout << "error\n";
        return 1;
    }

    long long value = stoll(num);

    if (value < 1LL << 31)
        cout << value << "\n";
    else
        cout << "error\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}