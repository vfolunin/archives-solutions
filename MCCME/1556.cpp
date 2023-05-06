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

    char prev, cur = 0;

    while (1) {
        prev = cur;
        cin >> cur;

        if (prev == cur)
            break;

        cout << (int)cur << "\n";
    }
}