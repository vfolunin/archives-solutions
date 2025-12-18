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

    vector<int> count(201);
    for (int i = 0; i < size; i++) {
        int dist;
        cin >> dist;

        count[dist]++;
    }

    for (int res = 1; 1; res++) {
        vector<int> resCount(201);
        for (int y = 0; y < res; y++)
            for (int x = 0; x < res; x++)
                if (y + x < resCount.size())
                    resCount[y + x]++;

        bool ok = 1;
        for (int dist = 0; ok && dist < count.size(); dist++)
            ok &= count[dist] <= resCount[dist];

        if (ok) {
            cout << res;
            break;
        }
    }
}