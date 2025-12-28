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

    unsigned long long a, b, c;
    cin >> a >> b >> c;

    cout << (a + b + c) % 42069900169420;
}