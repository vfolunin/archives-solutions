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

    unsigned long long vertexCount;
    cin >> vertexCount;

    cout << vertexCount * (vertexCount - 1) / 2;
}