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

    for (int i = 1; 1; i++) {
        if (n * i % 10 == 0) {
            cout << n * i;
            break;
        }
    }
}