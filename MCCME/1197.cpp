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

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;

        if (a > b)
            swap(a, b);

        cout << a << " " << b << "\n";
    }
}