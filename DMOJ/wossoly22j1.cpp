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

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    cout << (n >= a + 4 * b + 7 * c ? "Time to go shopping!" : "You cannot afford them all.");
}