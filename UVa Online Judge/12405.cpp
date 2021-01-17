#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int lineLength;
    string line;
    cin >> lineLength >> line;

    int scarecrowCount = 0, scarecrowR = -1;
    for (int i = 0; i < lineLength; i++) {
        if (line[i] == '.' && i > scarecrowR) {
            scarecrowCount++;
            scarecrowR = i + 2;
        }
    }

    cout << "Case " << test << ": " << scarecrowCount << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}