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

    int size;
    cin >> size;

    int limit = 1;
    for (int i = 0; i < size; i++)
        limit *= 10;

    int res = 0;
    for (int i = 0; i < limit; i++) {
        int sumL = 0, sumR = 0, sum0 = 0, sum1 = 0;
        for (int j = 0, value = i; j < size; j++, value /= 10) {
            int digit = value % 10;
            if (j < size / 2)
                sumR += digit;
            else
                sumL += digit;
            if (j % 2)
                sum1 += digit;
            else
                sum0 += digit;
        }
        res += sumL == sumR && sum0 == sum1;
    }

    cout << res;
}