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

    int power, value;
    cin >> power >> value;

    long long res = 1;
    for (int i = 0; i < power; i++)
        res *= value;

    cout << res;
}