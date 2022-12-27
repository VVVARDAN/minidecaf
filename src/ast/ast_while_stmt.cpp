/*****************************************************
 *  Implementation of "WhileStmt".
 *
 *  Please refer to ast/ast.hpp for the definition.
 *
 *  Keltin Leung 
 */

#include "ast/ast.hpp"
#include "ast/visitor.hpp"
#include "config.hpp"

using namespace mind;
using namespace mind::ast;

/* Creates a new WhileStmt node.
 *
 * PARAMETERS:
 *   cond    - the test expression
 *   body    - the loop body
 *   l       - position in the source text
 */
WhileStmt::WhileStmt(Expr *cond, Statement *body, Location *l) {

    setBasicInfo(WHILE_STMT, l);

    condition = cond;
    loop_body = body;
}

/* Visits the current node.
 *
 * PARAMETERS:
 *   v       - the visitor
 */
void WhileStmt::accept(Visitor *v) { v->visit(this); }

/* Prints the current AST node.
 *
 * PARAMETERS:
 *   os      - the output stream
 */
void WhileStmt::dumpTo(std::ostream &os) {
    ASTNode::dumpTo(os);
    newLine(os);
    os << condition;

    newLine(os);
    os << loop_body << ")";
    decIndent(os);
}




/* Creates a new DoWhileStmt node.
 *
 * PARAMETERS:
 *   cond    - the test expression
 *   body    - the loop body
 *   l       - position in the source text
 */
DoWhileStmt::DoWhileStmt(Expr *cond, Statement *body, Location *l) {

    setBasicInfo(Do_While_Stmt, l);

    condition = cond;
    loop_body = body;
}

/* Visits the current node.
 *
 * PARAMETERS:
 *   v       - the visitor
 */
void DoWhileStmt::accept(Visitor *v) { v->visit(this); }

/* Prints the current AST node.
 *
 * PARAMETERS:
 *   os      - the output stream
 */
void DoWhileStmt::dumpTo(std::ostream &os) {
    ASTNode::dumpTo(os);
    newLine(os);
    os << condition;

    newLine(os);
    os << loop_body << ")";
    decIndent(os);
}





/* Creates a new ForStmt node.
 *
 * PARAMETERS:
 *   cond    - the test expression
 *   body    - the loop body
 *   l       - position in the source text
 */
ForStmt::ForStmt(VarDecl *vardecl_, Expr *expr2_, Expr *expr3_, Statement *body, Location *l) {

    setBasicInfo(For_Stmt, l);
    vardecl = vardecl_;
    expr1 = NULL;
    expr2 = expr2_;
    expr3 = expr3_;
    //condition = cond;
    loop_body = body;
}

ForStmt::ForStmt(Expr *expr1_, Expr *expr2_, Expr *expr3_, Statement *body, Location *l) {

    setBasicInfo(For_Stmt, l);
    vardecl = NULL;
    //if(expr1_)
    expr1 = expr1_;
    //if(expr2_)
    expr2 = expr2_;
    //if(expr3_)
    expr3 = expr3_;
    //condition = cond;
    loop_body = body;
}

ForStmt::ForStmt(Statement *body, Location *l) {

    setBasicInfo(For_Stmt, l);
    vardecl = NULL;
    expr1 = NULL;
    expr2 = NULL;
    expr3 = NULL;
    //condition = cond;
    loop_body = body;
}
/* Visits the current node.
 *
 * PARAMETERS:
 *   v       - the visitor
 */
void ForStmt::accept(Visitor *v) { v->visit(this); }

/* Prints the current AST node.
 *
 * PARAMETERS:
 *   os      - the output stream
 */
void ForStmt::dumpTo(std::ostream &os) {
    ASTNode::dumpTo(os);
    if(vardecl!=NULL){
        newLine(os);
        os << vardecl;
    }
    if(expr1!=NULL){
        newLine(os);
        os << expr1;
    }
    newLine(os);
    os << expr2;
    newLine(os);
    os << expr3;

    newLine(os);
    os << loop_body << ")";
    decIndent(os);
}




/* Creates a new BreakStmt node.
 *
 * PARAMETERS:
 *   l       - position in the source text
 */
BreakStmt::BreakStmt(Location *l) { setBasicInfo(BREAK_STMT, l); }

/* Visits the current node.
 *
 * PARAMETERS:
 *   v       - the visitor
 */
void BreakStmt::accept(Visitor *v) { v->visit(this); }

/* Prints the current AST node.
 *
 * PARAMETERS:
 *   os      - the output stream
 */
void BreakStmt::dumpTo(std::ostream &os) {
    ASTNode::dumpTo(os);
    newLine(os);
    decIndent(os);
}





/* Creates a new ContStmt node.
 *
 * PARAMETERS:
 *   l       - position in the source text
 */
ContStmt::ContStmt(Location *l) { setBasicInfo(CONT_STMT, l); }

/* Visits the current node.
 *
 * PARAMETERS:
 *   v       - the visitor
 */
void ContStmt::accept(Visitor *v) { v->visit(this); }

/* Prints the current AST node.
 *
 * PARAMETERS:
 *   os      - the output stream
 */
void ContStmt::dumpTo(std::ostream &os) {
    ASTNode::dumpTo(os);
    newLine(os);
    decIndent(os);
}
