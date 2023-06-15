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

    int size, den;
    cin >> size >> den;

    int res = 0;
    for (int i = 0; i < size; i++) {
        int num;
        cin >> num;
        res += (num + den - 1) / den;
    }

    cout << res;
}