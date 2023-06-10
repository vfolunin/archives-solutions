#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitSum(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    int halfSize = size / 2, limit = 1;
    for (int i = 0; i < halfSize; i++)
        limit *= 10;

    vector<int> count(halfSize * 9 + 1);
    for (int i = 0; i < limit; i++)
        count[digitSum(i)]++;

    long long res = 0;
    for (int count : count)
        res += 1LL * count * count;

    if (size % 2)
        res *= 10;
    res--;

    cout << res;
}