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

    int sum;
    cin >> sum;

    cout << sum / 2 << "\n";
    for (int i = 0; i < sum / 2; i++)
        cout << (i ? 2 : 2 + sum % 2) << " ";
}