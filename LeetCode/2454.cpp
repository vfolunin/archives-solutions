class Solution {
public:
    vector<int> secondGreaterElement(vector<int> &a) {
        vector<int> firstGreater(a.size(), -1);
        vector<int> secondGreater(a.size(), -1);
        vector<int> stack;
        set<pair<int, int>> haveFirst;
        
        for (int i = 0; i < a.size(); i++) {
            while (!haveFirst.empty() && haveFirst.begin()->first < a[i]) {
                secondGreater[haveFirst.begin()->second] = a[i];
                haveFirst.erase(haveFirst.begin());
            }
            
            while (!stack.empty() && a[stack.back()] < a[i]) {
                firstGreater[stack.back()] = a[i];
                haveFirst.insert({ a[stack.back()], stack.back() });
                stack.pop_back();
            }
            stack.push_back(i);
        }
        
        return secondGreater;
    }
};