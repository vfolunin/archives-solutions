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

    long long res = 5;
    for (int i = 0; i < size - 2; i++)
        res *= 10;
    if (size > 1)
        res *= 9;

    cout << res;
}