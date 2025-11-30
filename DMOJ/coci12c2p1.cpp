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

    double num, den;
    int size;
    cin >> num >> den >> size;

    double res = num / den * 1000;
    for (int i = 0; i < size; i++) {
        cin >> num >> den;

        res = min(res, num / den * 1000);
    }

    cout << fixed << res;
}