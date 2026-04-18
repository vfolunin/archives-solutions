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

    int area;
    cin >> area;

    int resHeight = 1, resWidth = area;
    for (int height = 2; height * height <= area; height++) {
        if (area % height == 0) {
            resHeight = height;
            resWidth = area / height;
        }
    }

    cout << resHeight << " " << resWidth;
}