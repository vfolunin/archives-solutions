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

    double sum = 0;
    while (sum + 1.0 / n <= 0.5) {
        sum += 1.0 / n;
        n--;
    }

    cout << n;
}