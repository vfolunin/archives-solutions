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

    int num, den;
    cin >> num >> den;

    int quotient = num / den, remainder = num % den;
    if (remainder < 0) {
        quotient += den > 0 ? -1 : 1;
        remainder += den > 0 ? den : -den;
    }

    cout << quotient << " " << remainder;
}