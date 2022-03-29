#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int sign(int value) {
    if (value > 0)
        return 1;
    if (value < 0)
        return -1;
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b, c;
    cin >> a >> b >> c;

    if (sign(b - a) != sign(c - b))
        cout << "turned";
    else if (abs(b - a) < abs(c - b))
        cout << "accelerated";
    else if (abs(b - a) == abs(c - b))
        cout << "cruised";
    else
        cout << "braked";
}