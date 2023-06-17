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

    char x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1 -= 'a';
    y1 -= '1';
    x2 -= 'a';
    y2 -= '1';

    if ((x1 + y1) % 2 == (x2 + y2) % 2 && y1 <= y2 && abs(x1 - x2) <= y2 - y1)
        cout << "YES";
    else
        cout << "NO";
}