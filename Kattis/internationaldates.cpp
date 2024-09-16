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

    int a = stoi(s.substr(0, 2));
    int b = stoi(s.substr(3, 2));

    if (a <= 12 && b <= 12)
        cout << "either";
    else if (a <= 12)
        cout << "US";
    else
        cout << "EU";
}