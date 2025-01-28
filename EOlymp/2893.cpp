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

    long long volume;
    cin >> volume;

    long long resArea = 1LL << 60, resA, resB, resC;
    for (long long a = 1; a <= volume; a++) {
        if (volume % a)
            continue;

        for (long long b = a; a * b <= volume; b++) {
            if (volume % (a * b))
                continue;

            long long c = volume / (a * b);
            if (c < b)
                break;

            long long area = a * b + a * c + b * c;
            if (resArea > area) {
                resArea = area;
                resA = a;
                resB = b;
                resC = c;
            }
        }
    }

    cout << resA << " " << resB << " " << resC;
}