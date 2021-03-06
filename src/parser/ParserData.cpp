#include "Parser.h"
/**
 * 添加一个函数
 * @param name
 * @param f
 */
void Parser::addFunc(const std::string &name, Function *f)
{
    if(f->isExtern)
        extern_funcs.insert(std::make_pair(name,f));
    else
        funcs.insert(std::make_pair(name,f));
}
/**
 * 检查是否存在该函数
 * @param name
 * @return
 */
bool Parser::hasFunc(const std::string &name, bool is_extern)
{
    if(is_extern)
        return extern_funcs.count(name) == 1;
    else
        return funcs.count(name) == 1;
}
/**
 * 获取一个func
 * @param name
 * @return
 */
Function* Parser::getFunc(const std::string &name, bool is_extern)
{
    if(is_extern){
        if(auto f = extern_funcs.find(name);f != funcs.end())
            return f->second;
    }else{
        if(auto f = funcs.find(name);f != funcs.end())
            return f->second;
    }
    return nullptr;
}


/**
 * 添加一个结构体
 * @param name
 * @param f
 */
void Parser::addClass(const std::string &name, Class *f)
{
    classs.insert(std::make_pair(name,f));
}
/**
 * 检查是否存在该结构体
 * @param name
 * @return
 */
bool Parser::hasClass(const std::string &name)
{
    return classs.count(name) == 1;
}
/**
 * 获取一个Class
 * @param name
 * @return
 */
Class* Parser::getClass(const std::string &name)
{
    if(auto f = classs.find(name);f != classs.end())
        return f->second;
    return nullptr;
}
