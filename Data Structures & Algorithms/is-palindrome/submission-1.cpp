class Solution {
public:
    bool isPalindrome(string s) {
        int beg = 0;
        int end = s.size()-1;

        while(beg<end){
            if(!isalnum(s[beg])){
                beg++;
                continue;
            }

            if(!isalnum(s[end])){
                end--;
                continue;
            }

            if(tolower(s[beg]) != tolower(s[end])) return false;
            else{
                beg++;
                end--;
            }
        }

        return true;    
    }
};
