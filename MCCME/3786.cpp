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

    int t1 = readTime();
    int t2 = readTime();

    int res = 0;

    while (1) {
        res += t1 / 60 == t1 % 60;
        
        if (t1 == t2)
            break;

        t1 = (t1 + 1) % (24 * 60);
    }

    cout << res;
}