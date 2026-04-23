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

    int size, count;
    cin >> size >> count;

    for (int i = 0; count >= i + 1; i = (i + 1) % size)
        count -= i + 1;

    cout << count;
}