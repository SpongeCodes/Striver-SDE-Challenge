#include<bits/stdc++.h>
// implementation of cut logs problem (egg drop on leetcode)

/** Problem statement: link: https://www.codingninjas.com/studio/problems/cut-logs_8230782?challengeSlug=striver-sde-challenge&leftPanelTab=0
  K axes, N logs can be cut at a time. How many minimum tries to determine log cutting threshold?
*/

int cutLogs(int k, int n)
{
   vector<int> prev(n+1);
   // if only one axe is remaining worst case is all axe uses are tested
   for(int totalAxes=0;totalAxes<=n;totalAxes++) prev[totalAxes]=totalAxes;
   
   for(int axes=2;axes<=k;axes++){
       vector<int> curr(n+1,0);
       int x = 1;
       for(int i=1;i<=n;i++) {
            while (x < i && max(prev[x-1], curr[i-x]) > max(prev[x], curr[i-x-1]))
                    x++;

            // The final answer happens at this x.
            curr[i] = 1 + max(prev[x-1], curr[i-x]);
           
       }
       prev=curr;
   }
   return prev[n];
}
