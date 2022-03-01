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

    double limit, n;
    int type;
    cin >> limit >> n >> type;

    double ops;
    if (type == 1) {
        ops = 1;
        for (double i = 2; i <= min(n, 20.0); i++)
            ops *= i;
    } else if (type == 2) {
        ops = pow(2, n);
    } else if (type == 3) {
        ops = pow(n, 4);
    } else if (type == 4) {
        ops = pow(n, 3);
    } else if (type == 5) {
        ops = pow(n, 2);
    } else if (type == 6) {
        ops = n * log(n) / log(2);
    } else {
        ops = n;
    }

    cout << (ops <= limit ? "AC" : "TLE");
}