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

    while (1) {
        int n;
        cin >> n;

        cout << n << "\n";
        cout.flush();

        if (n == 42)
            break;
    }
}