#include "../Claseshpp/abb.hpp"
#include <iostream>

namespace trees {

ABB::ABB():root(nullptr) {}

ABB::ABB(ABBNode* camino):root(camino) {}

void ABB::insert_rec(int val, ABBNode* node){
	if (val < node->getData()){
		//LEFT
		if (node->getLeft() == nullptr){
			node->setLeft(new ABBNode(val));
			//std::cout<<val << " inserted on left" << std::endl;
		}
		else{
			insert_rec(val, node->getLeft());
		}
	}
	else{
		//RIGHT
		if (node->getRight() == nullptr){
			node->setRight(new ABBNode(val));
			//std::cout<<val << " inserted on right" << std::endl;
		}
		else{
			insert_rec(val, node->getRight());
		}
	}
}

void ABB::insert(int val){
	if (root == nullptr){
		root = new ABBNode(val);
	}
	else{
		insert_rec(val, root);
	}
}

ABBNode* ABB::find_rec(float val, ABBNode* node){
	ABBNode* ans = nullptr;

	if (node->getData() == val){
		ans = node;
	}
	else{
		if (val < node->getData()){
			ans = find_rec(val, node->getLeft());
		}
		else{
			ans = find_rec(val, node->getRight());
		}
	}

	return ans;
}

ABBNode* ABB::find(float val){
	ABBNode* ans = nullptr;
	ans = find_rec(val, root);
	return ans;
}

void ABB::traverse_rec(ABBNode* node, int level) {
	if (node != nullptr){
		std::cout << std::string(level*2, '-');
		std::cout << node->getDato() << std::endl;
		traverse_rec(node->getLeft(), level + 1);
		traverse_rec(node->getRight(), level + 1);
	}
}

void ABB::traverse(){
	traverse_rec(root, 1);
}

ABB::~ABB() {
	delete root;
}

}