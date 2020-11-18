/*
 * @author brewlin
 * @date   2020/9/1
 */
#ifndef LANG_UTILS_H
#define LANG_UTILS_H
#include <any>
#include <deque>
#include <string>
#include <iostream>
#include "Value.h"



[[noreturn]] void parse_err(char const* const format, ...);

template <typename _DesireType, typename... _ArgumentType>
inline bool anyone(_DesireType k, _ArgumentType... args) {
    return ((args == k) || ...);
}


#endif //LANG_UTILS_H
