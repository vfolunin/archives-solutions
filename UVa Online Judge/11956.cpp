#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string program;
    cin >> program;

    vector<int> mem(100);
    int i = 0;

    for (char cmd : program) {
        if (cmd == '>')
            i = (i + 1) % 100;
        else if (cmd == '<')
            i = (i + 99) % 100;
        else if (cmd == '+')
            mem[i] = (mem[i] + 1) % 256;
        else if (cmd == '-')
            mem[i] = (mem[i] + 255) % 256;
    }

    cout << "Case " << dec << test << ":";
    for (int byte : mem)
        cout << ' ' << hex << uppercase << setw(2) << setfill('0') << byte;
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}