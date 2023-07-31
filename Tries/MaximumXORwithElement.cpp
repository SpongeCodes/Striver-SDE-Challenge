#include <bits/stdc++.h>

// link: https://www.codingninjas.com/studio/problems/maximum-xor-with-an-element-from-array_8230839?challengeSlug=striver-sde-challenge

struct Node {
    Node *links[2];

    Node* getNext(int i) {
        return links[i];
    }

    void put(int i) {
        links[i] = new Node();
    }

};

struct Trie {
    private:
    Node *root;
    public:
    Trie() {
        root = new Node();
    }
    void insert(int num) {
        Node *curr = root;
        for(int i=31;i>=0;--i) {
            int link = (num>>i)&1;
            if(!curr->getNext(link))
                curr->put(link);
            curr = curr->getNext(link);
        }
    }

    int getMax(int number) {
        // iterate over the trie 
        // take opposite bit of current bit if present
		// biggerElement should hav first differing bit with array element
		// as set bit
        if(!root->getNext(0) && !root->getNext(1)) return -1;
        int res=0;
        Node *curr = root;
        for (int i = 31; i >= 0; --i) {
          int bit = (number>>i) & 1 ;
		  int oppositeBit = 1-bit;
          if(curr->getNext(oppositeBit)){
            res+=1<<i;
            curr=curr->getNext(oppositeBit);
          }
          else curr=curr->getNext(bit);
        }
        return res;
    }
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	int n= queries.size();
    int len = arr.size();
    vector<int> res(n);
	Trie *trie = new Trie();
	vector<pair<pair<int,int>,int>> q;
    for(int i=0;i<n;i++) {
      q.push_back({{queries[i][1],queries[i][0]},i});
    }
    sort(arr.begin(),arr.end());
    sort(q.begin(),q.end());
    // use offline queries to build trie with non-greater elements than ai
    // and store answer in position
	int j=0;
	for(int i=0;i<n;i++) {
        int ai= q[i].first.first;
        int xi=q[i].first.second;
        while(j<len && arr[j]<=ai) {
            trie->insert(arr[j]);
            j++;
        }
        if(j==0) {
            res[q[i].second]=-1;
            continue; 
        }
		int ans= trie->getMax(xi);
		res[q[i].second] = ans;
	}
    
    return res;
}
