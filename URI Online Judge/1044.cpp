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

    int a, b;
    cin >> a >> b;

    if (b % a == 0 || a % b == 0)
        cout << "Sao Multiplos\n";
    else
        cout << "Nao sao Multiplos\n";
}