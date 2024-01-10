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

    int sum = 0, product = 1;
    for (int i = 0; i < 3; i++) {
        sum += n % 10;
        product *= n % 10;
        n /= 10;
    }

    cout << sum << " " << product;
}