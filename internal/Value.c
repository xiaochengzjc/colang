/*
 * @author brewlin
 * @date   2020/9/6
 */
#include "Value.h"
#include "String.h"
#include "Array.h"
#include "Map.h"
/**
 * + operator
 * @param lhs
 * @param rhs
 * @return
 */
Value* value_plus(Value* lhs,Value* rhs) {
    Value* result = (Value*)gc_malloc(sizeof(Value));
    if(!lhs){
        memcpy(result,rhs, sizeof(Value));
        return result;
    }
    //有字符串就最终类型是字符串
    if(lhs->type == String || rhs->type == String){
        result->type = String;
        result->data = value_string_plus(lhs,rhs);
        return result;
    }
    //有int类型就进行int类型相加
    if (lhs->type == Int || rhs->type == Int){
        result->type = Int;
        result->data = value_int_plus(lhs,rhs);
        return result;
    }
    exit(1);
}
/**
 * - operator
 * @param lhs
 * @param rhs
 * @return
 */
Value* value_minus(Value* lhs,Value* rhs) {
    Value* result = (Value*)gc_malloc(sizeof(Value));
    if(!lhs){
        memcpy(result,rhs, sizeof(Value));
        return result;
    }
    //有字符串就最终类型是字符串
    if(lhs->type == String || rhs->type == String){
        result->type = String;
        result->data = value_string_minus(lhs,rhs);
        return result;
    }
    //有int类型就进行int类型相加
    if (lhs->type == Int || rhs->type == Int){
        result->type = Int;
        result->data = value_int_minus(lhs,rhs);
        return result;
    }
    exit(1);
}
/**
 * * operator
 * @param lhs
 * @param rhs
 * @return
 */
Value* value_mul(Value* lhs,Value* rhs) {
    Value* result = (Value*)gc_malloc(sizeof(Value));
    if(!lhs){
        memcpy(result,rhs, sizeof(Value));
        return result;
    }
    //有字符串就最终类型是字符串
    if(lhs->type == String || rhs->type == String){
        result->type = String;
        result->data = value_string_mul(lhs,rhs);
        return result;
    }
    //有int类型就进行int类型相加
    if (lhs->type == Int || rhs->type == Int){
        result->type = Int;
        result->data = value_int_mul(lhs,rhs);
        return result;
    }
    exit(1);
}
/**
 * / operator
 * @param lhs
 * @param rhs
 * @return
 */
Value* value_div(Value* lhs,Value* rhs) {
    Value* result = (Value*)gc_malloc(sizeof(Value));
    if(!lhs){
        memcpy(result,rhs, sizeof(Value));
        return result;
    }
    //字符串的触发运算全部返回0
    if(lhs->type == String || rhs->type == String){
        result->type = Int;
        result->data = value_string_div(lhs,rhs);
        return result;
    }
    //有int类型就进行int类型相加
    if (lhs->type == Int || rhs->type == Int){
        result->type = Int;
        result->data = value_int_div(lhs,rhs);
        return result;
    }
    exit(1);
}
/**
 * & operator
 * @param lhs
 * @param rhs
 * @return
 */
Value* value_bitand(Value* lhs,Value* rhs) {
    Value* result = (Value*)gc_malloc(sizeof(Value));
    if(!lhs){
        memcpy(result,rhs, sizeof(Value));
        return result;
    }
    //字符串的触发运算全部返回0
    if(lhs->type == String || rhs->type == String){
        result->type = Int;
        result->data = value_string_bitand(lhs,rhs);
        return result;
    }
    //有int类型就进行int类型相加
    if (lhs->type == Int || rhs->type == Int){
        result->type = Int;
        result->data = value_int_bitand(lhs,rhs);
        return result;
    }
    exit(1);
}
/**
 * | operator
 * @param lhs
 * @param rhs
 * @return
 */
Value* value_bitor(Value* lhs,Value* rhs) {
    Value* result = (Value*)gc_malloc(sizeof(Value));
    if(!lhs){
        memcpy(result,rhs, sizeof(Value));
        return result;
    }
    //字符串的触发运算全部返回0
    if(lhs->type == String || rhs->type == String){
        result->type = Int;
        result->data = value_string_bitor(lhs,rhs);
        return result;
    }
    //有int类型就进行int类型相加
    if (lhs->type == Int || rhs->type == Int){
        result->type = Int;
        result->data = value_int_bitor(lhs,rhs);
        return result;
    }
    exit(1);
}
/**
 * << operator
 * @param lhs
 * @param rhs
 * @return
 */
Value* value_shift_left(Value* lhs,Value* rhs) {
    Value* result = (Value*)gc_malloc(sizeof(Value));
    if(!lhs){
        memcpy(result,rhs, sizeof(Value));
        return result;
    }
    //字符串的触发运算全部返回0
    if(lhs->type == String || rhs->type == String){
        result->type = Int;
        result->data = value_string_shift_left(lhs,rhs);
        return result;
    }
    //有int类型就进行int类型相加
    if (lhs->type == Int || rhs->type == Int){
        result->type = Int;
        result->data = value_int_shift_left(lhs,rhs);
        return result;
    }
    exit(1);
}
/**
 * >> operator
 * @param lhs
 * @param rhs
 * @return
 */
Value* value_shift_right(Value* lhs,Value* rhs) {
    Value* result = (Value*)gc_malloc(sizeof(Value));
    if(!lhs){
        memcpy(result,rhs, sizeof(Value));
        return result;
    }
    //字符串的触发运算全部返回0
    if(lhs->type == String || rhs->type == String){
        result->type = Int;
        result->data = value_string_shift_right(lhs,rhs);
        return result;
    }
    //有int类型就进行int类型相加
    if (lhs->type == Int || rhs->type == Int){
        result->type = Int;
        result->data = value_int_shift_right(lhs,rhs);
        return result;
    }
    exit(1);
}
/**
 * == operator
 * @param lhs
 * @param rhs
 * @return Value*
 */
Value* value_equal(Value* lhs,Value* rhs,int equal) {
    Value* result = (Value*)gc_malloc(sizeof(Value));
    result->type = Bool;
    result->data = 0;
    // 如果有string则直接进行string比较
    if(lhs->type == String || rhs->type == String){
        result->data = value_string_equal(lhs,rhs,equal);
        return result;
    }
    //有int类型就进行int类型相加
    if (lhs->type == Int || rhs->type == Int){
        result->data = value_int_equal(lhs,rhs,equal);
    }
    return result;
}
/**
 * < operator
 * @param lhs
 * @param rhs
 * @return Value*
 */
Value* value_lowerthan(Value* lhs,Value* rhs,int equal)
{
    Value* result = (Value*)gc_malloc(sizeof(Value));
    result->type = Bool;
    //默认为true  小于
    result->data = 1;
    // 如果有string则直接进行string比较
    if(lhs->type == String || rhs->type == String){
        result->data = value_string_lowerthan(lhs,rhs,equal);
        return result;
    }
    //有int类型就进行int类型相加
    if (lhs->type == Int || rhs->type == Int){
        result->data = value_int_lowerthan(lhs,rhs,equal);
    }
    return result;
}
/**
 * > operator
 * @param lhs
 * @param rhs
 * @return Value*
 */
Value* value_greaterthan(Value* lhs,Value* rhs,int equal)
{
    Value* result = (Value*)gc_malloc(sizeof(Value));
    result->type = Bool;
    //默认为true  大于
    result->data = 1;
    // 如果有string则直接进行string比较
    if(lhs->type == String || rhs->type == String){
        result->data = value_string_greaterthan(lhs,rhs,equal);
        return result;
    }
    //有int类型就进行int类型相加
    if (lhs->type == Int || rhs->type == Int){
        result->data = value_int_greaterthan(lhs,rhs,equal);
    }
    return result;
}

/**
 * && operator
 * @param lhs
 * @param rhs
 * @return Value*
 */
Value* value_logand(Value* lhs,Value* rhs) {
    Value* result = (Value*)gc_malloc(sizeof(Value));
    result->type = Bool;
    result->data = isTrue(lhs) && isTrue(rhs);
    return result;
}
Value* value_logor(Value* lhs,Value* rhs) {
    Value* result = (Value*)gc_malloc(sizeof(Value));
    result->type = Bool;
    result->data = isTrue(lhs) || isTrue(rhs);
    return result;
}

/**
 *
 * @param root
 * @param index
 * @param var
 */
void   kv_update(Value* root,Value* index,Value* var)
{
    if(root->type == Array){
        return arr_updateone(root,index,var);
    }
    if(root->type == Map){
        return map_insert(root,index,var);
    }
    printf("[kv_update] arr or map is invalid ,probably something wrong\n");
}
/**
 *
 * @param root
 * @param index
 * @return
 */
Value* kv_get(Value* root,Value* index){
    if(root->type == Array){
        return arr_get(root,index);
    }
    if(root->type == Map){
        return map_find(root,index);
    }
    printf("[kv_get] arr or map is invalid ,probably something wrong\n");
}
/**
 * tell if itstrue
 * @param cond
 * @return bool
 */
int isTrue(Value* cond){
    switch (cond->type){
        case Int:
            return cond->data > 0;
        case Double:
            return cond->data > 0;
        case String:
            return stringlen(cond->data);
        case Bool:
            return cond->data;
        case Char:
            return cond->data != 0;
        case Null:
            return 0;
        default:
            return 0;
    }
}
/**
 *
 * @param opt
 * @param lhs
 * @param rhs
 * @return
 */
void unary_operator(int opt,Value *lhs,Value* rhs)
{
    if( !lhs || !rhs ){
        printf(" [unary-op] probably wrong at there! lhs:%p rhs:%p\n",lhs,rhs);
        return;
    }
    Value* ret;
    switch (opt){
        case TK_ASSIGN:
            ret = rhs;break;
        case TK_PLUS_AGN:
            ret = value_plus(*(Value**)lhs,rhs);break;
        case TK_MINUS_AGN:
            ret = value_minus(*(Value**)lhs,rhs);break;
        case TK_MUL_AGN:
            ret = value_mul(*(Value**)lhs,rhs);break;
        case TK_DIV_AGN:
            ret = value_div(*(Value**)lhs,rhs);break;
        case TK_BITAND_AGN:
            ret = value_bitand(*(Value**)lhs,rhs);break;
        case TK_BITOR_AGN:
            ret = value_bitor(*(Value**)lhs,rhs);break;
        case TK_SHIFTL_AGN:
            ret = value_shift_left(*(Value**)lhs,rhs);break;
        case TK_SHIFTR_AGN:
            ret = value_shift_right(*(Value**)lhs,rhs);break;
        default:
            printf(" [unary-op] unkown op:%d\n",opt);
            ret = rhs;
    }
    // assign =
    *(Value**)lhs = ret;
}
/**
 * lhs  rhs 都是堆变量
 * @param opt
 * @param lhs
 * @param rhs
 */
Value* binary_operator(int opt, Value *lhs, Value* rhs)
{
    if( !lhs || !rhs ){
        printf(" [binary-op] probably wrong at there! lhs:%p rhs:%p\n",lhs,rhs);
        return NULL;
    }
    switch (opt){
        case TK_PLUS:// +
            return value_plus(lhs,rhs);
        case TK_MINUS:// -
            return value_minus(lhs,rhs);
        case TK_MUL:// *
            return value_mul(lhs,rhs);
        case TK_DIV:// \ .
            return value_div(lhs,rhs);

        case TK_BITAND:// &
            return value_bitand(lhs,rhs);
        case TK_BITOR:// |
            return value_bitor(lhs,rhs);
        case TK_SHIFTL:
            return value_shift_left(lhs,rhs);
        case TK_SHIFTR:
            return value_shift_right(lhs,rhs);

        case TK_LT:// <
            return value_lowerthan(lhs,rhs,FALSE);
        case TK_LE:// <=
            return value_lowerthan(lhs,rhs,TRUE);
        case TK_GE:// >=
            return value_greaterthan(lhs,rhs,TRUE);
        case TK_GT:// >
            return value_greaterthan(lhs,rhs,FALSE);
        case TK_EQ:// ==
            return value_equal(lhs,rhs,TRUE);
        case TK_NE:// !=
            return value_equal(lhs,rhs,FALSE);
        case TK_LOGAND:// &&
            return value_logand(lhs,rhs);
        case TK_LOGOR:// ||
            return value_logor(lhs,rhs);
        default:
            printf(" [binary-op] unknow op:%d \n",opt);
            return NULL;
    }
}