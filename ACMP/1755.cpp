#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int readTime() {
    int h, m;
    char colon;
    cin >> h >> colon >> m;

    return h * 60 + m;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t = readTime();

    if (4 * 60 + 30 <= t && t < 11 * 60 + 30)
        cout << "morning";
    else if (11 * 60 + 30 <= t && t < 15 * 60 + 30)
        cout << "day";
    else if (15 * 60 + 30 <= t && t < 23 * 60 + 30)
        cout << "evening";
    else
        cout << "night";
}