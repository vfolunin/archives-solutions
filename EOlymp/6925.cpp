#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    char digit;
    string number;
    cin >> digit >> number;

    if (digit == '0' && number == "0")
        return 0;

    number.erase(remove(number.begin(), number.end(), digit), number.end());

    number = "0" + number;
    int i = 0;
    while (i < number.size() && number[i] == '0')
        i++;
    if (i == number.size())
        i--;
    number = number.substr(i);

    cout << number << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}