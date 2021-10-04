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

    for (int i = 1, j = 60; j >= 0; i += 3, j -= 5)
        cout << "I=" << i << " J=" << j << "\n";
}