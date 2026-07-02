#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int triangleCount;
    cin >> triangleCount;

    set<vector<int>> triangles;
    for (int i = 0; i < triangleCount; i++) {
        vector<int> triangle(3);
        int d = 0;
        for (int &value : triangle) {
            cin >> value;
            d = gcd(d, value);
        }

        for (int &value : triangle)
            value /= d;

        sort(triangle.begin(), triangle.end());
        triangles.insert(triangle);
    }

    cout << triangles.size();
}