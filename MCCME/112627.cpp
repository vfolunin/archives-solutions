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

    if (size % 2) {
        cout << 0;
        return 0;
    }
    size /= 2;

    int limit = 1;
    for (int i = 0; i < size; i++)
        limit *= 10;

    vector<int> count(size * 9 + 1);
    for (int i = 0; i < limit; i++)
        count[digitSum(i)]++;

    int res = 0;
    for (int count : count)
        res += count * count;

    cout << res;
}