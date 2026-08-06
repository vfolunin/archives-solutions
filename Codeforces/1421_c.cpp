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

    string s;
    cin >> s;

    cout << "3\n";
    cout << "R " << s.size() - 1 << "\n";
    cout << "L " << s.size() << "\n";
    cout << "L 2";
}