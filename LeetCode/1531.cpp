#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

class Solution {
    int getLen(int count) {
        return count == 1 ? 1 : 1 + to_string(count).size();
    }

    int getLen(string &s, int l, int r) {
        vector<pair<char, int>> parts;
        for (int i = l; i <= r; i++) {
            if (parts.empty() || parts.back().first != s[i])
                parts.push_back({ s[i], 1 });
            else
                parts.back().second++;
        }

        int size = 0;
        for (auto &[c, count] : parts)
            size += getLen(count);
        return size;
    }

    int getSimpleLen(string &s, int l, int r) {
        vector<int> count(26);
        for (int i = l; i <= r; i++)
            count[s[i] - 'a']++;
        return getLen(*max_element(count.begin(), count.end()));
    }

    int getRemoves(string &s, int l, int r) {
        vector<int> count(26);
        for (int i = l; i <= r; i++)
            count[s[i] - 'a']++;
        return r - l + 1 - *max_element(count.begin(), count.end());
    }

    int rec(int size, int removes, string &s, vector<vector<int>> &memo) {
        int &res = memo[size][removes];
        if (res != -1)
            return res;

        if (!size)
            return res = 0;
        if (!removes)
            return res = getLen(s, 0, size - 1);

        res = 1e9;
        for (int partSize = 1; partSize <= size; partSize++) {
            int partLen = getSimpleLen(s, size - partSize, size - 1);
            int partRemoves = getRemoves(s, size - partSize, size - 1);
            if (partRemoves > removes)
                break;
            res = min(res, rec(size - partSize, removes - partRemoves, s, memo) + partLen);
        }
        return res;
    }

public:
    int getLengthOfOptimalCompression(string s, int removes) {
        vector<vector<int>> memo(s.size() + 1, vector<int>(removes + 1, -1));
        return rec(s.size(), removes, s, memo);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Solution s;
    cout << s.getLengthOfOptimalCompression("denammdfegkjechilepbckbhkahhhhpkoigjdnboblaoejdjhhgcngpicimbpnhjmafbajmjhffhkeolefpimjhahcnnndjnmknd", 42);
}