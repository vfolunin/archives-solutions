#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

void printCmds(int offset, const string &order, int varCount) {
    if (order.size() == varCount) {
        cout << string(offset, ' ') << "writeln(";
        for (int i = 0; i < varCount; i++)
            cout << order[i] << (i + 1 < varCount ? "," : ")\n");
        return;
    }

    char var = 'a' + order.size();
   
    for (int i = 0; i < order.size(); i++) {
        cout << string(offset, ' ') << (i ? "else " : "") << "if " << var << " < " << order[i] << " then\n";
        string nextOrder = order;
        nextOrder.insert(nextOrder.begin() + i, var);
        printCmds(offset + 2, nextOrder, varCount);
    }

    cout << string(offset, ' ') << "else\n";
    string nextOrder = order;
    nextOrder.insert(nextOrder.end(), var);
    printCmds(offset + 2, nextOrder, varCount);
}

void solve(int test) {
    int varCount;
    cin >> varCount;

    if (test)
        cout << "\n";

    cout << "program sort(input,output);\n";
    cout << "var\n";
    for (int i = 0; i < varCount; i++)
        cout << (char)('a' + i) << (i + 1 < varCount ? "," : " : integer;\n");
    cout << "begin\n";
    cout << "  readln(";
    for (int i = 0; i < varCount; i++)
        cout << (char)('a' + i) << (i + 1 < varCount ? "," : ");\n");
    printCmds(2, "a", varCount);
    cout << "end.\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}