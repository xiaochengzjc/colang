#ifndef CO_LANG_PACKAGE_H
#define CO_LANG_PACKAGE_H
#include <string>
#include <tuple>
#include <iostream>
#include <fstream>
#include "Ast.h"
#include <memory>
#include <unordered_map>
#include "Utils.h"
#include <vector>
#include <cassert>
#include "Runtime.h"
#include "Expression.h"
#include "Statement.h"
#include <cstdlib>

struct Function;
struct Block;
class  Parser;

class Package {
public:
    explicit  Package(std::string package);
    ~Package();
    bool      parse();
    void      asmgen();

private:
    //map[filepath + name] = parser
    std::unordered_map<std::string,Parser*> parsers;
	std::string package;    
};


#endif //CO_LANG_PACKAGE_H
