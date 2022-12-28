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

    int a, b;
    cin >> a >> b;

    int stepCount = 0;
    while (1) {
        if (a > b)
            swap(a, b);

        if (!a)
            break;

        stepCount += b / a;
        b %= a;
    }

    cout << b << " " << stepCount;
}