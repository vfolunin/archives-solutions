class Solution {
public:
    int maxSelectedElements(vector<int> &a) {
        map<int, int> count;
        for (int value : a)
            count[value]++;

        map<int, int> length;
        for (auto &[value, count] : count) {
            length[value + 1] = max(length[value + 1], length[value] + 1);
            if (count >= 2)
                length[value + 1] = max(length[value + 1], length[value - 1] + 2);

            length[value] = max(length[value], length[value - 1] + 1);
        }

        int maxLength = 1;
        for (auto &[value, length] : length)
            maxLength = max(maxLength, length);
        return maxLength;
    }
};