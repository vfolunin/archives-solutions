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

    int sum;
    cin >> sum;

    int res = 0;
    for (int a = 1; 4 * a <= sum; a++)
        for (int b = a; a + 3 * b <= sum; b++)
            for (int c = b; a + b + 2 * c <= sum; c++)
                res++;

    cout << res;
}