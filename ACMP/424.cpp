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

    long long n;
    cin >> n;

    int moves = 0;
    while (n > 1) {
        n = (n + 8) / 9;
        moves++;

        if (n > 1) {
            n = (n + 1) / 2;
            moves++;
        }
    }

    cout << (moves % 2 ? "Stan wins." : "Ollie wins.");
}