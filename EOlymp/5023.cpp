#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int joseph(int size, int step) {
    int res = 0;
    for (int i = 1; i <= size; i++)
        res = (res + step) % i;
    return res + 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, step;
    cin >> size >> step;

    cout << joseph(size, step);
}