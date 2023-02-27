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

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j <= i; j++)
            cout << (char)('a' + j);
        cout << "\n";
    }
}