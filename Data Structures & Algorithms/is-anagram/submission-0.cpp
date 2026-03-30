class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_multiset<char> hashSet;
        for (int i = 0; i<s.size(); i++){
            hashSet.insert(s[i]);
        }
        for (int i = 0; i<t.size(); i++){
            auto it = hashSet.find(t[i]);
            if(it != hashSet.end()){
                hashSet.erase(it);
            }
            else return false;
        }
        return true;
    }
};
