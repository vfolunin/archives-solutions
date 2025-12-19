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

    int size, speed;
    string s;
    cin >> size >> speed >> s;

    int res = 0;
    for (char c : s) {
        if (c == 'D') {
            speed++;
        } else if (c == 'U') {
            if (speed)
                speed--;
        }
        res += !speed;
    }

    cout << res << "\n";
}