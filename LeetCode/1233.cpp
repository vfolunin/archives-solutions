class Solution {
public:
    vector<string> removeSubfolders(vector<string> &folders) {
        sort(folders.begin(), folders.end());
        
        vector<string> stack;
        for (string &folder : folders)
            if (stack.empty() || folder.size() <= stack.back().size() + 1 ||
                folder.substr(0, stack.back().size() + 1) != stack.back() + "/")
                stack.push_back(folder);
        
        return stack;
    }
};