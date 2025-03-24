#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int read() {
    int a, b;
    cin >> a >> b;
    return a * 100 + b;
}

void write(int n) {
    cout << n / 100 << " " << n % 100;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int a = read();
    int b = read();

    write(b - a);
}