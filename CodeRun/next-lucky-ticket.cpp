#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isLucky(int n) {
    string s = to_string(n);
    return s[0] + s[1] + s[2] == s[3] + s[4] + s[5];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    while (!isLucky(n))
        n++;

    cout << n;
}