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

    int t1, t2;
    cin >> t1 >> t2;

    cout << t1 * t1 / t2 << " " << t1 * t1 % t2 * 60 / t2;
}