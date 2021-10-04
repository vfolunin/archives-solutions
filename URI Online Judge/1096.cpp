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

    for (int i = 1; i <= 9; i += 2)
        for (int j = 7; j >= 5; j--)
            cout << "I=" << i << " J=" << j << "\n";
}