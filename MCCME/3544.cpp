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

    for (int i = 10; i < 100; i++) {
        int a = i / 10, b = i % 10;
        if (i == 2 * a * b)
            cout << i << " ";
    }
}