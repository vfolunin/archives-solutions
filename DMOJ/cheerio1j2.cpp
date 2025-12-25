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

    int size, targetX;
    cin >> size >> targetX;

    string resName;
    int resDist = 1e9;

    for (int i = 0; i < size; i++) {
        string name;
        int x;
        cin >> name >> x;

        int dist = abs(x - targetX);

        if (resDist > dist) {
            resName = name;
            resDist = dist;
        }
    }

    cout << resName;
}