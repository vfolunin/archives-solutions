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

    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    long long res = a * c;
    if (a == 1 && c == 1)
        res = max(b, d);
    else if (a == 1)
        res = d;
    else if (c == 1)
        res = b;

    while (1) {
        bool found = 0;
        for (long long i = 1; !found && i * i <= res; i++) {
            if (res % i)
                continue;
            long long j = res / i;
            found |= (a <= i && i <= b && c <= j && j <= d);
            found |= (a <= j && j <= b && c <= i && i <= d);
        }
        if (!found)
            break;
        res++;
    }

    cout << res;
}