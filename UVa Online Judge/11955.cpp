#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<long long>> getC() {
    vector<vector<long long>> c(51, vector<long long>(51));
    for (int i = 0; i < c.size(); i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
    return c;
}

void solve(int test) {
    char a[100], b[100];
    int power;
    scanf(" (%[^+]+%[^)])^%d", a, b, &power);

    static vector<vector<long long>> c = getC();

    printf("Case %d: ", test);
    for (int pa = power, pb = 0; pb <= power; pa--, pb++) {
        if (pb)
            printf("+");

        if (c[power][pa] > 1)
            printf("%lld*", c[power][pa]);

        if (pa) {
            printf("%s", a);
            if (pa > 1)
                printf("^%d", pa);
        }

        if (pa && pb)
            printf("*");
        
        if (pb) {
            printf("%s", b);
            if (pb > 1)
                printf("^%d", pb);
        }
    }
    printf("\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);
    
    for (int test = 1; test <= n; test++)
        solve(test);
}