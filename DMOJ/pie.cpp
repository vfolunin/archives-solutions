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

    int personCount, queryCount;
    cin >> personCount >> queryCount;

    vector<double> res(personCount);
    double size = 1;

    for (int i = 0; i < queryCount; i++) {
        int person, percent;
        cin >> person >> percent;

        res[person - 1] += size * (percent / 100.0);
        size *= (1 - percent / 100.0);
    }

    for (double value : res)
        cout << fixed << value << "\n";
}