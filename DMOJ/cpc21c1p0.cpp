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

    for (char c = 'a'; 1; c++) {
        if (s.find(c) == -1) {
            cout << c;
            break;
        }
    }
}