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

    int count, sum;
    cin >> count >> sum;

    cout << sum - count + 1 << " " << (sum + count - 1) / count << " " << sum / count;
}