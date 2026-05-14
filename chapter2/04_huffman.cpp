#include<bits/stdc++.h>
using namespace std;

class HuffmanNode{
    public:
        char ch;  
        int freq;
        HuffmanNode* left;
        HuffmanNode* right;

        HuffmanNode(int c, int f) : ch(c), freq(f), left(NULL), right(NULL) {}

};

struct compare{
    bool operator()(HuffmanNode* a, HuffmanNode* b){
        return a->freq > b->freq;
    }
};

HuffmanNode* buildtree(vector<char>& chars, vector<int>& freq){
    
    priority_queue<HuffmanNode* , vector<HuffmanNode*>, compare> pq;

    int n = chars.size();
    for(int i=0;i<n;i++){
        pq.push(new HuffmanNode(chars[i], freq[i]));
    }

    while(pq.size()>1){
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();

        HuffmanNode* merged = new HuffmanNode('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }

    return pq.top();
}

void traverse(HuffmanNode* root, vector<int>& codes){
    if(!root) return;

    if(!root->left && !root->right){
        cout << root->ch << " ";
        for(int x: codes){
            cout << x;
        }
        cout << endl;
        return;
    }

    codes.push_back(0);
    traverse(root->left, codes);
    codes.pop_back();

    
    codes.push_back(1);
    traverse(root->right, codes);
    codes.pop_back();
}


int main(){
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> chars(n);
    vector<int>  freqs(n);

    cout << "Enter each character and its frequency:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "  Character " << i + 1 << " (char freq): ";
        cin >> chars[i] >> freqs[i];
    }

    HuffmanNode* root = buildtree(chars, freqs);
    vector<int> codes;
    traverse(root, codes);
}