/*
 * @author brewlin
 * @date   2020/9/6
 */
#ifndef LANG_STATEMENT_H
#define LANG_STATEMENT_H

#include "Ast.h"
#include "Value.h"
#include "Llvm.h"
class Context;
struct ExecResult;
class Runtime;

struct Statement : public AstNode {
    using AstNode::AstNode;

    virtual ~Statement() = default;

    virtual ExecResult   interpret(Runtime* rt, std::deque<Context*> ctx);
    virtual ExecResult   asmgen(Runtime* rt, std::deque<Context*> ctx) = 0;
    virtual llvm::Value* compiler(Runtime* rt, std::deque<Context*> ctx)  = 0;
    virtual std::string  toString() = 0;

};

struct BreakStmt : public Statement {
    explicit     BreakStmt(int line, int column) : Statement(line, column) {}

    ExecResult   interpret(Runtime* rt, std::deque<Context*> ctx) override;
    ExecResult   asmgen(Runtime* rt, std::deque<Context*> ctx) override;
    llvm::Value* compiler(Runtime* rt, std::deque<Context*> ctx) override;
    std::string  toString() override;
};

struct ContinueStmt : public Statement {
    explicit     ContinueStmt(int line, int column) : Statement(line, column) {}

    ExecResult   interpret(Runtime* rt, std::deque<Context*> ctx) override;
    ExecResult   asmgen(Runtime* rt, std::deque<Context*> ctx) override;
    llvm::Value* compiler(Runtime* rt, std::deque<Context*> ctx)  override;
    std::string  toString() override;
};


struct ExpressionStmt : public Statement {
    explicit     ExpressionStmt(Expression* expr, int line, int column)
                 :Statement(line, column), expr(expr) {}

    Expression*  expr{};

    ExecResult   interpret(Runtime* rt, std::deque<Context*> ctx) override;
    ExecResult   asmgen(Runtime* rt, std::deque<Context*> ctx) override;
    llvm::Value* compiler(Runtime* rt, std::deque<Context*> ctx) override;
    std::string  toString() override;
};

struct ReturnStmt : public Statement {
    explicit     ReturnStmt(int line, int column) : Statement(line, column) {}
    Expression*  ret{};

    ExecResult   interpret(Runtime* rt, std::deque<Context*> ctx) override;
    ExecResult   asmgen(Runtime* rt, std::deque<Context*> ctx) override;
    llvm::Value* compiler(Runtime* rt, std::deque<Context*> ctx) override;
    std::string  toString() override;
};

struct IfStmt : public Statement {
    explicit     IfStmt(int line, int column) : Statement(line, column) {}

    Expression*  cond{};
    Block*       block{};
    Block*       elseBlock{};

    ExecResult   interpret(Runtime* rt, std::deque<Context*> ctx) override;
    ExecResult   asmgen(Runtime* rt, std::deque<Context*> ctx) override;
    llvm::Value* compiler(Runtime* rt, std::deque<Context*> ctx) override;
    std::string  toString() override;
};

struct WhileStmt : public Statement {
    explicit     WhileStmt(int line, int column) : Statement(line, column) {}
    Expression*  cond{};
    Block*       block{};

    ExecResult   interpret(Runtime* rt, std::deque<Context*> ctx) override;
    ExecResult   asmgen(Runtime* rt, std::deque<Context*> ctx) override;
    llvm::Value* compiler(Runtime* rt, std::deque<Context*> ctx) override;
    std::string  toString() override;
};

#endif //LANG_STATEMENT_H
