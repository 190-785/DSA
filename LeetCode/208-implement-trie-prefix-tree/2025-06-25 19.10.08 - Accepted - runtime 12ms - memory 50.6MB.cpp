class Trie {
private:
    struct Node {
        bool isWord;
        Node* child[26];
        Node() {
            isWord = false;
            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };
    Node* root;

public:
    Trie() { root = new Node(); }

    void insert(string word) {
        Node* curr = root;
        for (char c : word) {
            if (curr->child[c - 'a'] == nullptr) {
                curr->child[c - 'a'] = new Node();
            }
            curr = curr->child[c - 'a'];
        }
        curr->isWord = true;
    }

    bool search(string word) {
        Node* curr = root;
        for (char c : word) {
            if (curr->child[c - 'a'] == nullptr)
                return false;
            curr = curr->child[c - 'a'];
        }
        if (curr->isWord)
            return true;
        return false;
    }

    bool startsWith(string prefix) {
        Node* curr = root;
        for (char c : prefix) {
            if (curr->child[c - 'a'] == nullptr)
                return false;
            curr = curr->child[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */