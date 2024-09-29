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

    int offsetA, modA, offsetB, modB;
    cin >> offsetA >> modA >> offsetB >> modB;

    int res = 0;
    while ((res + offsetA) % modA || (res + offsetB) % modB)
        res++;

    cout << res;
}