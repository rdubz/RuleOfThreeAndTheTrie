//Ryan Williams
//CS 3505
//A3: "Rule-of-Three and the Trie"
//Node.cpp

#include "Node.h"
#include <algorithm>

using namespace std;

Node::Node()
{
  //when the node is created all spots in its array of node Pointers must be set to nullptr's
  for(unsigned int i = 0; i < 25; i++)
    {
      nodePointers[i] = nullptr;
    }
  //also set the isWord flag to false (we only set it to true when we add word)
  isWord = false;
}

//assignemnt operator overloaded method that 
Node& Node::operator=(Node other)
{
  swap(isWord, other.isWord);
  swap(nodePointers, other.nodePointers);

  return *this;
}

//Node copy constructor that does a deep copy into a new node that wont change the original if the new node is changed
Node::Node(const Node& other)
{
  //loop through all of the array spots and create new nodes and reassign the pointers to those new nodes
    for(unsigned int i = 0; i < 26; i++)
    {
      if(nodePointers[i] != nullptr)
	{
	  Node* newNode = new Node(*other.nodePointers[i]);

	  nodePointers[i] = newNode;
	}
      else 
	{
	  nodePointers[i] = nullptr;
	}
    }
}

//Node destructor
Node::~Node()
{
  //loop through all the spots in the array and delete the pointers
  for(unsigned int i = 0; i < 25; i++)
    {
      delete nodePointers[i];
    }
}
