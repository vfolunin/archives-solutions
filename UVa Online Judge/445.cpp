#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void process(string &line) {
    int k = 0;
    for (char c : line) {
        if (isdigit(c)) {
            k += c - '0';
        } else if (c == '!') {
            cout << "\n";
        } else if (c == 'b') {
            cout << string(k, ' ');
            k = 0;
        } else {
            cout << string(k, c);
            k = 0;
        }
    }
    cout << "\n";
}

bool solve(int test) {
    if (test)
        cout << "\n";
    string line;
    while (1) {
        if (!getline(cin, line))
            return 0;
        if (line.empty())
            break;
        process(line);
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}