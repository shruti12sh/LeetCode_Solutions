class Solution {
public:
    int bestClosingTime(string customers) {
        int y=0,n=0;
        for(auto i:customers){
            if(i=='Y')y++;
        }
        int mn = INT_MAX,index,penalty;
        for(int i=0;i<customers.size();i++){
            penalty = y + n;
            if(penalty<mn){
                mn = penalty;
                index = i;
            }
            if(customers[i]=='Y')y--;
            else n++;
        }
        penalty = y + n;
        if(penalty<mn){
                mn = penalty;
                index = customers.size();
        }
        return index;
    }
};