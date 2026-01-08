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

    int height, width, scaleY, scaleX;
    cin >> height >> width >> scaleY >> scaleX;

    vector<string> a(height);
    for (string &row : a)
        cin >> row;

    for (int y = 0; y < height * scaleY; y++) {
        for (int x = 0; x < width * scaleX; x++)
            cout << a[y / scaleY][x / scaleX];
        cout << "\n";
    }
}