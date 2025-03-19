#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int readTime() {
    int h, m;
    cin >> h >> m;

    return h * 60 + m;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l = readTime();
    int r = readTime();

    int res = 0;
    for (int i = l; i <= r; i++) {
        if (i % 60 == 0)
            res += i / 60;
        else if (i % 60 == 30)
            res++;
    }

    cout << res;
}