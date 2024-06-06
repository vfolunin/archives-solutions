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

    int n, a, b, c, ab, ac, bc;
    cin >> n >> a >> b >> c >> ab >> bc >> ac;

    cout << n - a - b - c + ab + bc + ac;
}