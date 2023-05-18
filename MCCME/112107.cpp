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

    int limit;
    cin >> limit;

    int sum = 0;
    for (int i = 1; sum + i * (i + 1) <= limit; i++)
        sum += i * (i + 1);

    cout << sum;
}