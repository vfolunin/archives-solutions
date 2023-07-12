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

    int d, n;
    cin >> d >> n;

    n--;
    cout << n / d + 1 << " " << n % d + 1;
}