#include "ast.hpp"
#include "symbol_table.hpp"

namespace LILC{

bool ProgramNode::nameAnalysis(SymbolTable * symTab){
	symTab->addScope();
	this->myDeclList->nameAnalysis(symTab);
}

bool DeclListNode::nameAnalysis(SymbolTable * symTab){
	bool result = true;
	for (std::list<DeclNode *>::iterator
		it=myDecls->begin();
		it != myDecls->end(); ++it){

	  DeclNode * elt = *it;
	  result = result && elt->nameAnalysis(symTab);
	}
}

bool VarDeclNode::nameAnalysis(SymbolTable * symTab){
	return symTab->addSymbol(myId->getId(), Func, myType->getType(), mySize);
}

bool FormalsListNode::nameAnalysis(SymbolTable * symTab){
	bool result = true;
	for (std::list<FormalDeclNode *>::iterator
		it=myFormals->begin();
		it != myFormals->end(); ++it){

	  FormalDeclNode * elt = *it;
	  result = result && elt->nameAnalysis(symTab);
	}
	return result;
}

bool ExpListNode::nameAnalysis(SymbolTable * symTab){
	bool result = true;
	for (std::list<ExpNode *>::iterator
		it = myExps.begin();
		it != myExps.end(); ++it){

	  ExpNode * elt = *it;
	  result = result && elt->nameAnalysis(symTab);
	}
	return result;
}

bool StmtListNode::nameAnalysis(SymbolTable * symTab){
	bool result = true;
	for (std::list<StmtNode *>::iterator
		it=myStmts->begin();
		it != myStmts->end(); ++it){

	  StmtNode * elt = *it;
	  result = result && elt->nameAnalysis(symTab);
	}
	return result;
}

bool FnBodyNode::nameAnalysis(SymbolTable * symTab){
	myDeclList->nameAnalysis(symTab);
	myStmtList->nameAnalysis(symTab);
}

bool FnDeclNode::nameAnalysis(SymbolTable * symTab){
	std::string type = myFormals->getTypes() + "->" + myType->getType();
	bool result = symTab->addSymbol(myId->getId(), Func, type, -1);
	symTab->addScope();
	result = result && myFormals->nameAnalysis(symTab);
	result = result && myBody->nameAnalysis(symTab);
	symTab->dropScope();
	return result;
}

bool FormalDeclNode::nameAnalysis(SymbolTable * symTab){
	return symTab->addSymbol(myId->getId(), Var, myType->getType(), -1);
}

bool StructDeclNode::nameAnalysis(SymbolTable * symTab){
	bool result = symTab->addSymbol(myId->getId(), Struct, myId->getId(), -1);
	//result = result && myDeclList->nameAnalysis(symTab);
	return result;
}

bool IntNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a IntNode.\n";
	return true;
}

bool BoolNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a BoolNode.\n";
	return true;
}

bool VoidNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a VoidNode.\n";
	return true;
}

bool StructNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a StructNode.\n";
	return true;
}

bool IntLitNode::nameAnalysis(SymbolTable * symTab){
	return true;
}

bool StrLitNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a StrLitNode.\n";
	return true;
}

bool IdNode::nameAnalysis(SymbolTable * symTab){
	myType = "(" + symTab->findType(myStrVal) + ")";
	if (myType.compare("")) {
		return false;
	}
	return true;
}

bool TrueNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a TrueNode.\n";
	return true;
}

bool FalseNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a FalseNode.\n";
	return true;
}

bool DotAccessNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp->nameAnalysis(symTab);
	return (result && myId->nameAnalysis(symTab));
}

bool AssignNode::nameAnalysis(SymbolTable * symTab){
	myExpLHS->nameAnalysis(symTab);
	myExpRHS->nameAnalysis(symTab);
	return true;
}

bool CallExpNode::nameAnalysis(SymbolTable * symTab){
	bool result = myId->nameAnalysis(symTab);
	result = result && myExpList->nameAnalysis(symTab);
	return result;
}

bool UnaryMinusNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a UnaryMinusNode.\n";
	return true;
}

bool NotNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a NotNode.\n";
	return true;
}

bool PlusNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a PlusNode.\n";
	return true;
}

bool MinusNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a MinusNode.\n";
	return true;
}

bool TimesNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a TimesNode.\n";
	return true;
}

bool DivideNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a DivideNode.\n";
	return true;
}

bool AndNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a AndNode.\n";
	return true;
}

bool OrNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a OrNode.\n";
	return true;
}

bool EqualsNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a EqualsNode.\n";
	return true;
}

bool NotEqualsNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a NotEqualsNode.\n";
	return true;
}

bool LessNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a LessNode.\n";
	return true;
}

bool GreaterNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a GreaterNode.\n";
	return true;
}

bool LessEqNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a LessEqNode.\n";
	return true;
}

bool GreaterEqNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a GreaterEqNode.\n";
	return true;
}

bool AssignStmtNode::nameAnalysis(SymbolTable * symTab){
	myAssign->nameAnalysis(symTab);
	return true;
}

bool PostIncStmtNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a PostIncStmtNode.\n";
	return true;
}

bool PostDecStmtNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a PostDecStmtNode.\n";
	return true;
}

bool ReadStmtNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a ReadStmtNode.\n";
	return true;
}

bool WriteStmtNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a WriteStmtNode.\n";
	return true;
}

bool IfStmtNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a IfStmtNode.\n";
	return true;
}

bool IfElseStmtNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a IfElseStmtNode.\n";
	return true;
}

bool WhileStmtNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a WhileStmtNode.\n";
	return true;
}

bool CallStmtNode::nameAnalysis(SymbolTable * symTab){
	return myCallExp->nameAnalysis(symTab);
}

bool ReturnStmtNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a ReturnStmtNode.\n";
	return true;
}

} // End namespace LIL' C
