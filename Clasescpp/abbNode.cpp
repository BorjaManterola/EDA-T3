#include "../Claseshpp/abbNode.hpp"

namespace trees {

ABBNode::ABBNode():
	ptrLeft(nullptr), data(-1), ope(""), ptrRight(nullptr) {}

ABBNode::ABBNode(int val):
	ptrLeft(nullptr), data(val), ope(""), ptrRight(nullptr) {}

ABBNode::ABBNode(std::string val):
	ptrLeft(nullptr), data(-1), ope(val), ptrRight(nullptr) {}

void ABBNode::setLeft(ABBNode* node){
	ptrLeft = node;
}

void ABBNode::setRight(ABBNode* node){
	ptrRight = node;
}

void ABBNode::setData(int val){
	data = val;
}

void ABBNode::setDato(std::string val){
	ope = val;
}

ABBNode* ABBNode::getLeft(){
	return ptrLeft;
}

ABBNode* ABBNode::getRight(){
	return ptrRight;
}

int ABBNode::getData(){
	return data;
}

std::string ABBNode::getDato() {
	return ope;
}

ABBNode::~ABBNode() {
	if (ptrLeft != nullptr){
		delete ptrLeft;
	}
	if (ptrRight != nullptr){
		delete ptrRight;
	}
}

}