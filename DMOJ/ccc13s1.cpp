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

    int year;
    cin >> year;

    while (1) {
        year++;

        string s = to_string(year);
        if (set<char>(s.begin(), s.end()).size() == s.size())
            break;
    }

    cout << year;
}