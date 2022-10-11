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

    int prev, cur;
    for (int i = 0; cin >> cur; i++) {
        if (i && prev < cur)
            cout << cur << " ";
        prev = cur;
    }
}