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

    int width, height, index;
    cin >> width >> height >> index;
    index--;

    int y = index / (2 * height);
    int x = index % (2 * height) / 2;

    cout << y + 1 << " " << x + 1 << (index % 2 ? " R" : " L");
}