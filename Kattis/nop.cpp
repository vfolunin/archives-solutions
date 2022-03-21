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

    string ops;
    cin >> ops;

    int prevOpPos = 0, nopCount = 0;
    for (int i = 0; i < ops.size(); i++) {
        if (isupper(ops[i])) {
            nopCount += (4 - (i - prevOpPos) % 4) % 4;
            prevOpPos = i;
        }
    }

    cout << nopCount;
}