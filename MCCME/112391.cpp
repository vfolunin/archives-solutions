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

    double sum = 0, count = 0, value;

    while (cin >> value) {
        sum += value;
        count++;
    }

    cout << fixed << sum / count;
}