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
 
    int capacity, time, count;
    cin >> capacity >> time >> count;

    if (count <= capacity)
        cout << 2 * time;
    else
        cout << (2 * count + capacity - 1) / capacity * time;
}