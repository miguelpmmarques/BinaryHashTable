#include <iostream>
#include <string.h>
#include <cmath>
#include <stdio.h>
#define TABLESIZE 143
using namespace std;

typedef struct Node * Pnode;

struct Node{
  Pnode right;
  Pnode left;
  int value;
  int key;
};

class BINARYtree{
public:
  BINARYtree(){}
  void insertNode(int value, int key);
  void printTree();
  void findNode(int key);
private:
  Pnode root = NULL;
  void printTreeRecursive(Pnode actNode);
  void recursiveInsert(Pnode actNode,Pnode newNode);
  void findNodeRecursive(Pnode actNode,int lookNode);
};

class HashTable{
public:
  HashTable(){}
  void insertNode(int value, int key);
  void findNode(int key);

private:
  BINARYtree hash[TABLESIZE];
  int hashFunction(int key);
};

int main() {
  HashTable myHash;
  cout << "WELCOME TO MY HASH TABLE WITH BINARY CHAINING" << endl;
  myHash.insertNode(332,2330);
  myHash.insertNode(83,344);
  myHash.insertNode(2,90);
  myHash.insertNode(12,213);
  myHash.insertNode(22,9);
  myHash.findNode(213);
  myHash.findNode(345);
  myHash.findNode(9);
  return 0;
}

void HashTable::insertNode(int value, int key){
  int index = this->hashFunction(key);
  this->hash[index].insertNode(value,key);
}

void HashTable::findNode(int key){
  int index = this->hashFunction(abs(key));
  this->hash[index].findNode(key);
}

int HashTable::hashFunction(int key){
  return (key*(key+11))%TABLESIZE;

}

void BINARYtree::findNodeRecursive(Pnode actNode,int lookNode){
  if (actNode->key > lookNode) {
    if (actNode->left) {
      this->findNodeRecursive(actNode->left,lookNode);
    }
    else{
      cout << "[NOT FOUND] Key - " << lookNode<< endl;
    }

  }else if (actNode->key < lookNode) {
    if (actNode->right) {
      this->findNodeRecursive(actNode->right,lookNode);
    }
    else{
      cout << "[NOT FOUND] Key - " << lookNode<< endl;
    }
  }else{
    cout << "[FOUND] Key - " << actNode->key <<" Value - " << actNode->value << endl;
  }
}
void BINARYtree::findNode(int key){
  if (this->root != NULL) {
    this->findNodeRecursive(this->root,key);
  }
  else{
    cout << "[NOT FOUND] Key - " << key<< endl;
  }
}
void BINARYtree::printTreeRecursive(Pnode actNode){
  if (actNode != NULL)
  {
    this->printTreeRecursive(actNode->left);
    cout << "Key - " << actNode->key <<" Value - " << actNode->value << endl;
    this->printTreeRecursive(actNode->right);
  }

}
void BINARYtree::printTree(){

  if (this->root == NULL) {
    cout << "The Tree is empty"<<endl;
  }
  else{
    this->printTreeRecursive(this->root);
  }
}
void BINARYtree::recursiveInsert(Pnode actNode,Pnode newNode){
  if (actNode->key > newNode->key) {
    if (actNode->left) {
      this->recursiveInsert(actNode->left,newNode);
    }
    else{
      actNode->left = newNode;
    }

  }else if (actNode->key < newNode->key) {
    if (actNode->right) {
      this->recursiveInsert(actNode->right,newNode);
    }
    else{
      actNode->right = newNode;
    }
  }else{
    cout << "[FOUND] Key - " << actNode->key <<" Value - " << actNode->value << endl;
  }

}
void BINARYtree::insertNode(int value, int key){

  Pnode newNode = (Pnode)malloc(sizeof(Node));
  newNode-> value = value;
  newNode->key = key;
  newNode->right = NULL;
  newNode->left = NULL;
  if (this->root == NULL){
    this->root = newNode;
  }
  else{
    this->recursiveInsert(this->root,newNode);
  }
}
