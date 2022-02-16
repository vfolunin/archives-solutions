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

    int width, borderCount;
    cin >> width >> borderCount;

    vector<int> parts;
    int lastCoord = 0;
    for (int i = 0; i < borderCount; i++) {
        int coord;
        cin >> coord;
        parts.push_back(coord - lastCoord);
        lastCoord = coord;
    }
    parts.push_back(width - lastCoord);

    set<int> sizes;
    for (int l = 0; l < parts.size(); l++) {
        int size = 0;
        for (int r = l; r < parts.size(); r++) {
            size += parts[r];
            sizes.insert(size);
        }
    }

    for (int size : sizes)
        cout << size << " ";
}