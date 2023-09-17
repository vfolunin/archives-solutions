class Solution {
public:
    int minimumRightShifts(vector<int> &a) {
        int minIndex = min_element(a.begin(), a.end()) - a.begin();
        rotate(a.begin(), a.begin() + minIndex, a.end());
        
        if (is_sorted(a.begin(), a.end()))
            return (a.size() - minIndex) % a.size();
        else
            return -1;
    }
};