#ifndef CO_LANG_ASMER_PARSER_H
#define CO_LANG_ASMER_PARSER_H
#include <string>
#include <tuple>
#include <iostream>
#include <fstream>
#include "src/asm_ast/Token.h"
#include <memory>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <cstdlib>
#include "Scanner.h"
#include "src/asm_ast/Function.h"
#include "src/asm_ast/Instruct.h"


namespace asmer {

    
class Parser {
public:
    asmer::Scanner*        scanner;
    asmer::SymTable*       symtable;
    std::vector<Function*> funcs;

public:
    explicit Parser(const std::string filepath);
    ~Parser();
    std::string printToken();
    void parse();
    void parseKeyword();
    void parseGlobal();
    void parseQuad(std::string labelname);
    void parseString(std::string labelname);
    void parseLabel();

    Instruct* parseInstruct();
    Instruct* parseZeroInstruct();
    Instruct* parseOneInstruct();
    Instruct* parseTwoInstruct();
    Function* parseFunction(std::string labelname);
};

};

//记录扫描的次数，第一遍扫描计算所有符号的地址或者值，第二编扫描，生成指令的二进制内容
extern int scanLop;
//有效数据长度
extern int dataLen;

#endif //CO_LANG_PARSER_H
