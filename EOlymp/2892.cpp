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

    double resA = 0, resB = 0;
    for (int i = 0; i < size; i++) {
        double value;
        cin >> value;

        resA += value;
        resB += 1 / value;
    }

    cout.precision(10);
    cout << fixed << resA + resB;
}