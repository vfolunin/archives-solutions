#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int readTime() {
    int hours, minutes;
    char colon;
    cin >> hours >> colon >> minutes;

    return hours * 60 + minutes;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int a = readTime();
    int b = readTime();

    if (a > b)
        b += 24 * 60;

    cout << b - a;
}