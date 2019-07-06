bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    if(a.first == b.first){
        return a.second < b.second; 
    } 
    return a.first > b.first;    
}
struct TrieNode{
    map<char, TrieNode*> children;
    bool endOfWord;
};
void convert(string &s){
    for(int i=0;i<s.size();i++){
        if(s[i]=='_'){
            s[i]=' ';
        }
    }
    return;
}
void addWord(TrieNode* root, string word){
    for(int i=0;i<word.length();i++){
        auto itr = root->children.find(word[i]);
        if(itr==root->children.end()){
            TrieNode* newNode = new TrieNode();
            newNode->endOfWord=false;
            root->children.insert(make_pair(word[i],newNode));
            root=newNode;
            continue;
        }
        root=itr->second;
    }
    root->endOfWord=true;
}
bool search(TrieNode* root, string word){
    for(int i=0;i<word.length();i++){
        auto itr = root->children.find(word[i]);
        if(itr == root->children.end()){
            return false;
        }
        root = itr->second;
    }
    return root->endOfWord;
}
vector<int> Solution::solve(string A, vector<string> &B) {
    int n = B.size();
    TrieNode* root = new TrieNode();
    root->endOfWord=false;
    convert(A);
    stringstream ss;
    ss<<A;
    string word;
    while(ss>>word){
        addWord(root, word);
    }
    int score;
    vector<pair<int,int>> rating(n);
    for(int i=0;i<n;i++){
        score = 0;
        convert(B[i]);
        ss.clear();
        ss<<B[i];
        while(ss>>word){
            if(search(root, word)){
                score++;
            }
        }
        rating[i].first = score;
        rating[i].second = i;
    }
    sort(rating.begin(),rating.end(),cmp);
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        ans[i]=rating[i].second;
    }
    return ans;
}
#include <iostream>

int main() {
  std::cout << "Hello World!\n";
}
