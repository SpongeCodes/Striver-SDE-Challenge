// Leetcode Super Egg Drop - great dp problem
// Same as cut logs O(N*K) approach where we utilize the fact that minimum value of max(T1,T2) 
// where T1=f(n-x,k) , T2=f(x-1,k-1) is achieved at higher x (1<=x<N) if N increases  
// for constant 'k', thus keep x pointer which finds threshold x and only iterate over N once for each 'k'
class Solution {
public:
    int superEggDrop(int k, int n) {
        // use iterative approach with bottom-up
        vector<int> prev(n+1,0); // represents dp(1 egg,i floors)
        //Base case
        for(int floors=0;floors<=n;floors++) prev[floors] = floors;
        
        for(int eggs=2;eggs<=k;eggs++) {
            // curr is for current number of eggs
            vector<int> curr(n+1,0);
            int x=1; // threshold x value
            for(int i=1;i<=n;i++) {
                // iterate over all possible floor range values 
                // for current egg count
                while(x<i && max(curr[i-x],prev[x-1]) > max(curr[i-x-1],prev[x])) {
                    x++;
                }
                curr[i]=1+max(curr[i-x],prev[x-1]);
            }
            prev=curr;
        }
        return prev[n];
    }
};
