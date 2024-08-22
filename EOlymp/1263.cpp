#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int read() {
    int ab, bc, ac;
    cin >> ab >> bc >> ac;

    for (int a = 0; a <= ab; a++) {
        int b = ab - a;
        int c = ac - a;
        if (0 <= b && 0 <= c && b + c == bc)
            return a + b + c;
    }

    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int a = read();
    int b = read();

    if (a == -1 || b == -1)
        cout << "Drogba Wins";
    else if (a > b)
        cout << "Messi Wins";
    else if (a == b)
        cout << "Draw...";
    else
        cout << "Ronaldo Wins";
}