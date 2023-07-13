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
    x -= 'A';
    y -= '1';

    cout << ((x + y) % 2 ? "WHITE" : "BLACK");
}