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

    int size, x1, y1, x2, y2;
    cin >> size >> x1 >> y1 >> x2 >> y2;

    vector<int> count(2);
    for (int x = 0; x < size; x++)
        for (int y = 0; y < size; y++)
            if (x < x1 || x > x2 || y < y1 || y > y2)
                count[(x + y) % 2]++;

    cout << abs(count[0] - count[1]);
}