class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> bracketMap;
        bracketMap['('] = ')'; bracketMap[')'] = '(';
        bracketMap['{'] = '}'; bracketMap['}'] = '{';
        bracketMap['['] = ']'; bracketMap[']'] = '[';

        unordered_set<char> openBrackets = {'(', '[', '{'};
        unordered_set<char> closedBrackets = {')', ']', '}'};
        
        stack<char> bStack;
        for(char c : s){
            if(openBrackets.count(c)){
                bStack.push(c);
            }
            else if(closedBrackets.count(c)){
                if(bStack.empty()) return false;
                char front = bStack.top();
                bStack.pop();
                if(bracketMap[c] == front) continue;
                else return false;
            }
            else return false;
        }
        if(bStack.empty()) return true;
        return false;
    }
};
