class Node{
public:
    vector<Node*> children;
    bool word;
    Node():children(26,nullptr),word(false) {}
};
class WordDictionary {
public:
    Node* root;
    WordDictionary():root(new Node()) {}
    
    void addWord(string word) {
        Node* curr=root;
        for(char c:word){
            if(curr->children[c-'a']==nullptr){
                curr->children[c-'a']=new Node();
            }
            curr=curr->children[c-'a'];
        }
        curr->word=true;
    }
    
    bool search(string word) {
        return dfs(word,0,root);
    }
private:
    bool dfs(string word,int j,Node* root){
        Node* curr=root;
        for(int i=j;i<word.size();i++){
            char c=word[i];
            if(c=='.'){
                for(Node* child:curr->children){
                    if(child!=nullptr && dfs(word,i+1,child)) return true;
                }
                return false;
            }else{
                if(curr->children[c-'a']==nullptr) return false;
                curr=curr->children[c-'a'];
            }
        }
        return curr->word;
    }
};
