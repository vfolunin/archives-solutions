#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string read() {
    int lineCount;
    cin >> lineCount;
    cin.ignore();

    string res, line;
    for (int i = 0; i < lineCount; i++) {
        getline(cin, line);
        res += line + "\n";
    }

    return res;
}

string filterDigits(string &s) {
    string res;
    for (char c : s)
        if (isdigit(c))
            res += c;
    return res;
}

bool solve(int test) {
    string a = read();
    if (a.empty())
        return 0;
    string b = read();

    cout << "Run #" << test << ": ";
    if (a == b)
        cout << "Accepted\n";
    else if (filterDigits(a) == filterDigits(b))
        cout << "Presentation Error\n";
    else
        cout << "Wrong Answer\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}