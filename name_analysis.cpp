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
	return result;
}

bool VarDeclNode::nameAnalysis(SymbolTable * symTab){
	if (mySize == NOT_STRUCT) {
		bool result = symTab->addSymbol(myId->getId(), Var, myType->getType(), mySize);

		if (!result) {
			reportError("Multiply declared identifier", myId->getId());
		}

		if (myType->getType().compare("void") == 0) {
			reportError("Non-function declared void", myId->getId());
			result = false;
		}

		return result;
	}

	SymbolTableEntry* entry;
	if (symTab->getGlobalScope() == nullptr) {
		entry = symTab->findEntry(myType->getType());
	} else {
		entry = symTab->getGlobalScope()->findEntry(myType->getType());
	}

	if (entry->getKind() != Struct) {
		reportError("Invalid name of struct type", myId->getId());
		return false;
	}
	return symTab->addSymbol(myId->getId(), Struct, myType->getType(), mySize);
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
	bool result = symTab->addSymbol(myId->getId(), Struct, "struct", -1);
	SymbolTable* structTable = symTab->findEntry(myId->getId())->getStructScope();
	structTable->setGlobalScope(symTab);
	result = result && myDeclList->nameAnalysis(structTable);
	return result;
}

bool IntNode::nameAnalysis(SymbolTable * symTab){
	//Should be taken care of
	std::cout << "[DELETE ME] I'm a IntNode.\n";
	return true;
}

bool BoolNode::nameAnalysis(SymbolTable * symTab){
	//Should be taken care of
	std::cout << "[DELETE ME] I'm a BoolNode.\n";
	return true;
}

bool VoidNode::nameAnalysis(SymbolTable * symTab){
	//Should be taken care of
	std::cout << "[DELETE ME] I'm a VoidNode.\n";
	return true;
}

bool StructNode::nameAnalysis(SymbolTable * symTab){
	//Should be taken care of
	std::cout << "[DELETE ME] I'm a StructNode.\n";
	return true;
}

bool IntLitNode::nameAnalysis(SymbolTable * symTab){
	//Should be taken care of
	return true;
}

bool StrLitNode::nameAnalysis(SymbolTable * symTab){
	//Should be taken care of
	std::cout << "[DELETE ME] I'm a StrLitNode.\n";
	return true;
}

bool IdNode::nameAnalysis(SymbolTable * symTab){
	myEntry = symTab->findEntry(myStrVal);
	if (myEntry->getKind() == NotFound) {
		reportError("Undeclared identifier", myStrVal);
		return false;
	}
	return true;
}

bool TrueNode::nameAnalysis(SymbolTable * symTab){
	//Should be taken care of
	std::cout << "[DELETE ME] I'm a TrueNode.\n";
	return true;
}

bool FalseNode::nameAnalysis(SymbolTable * symTab){
	//Should be taken care of
	std::cout << "[DELETE ME] I'm a FalseNode.\n";
	return true;
}

bool DotAccessNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp->nameAnalysis(symTab);
	structEntry = myExp->getEntry();
	if (structEntry->getKind() != Struct) {
		reportError("Dot‑access of non‑struct type", structEntry->getId());
		result = false;
	}
	if (structEntry->getType().compare("struct") != 0) {
		structEntry = symTab->findEntry(structEntry->getType());
	}


	SymbolTableEntry* entry = structEntry->getStructScope()->findEntry(myId->getId());
	if (entry->getKind() == NotFound) {
		reportError("Invalid struct field name", myId->getId());
		result = false;
	} else {
		result = result && myId->nameAnalysis(structEntry->getStructScope());
	}
	structEntry = symTab->findEntry(entry->getType());

	return result;
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
	return myExp->nameAnalysis(symTab);
}

bool NotNode::nameAnalysis(SymbolTable * symTab){
	return myExp->nameAnalysis(symTab);
}

bool PlusNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp1->nameAnalysis(symTab);
	return (result && myExp2->nameAnalysis(symTab));
}

bool MinusNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp1->nameAnalysis(symTab);
	return (result && myExp2->nameAnalysis(symTab));
}

bool TimesNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp1->nameAnalysis(symTab);
	return (result && myExp2->nameAnalysis(symTab));
}

bool DivideNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp1->nameAnalysis(symTab);
	return (result && myExp2->nameAnalysis(symTab));
}

bool AndNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp1->nameAnalysis(symTab);
	return (result && myExp2->nameAnalysis(symTab));
}

bool OrNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp1->nameAnalysis(symTab);
	return (result && myExp2->nameAnalysis(symTab));
}

bool EqualsNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp1->nameAnalysis(symTab);
	return (result && myExp2->nameAnalysis(symTab));
}

bool NotEqualsNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp1->nameAnalysis(symTab);
	return (result && myExp2->nameAnalysis(symTab));
}

bool LessNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp1->nameAnalysis(symTab);
	return (result && myExp2->nameAnalysis(symTab));
}

bool GreaterNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp1->nameAnalysis(symTab);
	return (result && myExp2->nameAnalysis(symTab));
}

bool LessEqNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp1->nameAnalysis(symTab);
	return (result && myExp2->nameAnalysis(symTab));
}

bool GreaterEqNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp1->nameAnalysis(symTab);
	return (result && myExp2->nameAnalysis(symTab));
}

bool AssignStmtNode::nameAnalysis(SymbolTable * symTab){
	myAssign->nameAnalysis(symTab);
	return true;
}

bool PostIncStmtNode::nameAnalysis(SymbolTable * symTab){
	return myExp->nameAnalysis(symTab);
}

bool PostDecStmtNode::nameAnalysis(SymbolTable * symTab){
	return myExp->nameAnalysis(symTab);
}

bool ReadStmtNode::nameAnalysis(SymbolTable * symTab){
	return myExp->nameAnalysis(symTab);
}

bool WriteStmtNode::nameAnalysis(SymbolTable * symTab){
	return myExp->nameAnalysis(symTab);
}

bool IfStmtNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp->nameAnalysis(symTab);
	symTab->addScope();
	result = result && myDecls->nameAnalysis(symTab);
	result = result && myStmts->nameAnalysis(symTab);
	symTab->dropScope();
	return result;
}

bool IfElseStmtNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp->nameAnalysis(symTab);
	symTab->addScope();
	result = result && myDeclsT->nameAnalysis(symTab);
	result = result && myStmtsT->nameAnalysis(symTab);
	symTab->dropScope();
	symTab->addScope();
	result = myExp->nameAnalysis(symTab);
	result = result && myDeclsF->nameAnalysis(symTab);
	result = result && myStmtsF->nameAnalysis(symTab);
	symTab->dropScope();
	return result;
}

bool WhileStmtNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp->nameAnalysis(symTab);
	symTab->addScope();
	result = result && myDecls->nameAnalysis(symTab);
	result = result && myStmts->nameAnalysis(symTab);
	symTab->dropScope();
	return result;
}

bool CallStmtNode::nameAnalysis(SymbolTable * symTab){
	return myCallExp->nameAnalysis(symTab);
}

bool ReturnStmtNode::nameAnalysis(SymbolTable * symTab){
	return myExp->nameAnalysis(symTab);
}

} // End namespace LIL' C
