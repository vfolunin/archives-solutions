#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    long long sum = n * (n + 1) / 2;

    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        sum -= x;
    }
    
    cout << sum;
}