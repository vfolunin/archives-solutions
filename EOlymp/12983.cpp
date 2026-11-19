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

    int targetSize, size, limit, divisor;
    cin >> targetSize >> size >> limit >> divisor;

    int remainder = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        remainder = (remainder + value) % divisor;
    }

    cout << (!remainder || remainder + 1LL * (targetSize - size) * limit >= divisor ? "Yes" : "No");
}