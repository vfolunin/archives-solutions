class Solution {
public:
    int minLengthAfterRemovals(string &s) {
        int countA = count(s.begin(), s.end(), 'a');
        int countB = s.size() - countA;
        return abs(countA - countB);
    }
};