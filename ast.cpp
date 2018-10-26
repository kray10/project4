#include "ast.hpp"
// Use this file if you'd like to implement any auxilary functions in your
// AST nodes
namespace LILC{

std::string FormalsListNode::getTypes() {
    std::string result = "";
    for (std::list<FormalDeclNode *>::iterator
      it=myFormals->begin();
      it != myFormals->end(); ++it){
        FormalDeclNode * elt = *it;
        result += elt->getType();
      if(next(it) != myFormals->end())
      {
        result += ",";
      }
    }
    return result;
}

	std::string IdNode::getId() {
  return myStrVal;
}

}
