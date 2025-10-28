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

    char targetC;
    string s;
    cin >> targetC;
    cin.ignore();
    getline(cin, s);

    cout << s << "\n" << count_if(s.begin(), s.end(), [&](char c) {
        return tolower(c) == targetC;
    });
}