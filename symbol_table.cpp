#include "symbol_table.hpp"
namespace LILC{

SymbolTableEntry::SymbolTableEntry () {
	this->id = "";
	this->kind = NotFound;
	this->type = "";
	this->size = 0;
}
SymbolTableEntry::SymbolTableEntry (std::string id, Kind kind, std::string type, int size) {
		this->id = id;
		this->kind = kind;
		this->type = type;
		this->size = size;
}

std::string SymbolTableEntry::getId() {
	return id;
}

void SymbolTableEntry::setId(std::string id) {
	this->id = id;
}

Kind SymbolTableEntry::getKind() {
	return kind;
}
void SymbolTableEntry::setKind(Kind kind) {
	this->kind = kind;
}
std::string SymbolTableEntry::getType() {
	return type;
}
void SymbolTableEntry::setType(std::string type) {
	this->type = type;
}
int SymbolTableEntry::getSize() {
	return size;
}
void SymbolTableEntry::setSize(int size) {
	this->size = size;
}

ScopeTable::ScopeTable(){
	map = new std::unordered_map<std::string, SymbolTableEntry *>();
}

SymbolTableEntry* ScopeTable::getEntry(std::string id) {
	auto entry = map->find(id);
	if (entry != map->end()) {
		return entry->second;
	}
	return new SymbolTableEntry();
}

SymbolTable::SymbolTable(){
	//TODO: implement the list of hashtables
	// approach to building a symbol table
	scopeTables = new std::list<ScopeTable *>();
};

void SymbolTable::addScope() {
	ScopeTable* table = new ScopeTable();
	scopeTables->push_back(table);
}

void SymbolTable::dropScope() {
	if (!scopeTables->empty()) {
		scopeTables->pop_back();
	}
}

}
