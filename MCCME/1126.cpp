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
    double speed1, speed2;
    cin >> size >> speed1 >> speed2;

    vector<double> coord(size + 1);
    for (int i = 1; i < coord.size(); i++)
        cin >> coord[i];

    double res = 0;
    for (int i = 0; i + 1 < coord.size(); i++)
        res = max(res, ((coord[i + 1] - coord[i]) / speed1 * speed2 - (coord[i] + coord[i + 1])) / 2);

    cout << fixed << res;
}