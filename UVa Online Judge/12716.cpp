#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const int N = 3e7 + 1;
const int N2 = N / 2;
int res[N];

void prepare() {
    for (int b = 1; b <= N2; b++)
        for (int a = b * 2; a < N; a += b)
            if (a - b == (a ^ b))
                res[a]++;

    for (int i = 2; i < N; i++)
        res[i] += res[i - 1];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    prepare();

    int n;
    scanf("%d", &n);

    for (int test = 1; test <= n; test++) {
        int i;
        scanf("%d", &i);
        printf("Case %d: %d\n", test, res[i]);
    }
}