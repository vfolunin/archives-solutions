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

    const int N = 1e8, R = 1e4;
    static bool isComposite[N];
    int primeCount = 0;

    for (int i = 2; i < N; i++) {
        if (isComposite[i])
            continue;

        if (primeCount++ % 100 == 0)
            printf("%d\n", i);

        if (i < R)
            for (int j = i * i; j < N; j += i)
                isComposite[j] = 1;
    }
}