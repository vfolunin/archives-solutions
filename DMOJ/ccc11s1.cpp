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

    int sCount = 0, tCount = 0;
    for (char c; cin >> c; ) {
        sCount += tolower(c) == 's';
        tCount += tolower(c) == 't';
    }

    cout << (sCount < tCount ? "English" : "French");
}