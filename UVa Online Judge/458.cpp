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

    char c;
    cin >> noskipws;
    while (cin >> c) {
        if (c != '\n')
            c -= 7;
        cout << c;
    }
}