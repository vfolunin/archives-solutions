class Solution {
public:
    int minOperations(string &s) {
        if (is_sorted(s.begin(), s.end()))
            return 0;
        
        if (s.size() == 2)
            return -1;

        auto [minIt, maxIt] = minmax_element(s.begin(), s.end());
        
        if (s.front() == *minIt || s.back() == *maxIt)
            return 1;
        
        if (count(s.begin(), s.end(), *maxIt) > 1 || s.front() != *maxIt ||
            count(s.begin(), s.end(), *minIt) > 1 || s.back() != *minIt)
            return 2;

        return 3;
    }
};