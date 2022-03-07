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

    int bitCount;
    cin >> bitCount;

    long long n = 0;
    
    for (int i = 0; i < bitCount; i++) {
        char bit;
        cin >> bit;
        n = n * 2 + (bit == 'O');
    }

    cout << n;
}