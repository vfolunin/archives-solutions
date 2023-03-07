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

    long long value = 0, sum = 0;
    char c;

    while (cin.get(c)) {
        if (isdigit(c)) {
            value = value * 10 + c - '0';
        } else {
            sum += value;
            value = 0;
        }
    }
    sum += value;

    cout << sum;
}