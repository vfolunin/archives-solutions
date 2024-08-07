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

    long long limit, index;
    cin >> limit >> index;

    if (index * index <= limit)
        cout << index * 2 - 1;
    else
        cout << -1;
}