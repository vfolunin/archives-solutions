#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool readSmile(istream &in) {
    char c = in.get();
    if (c != ':' && c != ';')
        return 0;

    while (in.peek() == '-')
        in.get();

    return in.peek() == '(' || in.peek() == ')' || in.peek() == '[' || in.peek() == ']';
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int res = 0;
    while (cin.peek() != EOF)
        res += readSmile(cin);

    cout << res;
}