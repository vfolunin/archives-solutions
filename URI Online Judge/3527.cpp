#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int readTime() {
    int hours, minutes;
    cin >> hours >> minutes;

    return hours * 60 + minutes;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a = readTime();
    int b = readTime();
    int c = readTime();
    int d = readTime();

    cout << (max({ b, c, d }) <= 7 * 60 || max({ b, c, d }) < a ? "LIVRE\n" : "FUMO\n");
}