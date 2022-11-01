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

    int t = 8 * 60 + n * 45 + (n - 1) * 5;

    cout << t / 60 << " " << t % 60;
}