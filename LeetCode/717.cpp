class Solution {
public:
    bool isOneBitCharacter(vector<int> &bits) {
        int i = 0;
        while (i + 1 < bits.size())
            i += bits[i] + 1;
        return i + 1 == bits.size();
    }
};