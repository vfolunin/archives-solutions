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

    char x, y;
    cin >> x >> y;

    cout << ((x - 'A' + y - '1') % 2 ? "WHITE" : "BLACK");
}