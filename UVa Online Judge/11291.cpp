#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double read(stringstream &ss) {
    while (ss.peek() == ' ')
        ss.ignore();
    if (ss.peek() == '(') {
        double p;
        ss.ignore();
        ss >> p;
        double a = read(ss);
        double b = read(ss);
        ss.ignore();
        return p * (a + b) + (1 - p) * (a - b);
    } else {
        double x;
        ss >> x;
        return x;
    }
}

bool solve() {
    string line;
    getline(cin, line);

    if (line == "()")
        return 0;

    stringstream ss(line);

    cout.precision(2);
    cout << fixed << read(ss) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}