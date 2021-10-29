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

    string s = "x = 35";

    cout << string(39, '-') << "\n";
    cout << "|" << s << string(31, ' ') << "|\n";
    cout << "|" << string(37, ' ') << "|\n";
    cout << "|" << string(15, ' ') << s << string(16, ' ') << "|\n";
    cout << "|" << string(37, ' ') << "|\n";
    cout << "|" << string(31, ' ') << s << "|\n";
    cout << string(39, '-') << "\n";
}