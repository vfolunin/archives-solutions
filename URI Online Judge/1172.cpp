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

    for (int i = 0; i < 10; i++) {
        int x;
        cin >> x;

        if (x <= 0)
            x = 1;

        cout << "X[" << i << "] = " << x << "\n";
    }
}