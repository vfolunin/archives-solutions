#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ask(long long i) {
    cout << "buf[" << i << "]" << endl;

    int res;
    cin >> res;

    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    long long l = 0, r = 1;
    while (ask(r)) {
        l = r;
        r *= 2;
    }

    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (ask(m))
            l = m;
        else
            r = m;
    }

    cout << "strlen(buf) = " << r << endl;
}