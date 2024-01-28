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

    int k2 = count(s.begin(), s.end(), '2');

    if (k2 * 2 > s.size())
        cout << 2;
    else if (k2 * 2 == s.size())
        cout << "=";
    else
        cout << 5;
}