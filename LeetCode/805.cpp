class Solution {
public:
    bool splitArraySameAverage(vector<int> &a) {
        vector<unordered_set<int>> sums(a.size() / 2 + 1);
        sums[0].insert(0);
        
        for (int value : a)
            for (int size = a.size() / 2; size >= 1; size--)
                for (int prevSum : sums[size - 1])
                    sums[size].insert(prevSum + value);
        
        int sum = accumulate(a.cbegin(), a.cend(), 0);
        
        for (int size = 1; size <= a.size() / 2; size++)
            if (sum * size % a.size() == 0 && sums[size].count(sum * size / a.size()))
                return 1;

        return 0;
    }
};
