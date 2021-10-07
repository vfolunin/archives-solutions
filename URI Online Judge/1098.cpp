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

    for (double i = 0; i <= 2; i += 0.2)
        for (int j = 1; j <= 3; j++)
            cout << "I=" << i << " J=" << i + j << "\n";
}