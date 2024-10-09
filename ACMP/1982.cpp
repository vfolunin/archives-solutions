#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int transform(int value) {
    int a = (value / 100) * (value / 10 % 10);
    int b = (value / 10 % 10) * (value % 10);
    if (a > b)
        swap(a, b);
    return a * (b > 9 ? 100 : 10) + b;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int value;
    cin >> value;

    int res = 100;
    while (transform(res) != value)
        res++;

    cout << res;
}