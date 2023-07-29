#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isGood(int n) {
    string s = to_string(n);
    return set<char>(s.begin(), s.end()).size() <= 2;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; 1; i++) {
        if (isGood(n - i)) {
            cout << n - i;
            break;
        }
        if (isGood(n + i)) {
            cout << n + i;
            break;
        }
    }
}