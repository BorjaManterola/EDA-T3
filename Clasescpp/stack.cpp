#include "../Claseshpp/stack.hpp"

namespace eda {

Stack::Stack():head(nullptr) {
 // TODO Auto-generated constructor stub
 }

 void Stack::push(std::string val){
    Node* node = new Node(val);
    push(node);
}

 void Stack::push(trees::ABBNode* val){
    Node* nodo = new Node(val);
    push(nodo);
}

 void Stack::push(Node* node){
    if (head == nullptr){
        head = node;
    }
    else{
        node->setNext(head);
        head = node;
    }
 }
 

void Stack::pop(){
    if (!isEmpty()){
        Node* ptr = head;
        head = head->getNext();
        delete ptr;
    }
}

Node* Stack::top(){
    return head; 
}

 bool Stack::isEmpty(){
    return (head == nullptr);
 }

void Stack::clear(){
    while (!isEmpty()){ 
        pop();
    }
}

Stack::~Stack() {
    clear();
}

}