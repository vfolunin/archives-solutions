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

    vector<int> area(4);
    int totalArea = 0;

    for (int &a : area) {
        cin >> a;
        totalArea += a;
    }

    sort(area.begin(), area.end());

    for (int h = 1; h <= totalArea; h++) {
        if (totalArea % h)
            continue;
        int w = totalArea / h;

        if ((area[0] + area[1]) % h)
            continue;
        int w1 = (area[0] + area[1]) / h;

        if ((area[2] + area[3]) % h)
            continue;
        int w2 = (area[2] + area[3]) / h;

        if (w1 + w2 != w)
            continue;

        if ((area[0] + area[2]) % w)
            continue;
        int h1 = (area[0] + area[2]) / w;

        if ((area[1] + area[3]) % w)
            continue;
        int h2 = (area[1] + area[3]) / w;

        if (h1 + h2 != h)
            continue;

        cout << "S\n";
        return 0;
    }

    cout << "N\n";
}