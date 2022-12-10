// The trie data structure is a tree-like data structure used to store strings.
// The trie contains a root node that stores a pointer to the root of the tree, as well as pointers to the children of the root node.
// Each node of the tree stores a character, and can contain up to 26 child nodes representing the letters of the alphabet.

#include <iostream>
#include <string>

constexpr int ALPHABET_SIZE = 26;

// A Trie node
struct TrieNode {
  struct TrieNode *children[ALPHABET_SIZE];

  // isEndOfWord is true if the node represents end of a word
  bool isEndOfWord = false;
};

// Returns new trie node (initialized to NULLs)
auto getNode() -> TrieNode * {
  auto pNode = new TrieNode;

  for (int i = 0; i < ALPHABET_SIZE; i++)
    pNode->children[i] = nullptr;

  return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(TrieNode *root, const std::string &key) {
  auto pCrawl = root;

  for (const auto &c : key) {
    const auto index = c - 'a';
    if (!pCrawl->children[index])
      pCrawl->children[index] = getNode();

    pCrawl = pCrawl->children[index];
  }

  // mark last node as leaf
  pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else false
bool search(TrieNode *root, const std::string &key) {
  auto pCrawl = root;

  for (const auto &c : key) {
    const auto index = c - 'a';
    if (!pCrawl->children[index])
      return false;

    pCrawl = pCrawl->children[index];
  }

  return (pCrawl != nullptr && pCrawl->isEndOfWord);
}

// Function to count number of strings with a given prefix
int countStringsWithGivenPrefix(struct TrieNode *root, const std::string &prefix) {
  int result = 0;
  struct TrieNode *p = root;

  for (const auto &c : prefix) {
    int index = c - 'a';
    if (!p->children[index]) 
      return 0;
    
    p = p->children[index];
  }

  dfsCount(result, p);

  return result;
}

// Helper function to traverse the trie and count all words with given prefix
void dfsCount(int &result, TrieNode *node)
{
  if (node->isEndOfWord) {
    ++result;
  }

  // Recur for all children of current node
  for (auto i = 0; i < ALPHABET_SIZE; ++i) {
    if (node->children[i]) {
      dfsCount(result, node->children[i]);
    }
  }
}

// Driver
int main() {
  // Input keys (use only 'a' through 'z'
  // and lower case)
  const std::string keys[] = {"the", "a", "there",
                              "answer", "any", "by",
                              "bye", "their"};

  const auto n = std::size(keys);

  auto root = getNode();

  // Construct trie
  for (int i = 0; i < n; i++)
    insert(root, keys[i]);

  // Search for different keys
  search(root, "the") ? std::cout << "Yes\n" : std::cout << "No\n";
  search(root, "these") ? std::cout << "Yes\n" : std::cout << "No\n";
  return 0;
}
