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

    int maxSize = 0;

    for (string s; cin >> s; )
        maxSize = max<int>(maxSize, s.size());

    cout << maxSize;
}