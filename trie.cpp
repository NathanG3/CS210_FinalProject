#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct TrieNode {
    bool isEndOfWord;
    unordered_map<char, TrieNode*> children;
    unordered_map<string, string> cities;

    TrieNode() : isEndOfWord(false) {}
};

class NameTrie {
private:
    TrieNode* root;

public:
    NameTrie() {
        root = new TrieNode();
    }

    void insert(const string& city, const string& countryCode, const string& population) {
        TrieNode* node = root;
        for (char c : city) {
            c = tolower(c); // Case-insensitive
            if (node->children.count(c) == 0)
                node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->isEndOfWord = true;
        node->cities[countryCode] = population;
    }

    bool search(const string& city, const string& countryCode, const string& population) {
        TrieNode* node = root;
        for (char c : city) {
            c = tolower(c);
            if (node->children.count(c) == 0)
                return false;
            node = node->children[c];
        }
        if (node->isEndOfWord && node->cities.count(countryCode))
          return true;

        return false;

    }

    void printTrie(TrieNode* node = nullptr, string prefix = "", string indent = "") {
        if (!node) node = root;
        if (node->isEndOfWord)
            cout << indent << "'" << prefix << "' (END)" << endl;
        for (auto& [ch, child] : node->children) {
            printTrie(child, prefix + ch, indent + "  ");
        }
    }
};


