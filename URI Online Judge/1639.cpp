#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string number;
    cin >> number;

    if (number == "0")
        return 0;

    set<string> numbers;
    while (1) {
        int val = stoi(number);
        string nextNumber = to_string(val * val);
        if (nextNumber.size() < 2 * number.size())
            nextNumber = string(2 * number.size() - nextNumber.size(), '0') + nextNumber;
        if (numbers.count(nextNumber))
            break;
        numbers.insert(nextNumber);
        number = nextNumber.substr((nextNumber.size() - number.size()) / 2, number.size());
    }

    cout << numbers.size() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}