// link: https://www.codingninjas.com/studio/problems/0-1-knapsack_8230801?challengeSlug=striver-sde-challenge


// bottom-up approach
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// iterative solution with tabulation (BOTTOM-UP)
	// space optimized as we are using result of previous row
	vector<int> curr(w+1,0);
	vector<int> prev(w+1,0);
	for(int W=weights[0];W<=w;W++) {
		if(weights[0]<=W) prev[W]=values[0];
	}
	for(int i=1;i<n;i++) {
		for(int j=0;j<=w;j++) {
			int result_not_take = prev[j];
			int result_take= 0;
			if(j>=weights[i]) result_take=values[i]+prev[j-weights[i]];
			curr[j] =max(result_take,result_not_take);
		}
		prev=curr;
	}
	return curr[w];
}
