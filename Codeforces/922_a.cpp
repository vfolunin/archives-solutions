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

    int copyCount, origCount;
    cin >> copyCount >> origCount;

    if (origCount == 0) {
        cout << "NO";
    } else if (origCount == 1) {
        cout << (copyCount == 0 ? "YES" : "NO");
    } else {
        copyCount -= origCount - 1;

        cout << (copyCount >= 0 && copyCount % 2 == 0 ? "YES" : "NO");
    }
}