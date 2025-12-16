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

    int aSize;
    cin >> aSize;

    int aRes = 0;
    for (int i = 0; i < aSize; i++) {
        int h, w;
        cin >> h >> w;

        aRes = max(aRes, h * w);
    }

    int bSize;
    cin >> bSize;

    int bRes = 0;
    for (int i = 0; i < bSize; i++) {
        int h, w;
        cin >> h >> w;

        bRes = max(bRes, h * w);
    }

    if (aRes > bRes)
        cout << "Casper";
    else if (aRes < bRes)
        cout << "Natalie";
    else
        cout << "Tie";
}