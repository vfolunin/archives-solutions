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
 
    int size, replaceCount;
    string s;
    cin >> size >> replaceCount >> s;

    string to(26, 'a');
    for (int i = 0; i < to.size(); i++)
        to[i] += i;

    for (int i = 0; i < replaceCount; i++) {
        char a, b;
        cin >> a >> b;

        string nextTo;
        for (char c : to) {
            if (c == a)
                nextTo += b;
            else if (c == b)
                nextTo += a;
            else
                nextTo += c;
        }
        to.swap(nextTo);
    }

    for (char &c : s)
        cout << to[c - 'a'];
}