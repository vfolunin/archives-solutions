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

    int size, divisor;
    cin >> size >> divisor;

    for (int i = 1; i < size; i++)
        cout << i << " ";

    long long sum = size * (size + 1LL) / 2;

    cout << size + (divisor - sum % divisor) % divisor << "\n";
}