#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int roundCount;
    cin >> roundCount;

    if (!roundCount)
        return 0;

    int aSum = 0, bSum = 0;
    for (int i = 0; i < roundCount; i++) {
        int a, b;
        cin >> a >> b;
        aSum += a;
        bSum += b;
    }

    cout << "Teste " << test << "\n";
    cout << (aSum > bSum ? "Aldo\n\n" : "Beto\n\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}