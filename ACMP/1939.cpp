#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getPrimeDivisorCount(int n) {
    int res = 0;
    for (int d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            n /= d;
            res++;
        }
    }
    res += n > 1;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        cout << getPrimeDivisorCount(value) % 2 + 1 << " ";
    }
}