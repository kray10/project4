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
	std::cout << "[DELETE ME] I'm a varDecl. "
		" you should add the information from my"
		" subtree to the to the symbol table"
		" as a new entry in the current scope table\n";

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
}

bool ExpListNode::nameAnalysis(SymbolTable * symTab){
	bool result = true;
	for (std::list<ExpNode *>::iterator
		it = myExps.begin();
		it != myExps.end(); ++it){

	  ExpNode * elt = *it;
	  result = result && elt->nameAnalysis(symTab);
	}
}

bool StmtListNode::nameAnalysis(SymbolTable * symTab){
	bool result = true;
	for (std::list<StmtNode *>::iterator
		it=myStmts->begin();
		it != myStmts->end(); ++it){

	  StmtNode * elt = *it;
	  result = result && elt->nameAnalysis(symTab);
	}
}

bool FnBodyNode::nameAnalysis(SymbolTable * symTab){
	myDeclList->nameAnalysis(symTab);
	myStmtList->nameAnalysis(symTab);
}

bool FnDeclNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a fnDecl. "
		" you should add my information to"
		" the current scope table.\n"
		" you should also add and make current"
		" a new scope table for my body\n";
	bool result = symTab->addSymbol(myId->getId(), Func, myType->getType(), -1);
	symTab->addScope();
	result = result && myFormals->nameAnalysis(symTab);
	result = result && myBody->nameAnalysis(symTab);
	return result;
}

bool FormalDeclNode::nameAnalysis(SymbolTable * symTab){
	return symTab->addSymbol(myId->getId(), Var, myType->getType(), -1);
	return true;
}

bool StructDeclNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a StructDeclNode.\n";
	return true;
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
	std::cout << "[DELETE ME] I'm a IntLitNode.\n";
	return true;
}

bool StrLitNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a StrLitNode.\n";
	return true;
}

bool IdNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a IdNode.\n";
	myType = "(" + symTab->findType(myStrVal) + ")";
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
	std::cout << "[DELETE ME] I'm a DotAccessNode.\n";
	return true;
}

bool AssignNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a AssignNode.\n";
	myExpLHS->nameAnalysis(symTab);
	myExpRHS->nameAnalysis(symTab);
	return true;
}

bool CallExpNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a CallExpNode.\n";
	return true;
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
	std::cout << "[DELETE ME] I'm a AssignStmtNode.\n";
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
	std::cout << "[DELETE ME] I'm a CallStmtNode.\n";
	return true;
}

bool ReturnStmtNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a ReturnStmtNode.\n";
	return true;
}

} // End namespace LIL' C
