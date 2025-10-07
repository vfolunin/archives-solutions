#include <iostream>
#include <algorithm>
#include <cmath>
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

    double sum = 0;
    for (int i = 0; i < size; i++) {
        double value;
        cin >> value;

        sum += pow(value, 3);
    }

    cout << fixed << cbrt(sum);
}