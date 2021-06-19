#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    string ops, var;
    vector<long long> nums;

    while (1) {
        long long num;
        char op;

        if (!(cin >> num >> op))
            return 0;

        nums.push_back(num);
        ops.push_back(op);

        if (op == '=')
            break;
    }
    cin >> var;

    if (test)
        cout << "\n";
    while (1) {
        for (int i = 0; i < nums.size(); i++)
            cout << nums[i] << " " << ops[i] << " ";
        cout << var << "\n";

        int pos = -1;
        for (int i = ops.size() - 1; i >= 0; i--)
            if (ops[i] == '+' || ops[i] == '-')
                pos = i;
        for (int i = ops.size() - 1; i >= 0; i--)
            if (ops[i] == '*' || ops[i] == '/')
                pos = i;

        if (pos == -1)
            break;

        if (ops[pos] == '+')
            nums[pos] += nums[pos + 1];
        else if (ops[pos] == '-')
            nums[pos] -= nums[pos + 1];
        else if (ops[pos] == '*')
            nums[pos] *= nums[pos + 1];
        else
            nums[pos] /= nums[pos + 1];

        nums.erase(nums.begin() + pos + 1);
        ops.erase(pos, 1);
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}