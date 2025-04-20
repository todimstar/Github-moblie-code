class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> cha(n+1,0);
        for(vector<int> i : bookings){
            cha[i[0]-1]+=i[2];
            cha[i[1]]-=i[2];
        }
        vector<int> jg(n,0);
        jg[0] = cha[0];
        for(int i=1;i<n;i++){
            jg[i]=jg[i-1]+cha[i];
        }
        return jg;
    }
};