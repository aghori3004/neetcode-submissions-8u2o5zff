class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int alice = 0; int bob = 0;
        bool aliceChance = true;
        while(!piles.empty()){
            int next; int next2next;
            if(piles[0]>=piles.back()){
                next = piles[0];
                next2next = piles.back();
                piles.erase(piles.begin());
                piles.pop_back();
            }
            else {
                next = piles.back();
                next2next = piles[0];
                piles.pop_back();
                piles.erase(piles.begin());
            }
            if(aliceChance){
                alice += next;
                bob+=next2next;
            }
            else{
                bob+= next;
                alice += next2next;
            }
        }
        return(alice>bob);
    }
};