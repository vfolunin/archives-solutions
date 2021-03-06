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

    char a[10], b[10], c[10], op;
    int res = 0;

    while (1) {
        if (scanf("%[^+-]%c%[^=]=%s", a, &op, b, c) == EOF)
            break;

        if (a[0] != '?' && b[0] != '?' && c[0] != '?') {
            int av = atoi(a), bv = atoi(b), cv = atoi(c);
            res += op == '+' && av + bv == cv || op == '-' && av - bv == cv;
        }
    }

    cout << res << "\n";
}