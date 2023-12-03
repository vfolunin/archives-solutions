class Solution {
public:
    int findMinimumOperations(string &a, string &b, string &c) {
        int size = a.size();
        while (a.substr(0, size) != b.substr(0, size) || a.substr(0, size) != c.substr(0, size))
            size--;

        return size ? a.size() + b.size() + c.size() - 3 * size : -1;
    }
};