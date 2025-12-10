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

    vector<double> probability(size + 1);
    probability[0] = 1;

    for (int i = 0; i < size; i++) {
        double p;
        cin >> p;

        for (int count = size; count; count--)
            probability[count] = probability[count - 1] * p + probability[count] * (1 - p);

        probability[0] *= 1 - p;
    }

    double res = 0;
    for (int i = size / 2 + 1; i <= size; i++)
        res += probability[i];

    cout.precision(10);
    cout << fixed << res;
}