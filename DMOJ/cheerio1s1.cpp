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

    int size, dist;
    cin >> size >> dist;

    long long res = 0;
    int prevPos = 0;
    for (int i = 0; i < size; i++) {
        int pos, red, green;
        cin >> pos >> red >> green;

        res += pos - prevPos;
        if (res % (red + green) < red)
            res += red - res % (red + green);

        prevPos = pos;
    }
    res += dist - prevPos;

    cout << res;
}