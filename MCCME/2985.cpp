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

    char maxC = 0;

    while (1) {
        char c = cin.get();

        maxC = max(maxC, c);

        if (c == '.')
            break;
    }

    cout << (int)maxC;
}