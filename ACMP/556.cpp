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
    cin >> size;

    vector<vector<double>> p(size + 1, vector<double>(2));
    p[0][1] = 1;

    for (int i = 1; i < p.size(); i++) {
        double curP;
        cin >> curP;

        p[i][1] = p[i - 1][1] * curP + p[i - 1][0] * (1 - curP);
        p[i][0] = p[i - 1][0] * curP + p[i - 1][1] * (1 - curP);
    }

    cout << fixed << p.back()[1];
}