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

    long long res = 9;
    for (int i = 1; i < size; i++)
        res *= 10 - i;

    cout << res;
}