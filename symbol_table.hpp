#ifndef LILC_SYMBOL_TABLE_HPP
#define LILC_SYMBOL_TABLE_HPP
#include <unordered_map>
#include <list>
#include <iostream>

namespace LILC{
class SymbolTable;
enum Kind {Var, Func, Struct, NotFound};
//A single entry for one name in the symbol table
class SymbolTableEntry{
public:
	SymbolTableEntry();
	SymbolTableEntry (std::string id, Kind kind, std::string type, int size);

	std::string getId();
	void setId(std::string id);
	Kind getKind();
	void setKind(Kind kind);
	std::string getType();
	void setType(std::string type);
	int getSize();
	void setSize(int size);
	SymbolTable* getStructScope() {
		return structScope;
	}
private:
	std::string id;
	Kind kind;
	std::string type;
	int size;
	SymbolTable* structScope;
};

//A single
class ScopeTable{
	public:
		ScopeTable();
		//TODO: add functions for looking up symbols
		// and/or returning information to indicate
		// that the symbol does not exist within
		// the current scope
		SymbolTableEntry* getEntry(std::string id);
		bool addEntry(std::string id, SymbolTableEntry* entry);
		bool exists(std::string id);

	private:
		std::unordered_map<std::string, SymbolTableEntry *>* map;
};

class SymbolTable{
	public:
		SymbolTable();
		//TODO: add functions to create a new scope
		// table when a new scope is entered,
		// drop a scope table when a scope is finished,
		// etc.
		void addScope();
		void dropScope();

		// returns true if succesfully added
		// false if already exists
		bool addSymbol(std::string id, Kind kind, std::string type, int size);
		SymbolTableEntry* findEntry(std::string id);
		SymbolTable* getGlobalScope();
		void setGlobalScope(SymbolTable* table);

	private:
		std::list<ScopeTable *> * scopeTables;
		SymbolTable* globalScope;
};

}
#endif
