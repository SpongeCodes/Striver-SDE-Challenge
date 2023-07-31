// link : https://www.codingninjas.com/studio/problems/maximum-xor-of-two-numbers-in-an-array_8230852?challengeSlug=striver-sde-challenge
#include <bits/stdc++.h>

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
            int link = (num&(1<<i))? 1:0;
            if(!curr->getNext(link))
                curr->put(link);
            curr = curr->getNext(link);
        }
    }

    int getMax(int number) {
        // iterate over the trie 
        // take opposite bit of current bit if present
        int res=0;
        Node *curr = root;
        for (int i = 31; i >= 0; --i) {
          int bit = (number & (1 << i)) > 0 ? 1 : 0;
          if (curr->getNext(1 - bit)) {
            res += 1<<i;
            curr=curr->getNext(1-bit);
          }
          else curr=curr->getNext(bit);
        }
        
        return res;
    }
};

int maximumXor(vector<int> A)
{
    Trie *trie = new Trie();
    for(int &a: A)
        trie->insert(a);
    int res=0;
    for(int &a: A)
        res = max(res,trie->getMax(a));
    return res;
}
