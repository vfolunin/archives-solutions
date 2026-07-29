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

    int res = 1;
    for (int i = 0; i < size - 1; i++)
        res = res * 3 % 1000003;

    cout << res;
}