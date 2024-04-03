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

    int ax, ay, bx, by, n;
    cin >> ax >> ay >> bx >> by >> n;

    cout << ax + bx + n << " " << ay + by + n;
}