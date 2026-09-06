struct Node {
    bool is_end; 
    Node* children[26];
    Node(): is_end(false) {
        for (int i =0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(string word) {
        Node* curr = root;
        for (auto c: word) {
            int ind = c - 'a';
            if (!curr->children[ind]) {
                curr->children[ind] = new Node();
            }
            curr = curr->children[ind];
        }
        curr->is_end = true;
    }

    bool search(string word) {
        Node* curr = root;

        for (auto c: word) {
            int ind = c - 'a';
            if (curr->children[ind] == nullptr) {
                return false;
            }
            curr = curr->children[ind];

        }
        return curr->is_end;
    }

    bool startsWith(string prefix) {
        Node* curr = root;
        for (char c: prefix) {
            int ind = c - 'a';
            if (curr->children[ind] == nullptr) {
                return false;
            }
            curr = curr->children[ind];
        }
        return true;
    }

    void clear(Node* curr) {
        if (!curr) return;


        for (int i = 0; i < 26; i++) {
            clear(curr->children[i]);
        }


        delete curr;
    }

};