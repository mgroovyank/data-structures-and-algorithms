struct TrieNode{
    map<char, pair<TrieNode*, int>> children;
    bool endOfWord;
};
void insert(TrieNode* root, string s){
    for(int i=0;i<s.length();i++){
        auto itr = root->children.find(s[i]);
        if(itr == root->children.end()){
            TrieNode* temp = new TrieNode();
            temp->endOfWord = false;
            root->children.insert(make_pair(s[i],make_pair(temp,0)));
            root = temp;
            continue;
        }
        (itr->second).second+=1;
        root = (itr->second).first;
    }
    root->endOfWord = true;
}
string findPrefix(string s, TrieNode* root){
    string temp="";
    for(int i=0;i<s.length();i++){
        auto itr = root->children.find(s[i]);
        if((itr->second).second == 1){
            temp = temp + s[i];
            return temp;
        }else{
            temp = temp + s[i];
            root = (itr->second).first;
        }
    }
}
vector<string> Solution::prefix(vector<string> &A){
    TrieNode* root = new TrieNode();
    root->endOfWord = false;
    for(int i=0;i<A.size();i++){
        insert(root, A[i]);
    }
    vector<string> ans;
    for(int i=0;i<A.size();i++){
        ans.push_back(findPrefix(A[i], root));
    }
    return ans;
}
