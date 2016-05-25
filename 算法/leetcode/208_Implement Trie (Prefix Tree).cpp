// Implement a trie with insert, search, and startsWith methods.

// Note:
// You may assume that all inputs are consist of lowercase letters a-z.

// Subscribe to see which companies asked this question
class TrieNode {
public:
    // int count;
    TrieNode* next[26];
    bool isWord;
    // Initialize your data structure here.
    TrieNode() {
        // count = 1;
        isWord = false;
        for (int i = 0; i < 26; ++i)
        {
            next[i] = NULL;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* rootTemp = root;
        for (int i = 0;i < word.size(); i++)
        {
            int c = word[i]-'a';
            if(NULL!=rootTemp->next[c])
            {
                // rootTemp->count++;
                rootTemp = rootTemp->next[c];
                // rootTemp->count++;
            }else{
                // rootTemp->count++;
                rootTemp->next[c] = new TrieNode();
                rootTemp = rootTemp->next[c];
            }
        }
        rootTemp->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* rootTemp = find(word);
        if(NULL!=rootTemp)
        {
            return rootTemp->isWord;
        }else{
            return false;
        }
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* rootTemp = find(prefix);
        if(NULL!=rootTemp)
        {
            return true;
        }else{
            return false;
        }
    }

private:
    TrieNode* root;
    TrieNode* find(string word)
    {
        TrieNode* rootTemp = root;
        for (int i = 0;i < word.size()&&rootTemp!=NULL; i++)
        {
            int c = word[i]-'a';
            if(NULL!=rootTemp->next[c])
            {
                // rootTemp->count++;
                rootTemp = rootTemp->next[c];
                // rootTemp->count++;
            }else{
                return NULL;
            }
        }
        return rootTemp;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");