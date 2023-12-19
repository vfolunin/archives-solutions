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

    double sum = 0, count = 0;
    for (double value; cin >> value; ) {
        sum += value;
        count++;
    }

    cout.precision(2);
    cout << fixed << sum / count;
}