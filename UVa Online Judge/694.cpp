#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    long long a, limit;
    cin >> a >> limit;

    if (a < 0 && limit < 0)
        return 0;

    cout << "Case " << test << ": A = " << a << ", limit = " << limit << ", ";
    
    long long terms = 1;
    while (a != 1) {
        if (a % 2)
            a = 3 * a + 1;
        else
            a /= 2;
        if (a > limit)
            break;
        terms++;
    }

    cout << "number of terms = " << terms << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}