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
    double x;
    cin >> size >> x;

    double res = 0;
    for (int i = size; i >= 0; i--) {
        double coeff;
        cin >> coeff;
        res = res * x + coeff;
    }

    cout << fixed << res;
}