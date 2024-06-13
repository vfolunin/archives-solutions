#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int a, b, size;
    cin >> a >> b >> size;

    if (!size)
        return 0;

    cout << "Case " << test << ": " << size / b * a + min(size % b, a) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}