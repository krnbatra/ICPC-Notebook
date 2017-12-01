/* trie 2d */
const int MAXN = 500005;
int sz = 0;

int trie[26][MAXN];
int end1[MAXN];

void insert(string s){
    int v = 0;
    for(int i = 0; i < s.size(); i++){
        int c = s[i]-'a';
        if(trie[c][v] == -1)
            trie[c][v] = ++sz;
        v = trie[c][v];
    }
    ++end1[v];
}

bool searchPrefix(string prefix){
    int v = 0;
    int i;
    for(i = 0; i < prefix.size(); i++){
        int c = prefix[i]-'a';
        if(trie[c][v] == -1)
            return false;
        v = trie[c][v];
    }
    return i == prefix.size();
}


bool searchWord(string prefix){
    int v = 0;
    int i;
    for(i = 0; i < prefix.size(); i++){
        int c = prefix[i]-'a';
        if(trie[c][v] == -1)
            return false;
        v = trie[c][v];
    }
    return end1[v] > 0;
}
int main(){
    memset(trie, -1, sizeof trie);
    insert("abc");
    cout << end1[3] << endl;
}