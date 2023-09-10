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

    long long n, d;
    cin >> n >> d;

    long long sum = 0;
    while (n >= d) {
        sum += n / d;
        n = n / d + n % d;
    }
    
    cout << sum << " " << n;
}