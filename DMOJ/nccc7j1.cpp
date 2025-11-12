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

    int res = 0;
    for (int i = 0; i < 5; i++) {
        char c;
        cin >> c;

        res += c == 'P';
    }

    cout << res << "\n";
}