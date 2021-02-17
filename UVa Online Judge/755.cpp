#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string getNumber(string &phone) {
    static string letters = "ABCDEFGHIJKLMNOPRSTUVWXY";
    static string digits  = "222333444555666777888999";

    string number;
    for (char c : phone) {
        if (isdigit(c))
            number += c;
        else if (isupper(c))
            number += digits[letters.find(c)];
    }
    number.insert(3, 1, '-');
    return number;
}

void solve(int test) {
    int phoneCount;
    cin >> phoneCount;

    map<string, int> numberCount;
    for (int i = 0; i < phoneCount; i++) {
        string phone;
        cin >> phone;
        numberCount[getNumber(phone)]++;
    }

    if (test)
        cout << "\n";
    bool hasOutput = 0;
    for (auto &[number, count] : numberCount) {
        if (count > 1) {
            hasOutput = 1;
            cout << number << " " << count << "\n";
        }
    }
    if (!hasOutput)
        cout << "No duplicates.\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}