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

    int n, a, b, z;
    cin >> n >> a >> b >> z;

    int ab = a + b - (n - z);

    cout << ab << " " << a - ab << " " << b - ab;
}