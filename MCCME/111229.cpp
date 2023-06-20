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

    long long countA, countB, priceA, priceB;
    cin >> countA >> countB >> priceA >> priceB;

    cout << max(countA * priceA, countB * priceB);
}