#ifndef ABB_HPP_
#define ABB_HPP_

#include "abbNode.hpp"
#include <vector>
#include <sstream>

namespace trees {

class ABB {
private:
	ABBNode* root;
public:
	ABB();
	ABB(ABBNode* _root);
	void insert_rec(int val, ABBNode* node);
	void insert(int val);
	ABBNode* find_rec(float val, ABBNode* node);
	ABBNode* find(float val);
	void traverse_rec(ABBNode* node, int level);
	void traverse();
	virtual ~ABB();
};

} /* namespace trees */

#endif