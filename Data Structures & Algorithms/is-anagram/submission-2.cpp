class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hashMap;

        if (s.size() != t.size()) return false;
        
        for(int i = 0; i < s.size(); i++){
            if (hashMap.find(s[i]) != hashMap.end()){
                hashMap[s[i]] += 1;
            } else {
                hashMap[s[i]] = 1;
            }
        }

        for (int i = 0; i < t.size(); i++){
            if (hashMap.find(t[i]) != hashMap.end()){
                if(hashMap[t[i]] == 1){
                    hashMap.erase(t[i]);
                } else {
                    hashMap[t[i]] -= 1;
                }
            } else {
                return false;
            }
        }
        if (hashMap.empty()){
            return true;
        } else {
            return false;
        }
    }
};
