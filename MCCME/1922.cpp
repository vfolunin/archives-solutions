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

    int h, w;
    cin >> h >> w;

    string bestName;
    int bestSum = 1e9;

    for (int y = 0; y < h; y++) {
        string name;
        cin >> name;

        int sum = 0;
        for (int x = 0; x < w; x++) {
            int value;
            cin >> value;
            sum += value;
        }

        if (bestSum > sum) {
            bestName = name;
            bestSum = sum;
        }
    }

    cout << bestName;
}