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

    while (1) {
        int n;
        cin >> n;

        if (!n)
            break;

        for (int i = 1; i <= n; i++)
            cout << i << (i + 1 <= n ? " " : "\n");
    }
}