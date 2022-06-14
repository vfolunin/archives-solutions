class Solution {
public:
    int numUniqueEmails(vector<string> &emails) {
        unordered_set<string> addresses;
        
        for (const string &email : emails) {
            string address;
            int i = 0;
            
            for ( ; email[i] != '@' && email[i] != '+'; i++)
                if (email[i] != '.')
                    address += email[i];
            
            address += email.substr(email.find('@', i));
            addresses.insert(address);
        }
        
        return addresses.size();
    }
};