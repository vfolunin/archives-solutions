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

    int size;
    cin >> size;

    map<int, int> maxHeight;
    for (int i = 0; i < size; i++) {
        int width, height;
        cin >> width >> height;
        maxHeight[width] = max(maxHeight[width], height);
    }

    long long res = 0;
    for (auto &[width, height] : maxHeight)
        res += height;

    cout << res;
}