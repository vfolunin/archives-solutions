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

    int from, delta, size;
    cin >> from >> delta >> size;

    for (int i = 0; i < size; i++)
        cout << from + i * delta << " ";
}