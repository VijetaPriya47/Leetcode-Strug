class Solution {
public:
    int maxDistance(string s, int k) {
        
        int N=0,S=0,E=0,W=0;
        int dir=0,dis=0;
        for(int i=0;i<s.size();i++){
            char x=s[i];
            if(x=='N')N++;
            else if (x=='S')S++;
            else if (x=='E')E++;
            else W++;

            dir=abs(N-S)+abs(E-W);
                dis=max(dis,min(i+1,dir+(2*k)));

            
        }
        return dis;
        
    }
};