#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    long long k5, k6;
    if (!(cin >> k5 >> k6))
        return 0;

    long long edgeCount = (k5 * 5 + k6 * 6) / 2;
    long long vertexCount = edgeCount + 2 - (k5 + k6);

    cout << "Molecula #" << test << ".:.\n";
    cout << "Possui " << vertexCount << " atomos e " << edgeCount << " ligacoes\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}