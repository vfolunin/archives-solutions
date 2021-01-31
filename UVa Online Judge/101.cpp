#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Stacks {
    vector<vector<int>> stack;

    Stacks(int n) {
        stack.resize(n);
        for (int i = 0; i < n; i++)
            stack[i].push_back(i);
    }

    int stackOf(int element) {
        for (int i = 0; i < stack.size(); i++)
            if (find(stack[i].begin(), stack[i].end(), element) != stack[i].end())
                return i;
        return -1;
    }

    void free(int stackIndex, int element) {
        while (1) {
            int topElem = stack[stackIndex].back();
            if (topElem == element)
                break;
            stack[topElem].push_back(topElem);
            stack[stackIndex].pop_back();
        }
    }

    void moveOnto(int a, int b) {
        int sa = stackOf(a);
        int sb = stackOf(b);
        if (sa == sb)
            return;
        free(sa, a);
        free(sb, b);
        stack[sb].push_back(a);
        stack[sa].pop_back();
    }

    void moveOver(int a, int b) {
        int sa = stackOf(a);
        int sb = stackOf(b);
        if (sa == sb)
            return;
        free(sa, a);
        stack[sb].push_back(a);
        stack[sa].pop_back();
    }

    void pileOnto(int a, int b) {
        int sa = stackOf(a);
        int sb = stackOf(b);
        if (sa == sb)
            return;
        free(sb, b);
        auto it = find(stack[sa].begin(), stack[sa].end(), a);
        stack[sb].insert(stack[sb].end(), it, stack[sa].end());
        stack[sa].erase(it, stack[sa].end());
    }

    void pileOver(int a, int b) {
        int sa = stackOf(a);
        int sb = stackOf(b);
        if (sa == sb)
            return;
        auto it = find(stack[sa].begin(), stack[sa].end(), a);
        stack[sb].insert(stack[sb].end(), it, stack[sa].end());
        stack[sa].erase(it, stack[sa].end());
    }

    void print() {
        for (int i = 0; i < stack.size(); i++) {
            cout << i << ":";
            for (int element : stack[i])
                cout << " " << element;
            cout << "\n";
        }
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    Stacks stacks(n);

    while (1) {
        string cmd1, cmd2;
        int a, b;
        if (!(cin >> cmd1 >> a >> cmd2 >> b))
            break;

        if (cmd1 == "move" && cmd2 == "onto")
            stacks.moveOnto(a, b);
        if (cmd1 == "move" && cmd2 == "over")
            stacks.moveOver(a, b);
        if (cmd1 == "pile" && cmd2 == "onto")
            stacks.pileOnto(a, b);
        if (cmd1 == "pile" && cmd2 == "over")
            stacks.pileOver(a, b);
    }

    stacks.print();
}