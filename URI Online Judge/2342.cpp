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

    long long limit, a, b;
    char op;
    cin >> limit >> a >> op >> b;

    long long res = op == '+' ? a + b : a * b;

    cout << (res <= limit ? "OK\n" : "OVERFLOW\n");
}