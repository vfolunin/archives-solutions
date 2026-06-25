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

    int den, size;
    cin >> den >> size;

    long long num = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        num += value;
    }

    cout << (num + den - 1) / den;
}