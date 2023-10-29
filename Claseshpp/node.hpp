#ifndef NODE_HPP_
#define NODE_HPP_
#include <iostream>
#include <string>
#include "abbNode.hpp"
namespace eda {

class Node {
private:
trees::ABBNode* abbnode;
int dato;
std::string data;
Node* ptrNext;
public:
Node();
Node(int _dato, Node* next = nullptr);
Node(std::string _data, Node* next = nullptr);
Node(trees::ABBNode* _abbnode, Node* next = nullptr);
void setDato(int _dato);
void setData(std::string _data);
void setNext(Node* _next);
void setABBNode(trees::ABBNode* _abbnode);
int getDato();
trees::ABBNode* getABBNode();
std::string getABBNodeDato();
std::string getData();
Node* getNext();
void print();
virtual ~Node();
};

}

#endif