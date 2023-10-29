#ifndef ABBNODE_HPP_
#define ABBNODE_HPP_
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

namespace trees {

class ABBNode {
private:
	ABBNode* ptrLeft;
	float data;
	std::string ope;
	ABBNode* ptrRight;
	int size;
public:
	ABBNode();
	ABBNode(int val);
	ABBNode(std::string val);
	void setLeft(ABBNode* node);
	void setRight(ABBNode* node);
	void setData(int val);
	void setDato(std::string val);
	ABBNode* getLeft();
	ABBNode* getRight();
	int getData();
	std::string getDato();
	virtual ~ABBNode();
};

}

#endif