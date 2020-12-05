#include "Parser.h"
#include <fstream>
#include "Utils.h"
#include "AsmGen.h"
#include "Package.h"

void Parser::asmgen()
{    
    std::string fullname = filename + ".s";
    std::ofstream out(fullname,std::ios::app);
    AsmGen::out = &out;
    if(out.fail()){
        parse_err("genrate assembly file failed package:%s file:%s",pkg->package.c_str(),
        filename.c_str());
    }
    AsmGen::parser = this;
    //1 计算变量的栈偏移量
    AsmGen::assign_offsets();
    //2 注册全局 var
    AsmGen::registerVars();
    //3 注册全局 string
    AsmGen::registerStrings();
    //4 注册 函数信息
    AsmGen::registerFuncs();
    AsmGen::parser = nullptr;


    out.close();
    AsmGen::out = nullptr;

}