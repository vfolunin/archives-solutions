#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int getDist(int a, int b, int size) {
    int dist = abs(a - b);
    return min(dist, size - dist);
}

int main() {
    freopen("i.in", "r", stdin);
    freopen("i.out", "w", stdout);
 
    int size;
    cin >> size;

    unordered_map<int, vector<int>> pos;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        pos[value].push_back(i);
    }

    int resI, resJ, resDist = 0;
    for (auto &[_, pos] : pos) {
        if (pos.size() < 2)
            continue;

        for (int i = 0, j = 0; i < pos.size(); i++) {
            while (getDist(pos[i], pos[j], size) < getDist(pos[i], pos[(j + 1) % pos.size()], size))
                j = (j + 1) % pos.size();

            int dist = getDist(pos[i], pos[j], size);
            if (resDist < dist) {
                resI = pos[i];
                resJ = pos[j];
                resDist = dist;
            }
        }
    }

    cout << resI + 1 << " " << resJ + 1;
}