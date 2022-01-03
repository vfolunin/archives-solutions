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

    vector<int> open(600, 1);

    for (int i = 0; i < 3; i++) {
        int from;
        cin >> from;
        fill(open.begin() + from, open.begin() + from + 200, 0);
    }

    int area = 0;
    for (int o : open)
        area += o;
    area *= 100;

    cout << area << "\n";
}