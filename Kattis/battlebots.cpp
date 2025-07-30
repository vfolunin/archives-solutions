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

    long double size;
    cin >> size;

    int res = 1;
    while (size > 1) {
        size /= 2;
        res++;
    }

    cout << res;
}