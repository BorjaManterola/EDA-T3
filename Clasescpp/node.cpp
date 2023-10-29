#include "../Claseshpp/node.hpp"

namespace eda {

Node::Node(): abbnode(nullptr), dato(-1), data(""), ptrNext(nullptr) {}

Node::Node(int val, Node* next): abbnode(nullptr), dato(val), data(""), ptrNext(next) {}

Node::Node(std::string val, Node* next): abbnode(nullptr), dato(-1), data(val), ptrNext(next) {}

Node::Node(trees::ABBNode* val, Node* next): abbnode(val), dato(-1), data(""), ptrNext(next) {}

void Node::setDato(int _dato){
    data = _dato;
}

void Node::setData(std::string _data){
    data = _data;
}

void Node::setABBNode(trees::ABBNode* _abbnode) {
    abbnode = _abbnode;
}

void Node::setNext(Node* next){
    ptrNext = next;
}

int Node::getDato(){
    return dato;
}

trees::ABBNode* Node::getABBNode() {
    if (abbnode == nullptr) {
    }
    return abbnode;
}

std::string Node::getData(){
    return data;
}

std::string Node::getABBNodeDato() {
    return abbnode->getDato();
}

Node* Node::getNext(){
    return ptrNext;
}

void Node::print(){
    std::cout << data ;
}

Node::~Node() {}

}