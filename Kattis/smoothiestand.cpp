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

    int w, h;
    cin >> w >> h;

    vector<int> num(w);
    for (int &value : num)
        cin >> value;

    int res = 0;
    for (int y = 0; y < h; y++) {
        int count = 1e9;

        for (int x = 0; x < w; x++) {
            int den;
            cin >> den;

            if (den)
                count = min(count, num[x] / den);
        }

        int price;
        cin >> price;

        res = max(res, count * price);
    }

    cout << res;
}