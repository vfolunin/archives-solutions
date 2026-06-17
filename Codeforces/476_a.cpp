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

    int size, divisor;
    cin >> size >> divisor;

    int res = (size + 1) / 2;
    while (res % divisor && res <= size)
        res++;

    cout << (res <= size ? res : -1);
}