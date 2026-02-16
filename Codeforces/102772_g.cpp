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

    double ab, ac, bc;
    cin >> ab >> ac >> bc;

    cout << fixed << ab * ac / bc << "\n";
    cout << ab * bc / ac << "\n";
    cout << ac * bc / ab;
}