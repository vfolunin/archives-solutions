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

    int a, b, size;
    cin >> a >> b >> size;

    for (int i = 1; i <= size; i++)
        cout << a * i + b << " ";
}