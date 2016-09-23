//Ryan Williams
//CS 3505
//A3: "Rule-of-Three and the Trie"
//Node.h 

class Node
{
 public:

  Node* nodePointers[26];
  bool isWord;
  Node();
  Node(const Node& other);
  ~Node();

  Node& operator=(Node other);
  
};
