#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    int res = 0;
    for (int y = 0; y < h; y++) {
        unordered_set<string> values;
        for (int x = 0; x < w; x++) {
            string value;
            cin >> value;

            if (values.count(value))
                res++;
            else
                values.insert(value);
        }
    }

    cout << res;
}