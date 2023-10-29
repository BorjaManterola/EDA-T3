#ifndef STACK_HPP_
#define STACK_HPP_

#include "node.hpp"
#include "abbNode.hpp"

namespace eda {

class Stack {
private:
Node* head;
public:
Stack();
void push(std::string val);
void push(trees::ABBNode* val);
void push(Node* node);
void pop();
Node* top();
bool isEmpty();
void clear();
virtual ~Stack();
};

} /* namespace eda */

#endif