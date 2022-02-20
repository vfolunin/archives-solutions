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

    int n;
    cin >> n;

    int missed = 1, output = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        while (missed < x) {
            cout << missed++ << "\n";
            output = 1;
        }
        missed = x + 1;
    }

    if (!output)
        cout << "good job";
}