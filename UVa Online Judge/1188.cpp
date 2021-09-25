#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double getF1(int vertexCount) {
    double power = 1, num = 0, den = 0;
    for (int i = 1; i <= vertexCount; i++) {
        power *= vertexCount - 1;
        num += power * i;
        den += power;
    }
    return num / den;
}

double getF2(int vertexCount) {
    double power = 1, num = 0, den = 0;
    for (int i = 1; i < vertexCount; i++) {
        power *= vertexCount - i;
        num += power * i;
        den += power;
    }
    return num / den;
}

double getF3(int vertexCount) {
    double power = 1, num = 0, den = 0;
    for (int i = 2; i < vertexCount; i++) {
        power *= vertexCount - i;
        num += power * (i + 1);
        den += power;
    }
    return num / den;
}

bool solve() {
    int vertexCount;
    cin >> vertexCount;

    if (!vertexCount)
        return 0;

    cout.precision(4);
    cout << fixed << getF1(vertexCount) << " ";
    cout << fixed << getF2(vertexCount) << " ";
    cout << fixed << getF3(vertexCount) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}