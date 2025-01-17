#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void tryUpdate(long long h, long long w, long long &bestH, long long &bestW) {
    if (bestH * bestW > h * w) {
        bestH = h;
        bestW = w;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long ah, aw, bh, bw;
    cin >> ah >> aw >> bh >> bw;

    long long bestH = 1e9, bestW = 1e9;
    tryUpdate(max(ah, bh), aw + bw, bestH, bestW);
    tryUpdate(max(ah, bw), aw + bh, bestH, bestW);
    tryUpdate(ah + bh, max(aw, bw), bestH, bestW);
    tryUpdate(ah + bw, max(aw, bh), bestH, bestW);

    cout << bestH << " " << bestW;
}