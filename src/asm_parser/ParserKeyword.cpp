/**
 *@ClassName ParserKeyword
 *@Author brewlin
 *@Date 2020/12/14 0014 下午 5:11
 *@Version 1.0
 **/

#include "Parser.h"
#include "src/asm_ast/Sym.h""

namespace asmer{
    /**
     * 解析 global定义
     */
    void Parser::parseGlobal() {
        assert(scanner->token() == KW_GLOBAL);

        //next
        assert(scanner->scan() == KW_LABEL);

        //TODO: save global label
        std::string labelname = scanner->value();

        scanner->next();
        return;
    }
    //解析label
    void Parser::parseLabel() {
        std::string labelname = scanner->value();
        //next;
        scanner->scan();
        // :
        assert(scanner->token() == TK_COLON);

        //label下有两种情况，
        //1 数据定义
        //2 函数指令
        //next
        switch(scanner->scan()){
            case KW_QUAD:
                parseQuad(labelname);
                return;
            case KW_STRING:
                parseString(labelname):
                return;
            default:
        }

        //其他情况就是函数定义了
        Function* func =parseFunction(labelname);
        funcs.push_back(func);
        return;

    }
    /**
     * 解析 全局变量
     * @param labelname
     */
    void Parser::parseQuad(std::string labelname) {
        assert(scanner->token() == KW_QUAD);

        //下一个是变量的大小
        assert(scanner->scan() == TK_NUMBER);
        int len = std::stoi(scanner->value());

        Sym* sym = new Sym(labelname,len);
        symtable->addSym(sym);

        //next
        scanner->scan();
        return;
    }
    void Parser::parseString(std::string labelname) {
         assert(scanner->token() == KW_STRING);

        //下一个是变量的大小
        assert(scanner->scan() == TK_STRING);

        Sym* sym = new Sym(labelname,scanner->value());
        symtable->addSym(sym);

        //next
        scanner->scan();
        return;
    }
};
