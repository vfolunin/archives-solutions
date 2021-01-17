#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> readMem() {
    vector<int> mem(1000);
    string line;
    for (int i = 0; getline(cin, line); i++) {
        if (line.empty())
            break;
        mem[i] = stoi(line);
    }
    return mem;
}

int process(vector<int> &mem) {
    vector<int> reg(10);

    for (int opCount = 1, ip = 0; 1; opCount++, ip++) {
        int op = mem[ip] / 100;
        int arg1 = mem[ip] / 10 % 10;
        int arg2 = mem[ip] % 10;
        
        if (op == 1) {
            return opCount;
        } else if (op == 2) {
            reg[arg1] = arg2;
        } else if (op == 3) {
            reg[arg1] = (reg[arg1] + arg2) % 1000;
        } else if (op == 4) {
            reg[arg1] = (reg[arg1] * arg2) % 1000;
        } else if (op == 5) {
            reg[arg1] = reg[arg2];
        } else if (op == 6) {
            reg[arg1] = (reg[arg1] + reg[arg2]) % 1000;
        } else if (op == 7) {
            reg[arg1] = (reg[arg1] * reg[arg2]) % 1000;
        } else if (op == 8) {
            reg[arg1] = mem[reg[arg2]];
        } else if (op == 9) {
            mem[reg[arg2]] = reg[arg1];
        } else if (op == 0) {
            if (reg[arg2])
                ip = reg[arg1] - 1;
        }
    }
}

void solve(int test) {
    vector<int> mem = readMem();
    if (test)
        cout << "\n";
    cout << process(mem) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore(2);

    for (int i = 0; i < n; i++)
        solve(i);
}