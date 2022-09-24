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

    double sum = 0;
    for (long long i = 1; i <= n; i++)
        sum += 1.0 / (i * i);

    cout << fixed << sum;
}