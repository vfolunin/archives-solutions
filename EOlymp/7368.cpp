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

    for (int y = 0; y < h; y++) {
        vector<int> a(w);
        int minValue = 1e9, maxValue = -1e9;
        for (int &value : a) {
            cin >> value;
            minValue = min(minValue, value);
            maxValue = max(maxValue, value);
        }

        a.erase(remove(a.begin(), a.end(), minValue), a.end());
        a.erase(remove(a.begin(), a.end(), maxValue), a.end());

        double sum = 0;
        for (int value : a)
            sum += value;

        cout.precision(2);
        cout << fixed << sum / a.size() << " ";
    }
}