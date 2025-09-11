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

    int aLimit, bLimit, sum;
    cin >> aLimit >> bLimit >> sum;

    if (aLimit + bLimit >= sum) {
        int a = min(sum, aLimit);
        int b = sum - a;

        cout << a << " " << b;
    } else {
        cout << "Impossible";
    }
}