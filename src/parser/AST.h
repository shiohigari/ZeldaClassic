#ifndef AST_H
#define AST_H

class AST;
// for flex and bison
#define YYSTYPE AST*

#ifdef _MSC_VER
#if (_MSC_VER <= 1600)
#define snprintf _snprintf
#endif
#endif

#include "y.tab.hpp"
#include "Compiler.h"
#include <list>
#include <vector>
#include <map>
#include <string>

using std::string;
using std::pair;
using std::map;
using std::vector;
using std::list;

#define RECURSIONLIMIT 30

extern string curfilename;
int go(const char *f);

// AST Subclasses.
class AST; // virtual
class ASTProgram;
class ASTFloat;
class ASTString;
// Statements
class ASTStmt; // virtual
class ASTBlock;
class ASTStmtAssign;
class ASTStmtIf;
class ASTStmtIfElse;
class ASTStmtSwitch;
class ASTSwitchCases;
class ASTStmtFor;
class ASTStmtWhile;
class ASTStmtDo;
class ASTStmtReturn;
class ASTStmtReturnVal;
class ASTStmtBreak;
class ASTStmtContinue;
class ASTStmtEmpty;
// Declarations
class ASTDecl; // virtual
class ASTScript;
class ASTDeclList;
class ASTImportDecl;
class ASTFuncDecl;
class ASTArrayDecl;
class ASTArrayList;
class ASTVarDecl;
class ASTVarDeclInitializer;
class ASTTypeDef;
// Expressions
class ASTExpr; // virtual
class ASTExprConst;
class ASTNumConstant;
class ASTBoolConstant;
class ASTStringConstant;
class ASTExprDot;
class ASTExprArrow;
class ASTExprArray;
class ASTFuncCall;
class ASTUnaryExpr; // virtual
class ASTExprNegate;
class ASTExprNot;
class ASTExprBitNot;
class ASTExprIncrement;
class ASTExprPreIncrement;
class ASTExprDecrement;
class ASTExprPreDecrement;
class ASTBinaryExpr; // virtual
class ASTLogExpr; // virtual
class ASTExprAnd;
class ASTExprOr;
class ASTRelExpr; // virtual
class ASTExprGT;
class ASTExprGE;
class ASTExprLT;
class ASTExprLE;
class ASTExprEQ;
class ASTExprNE;
class ASTAddExpr; // virtual
class ASTExprPlus;
class ASTExprMinus;
class ASTMultExpr; // virtual
class ASTExprTimes;
class ASTExprDivide;
class ASTExprModulo;
class ASTBitExpr; // virtual
class ASTExprBitAnd;
class ASTExprBitOr;
class ASTExprBitXor;
class ASTShiftExpr; // virtual
class ASTExprLShift;
class ASTExprRShift;
// Types
class ASTScriptType;
class ASTVarType;

class ASTVisitor
{
public:
    virtual ~ASTVisitor() {}
    virtual void caseDefault(void *param) = 0;
	// AST Subclasses
    virtual void caseProgram(ASTProgram&, void* param) {caseDefault(param);}
    virtual void caseProgram(ASTProgram& node) {caseProgram(node, NULL);}
    virtual void caseFloat(ASTFloat&, void* param) {caseDefault(param);}
    virtual void caseFloat(ASTFloat& node) {caseFloat(node, NULL);}
    virtual void caseString(ASTString&, void* param) {caseDefault(param);}
    virtual void caseString(ASTString& node) {caseString(node, NULL);}
	// Statements
    virtual void caseBlock(ASTBlock&, void* param) {caseDefault(param);}
    virtual void caseBlock(ASTBlock& node) {caseBlock(node, NULL);}
    virtual void caseStmtAssign(ASTStmtAssign&, void* param) {caseDefault(param);}
    virtual void caseStmtAssign(ASTStmtAssign& node) {caseStmtAssign(node, NULL);}
    virtual void caseStmtIf(ASTStmtIf&, void* param) {caseDefault(param);}
    virtual void caseStmtIf(ASTStmtIf& node) {caseStmtIf(node, NULL);}
    virtual void caseStmtIfElse(ASTStmtIfElse&, void* param) {caseDefault(param);}
    virtual void caseStmtIfElse(ASTStmtIfElse& node) {caseStmtIfElse(node, NULL);}
	virtual void caseStmtSwitch(ASTStmtSwitch&, void*  param) {caseDefault(param);}
	virtual void caseStmtSwitch(ASTStmtSwitch& node) {caseStmtSwitch(node, NULL);}
	virtual void caseSwitchCases(ASTSwitchCases&, void*  param) {caseDefault(param);}
	virtual void caseSwitchCases(ASTSwitchCases& node) {caseSwitchCases(node, NULL);}
    virtual void caseStmtFor(ASTStmtFor&, void* param) {caseDefault(param);}
    virtual void caseStmtFor(ASTStmtFor& node) {caseStmtFor(node, NULL);}
    virtual void caseStmtWhile(ASTStmtWhile&, void* param) {caseDefault(param);}
    virtual void caseStmtWhile(ASTStmtWhile& node) {caseStmtWhile(node, NULL);}
    virtual void caseStmtDo(ASTStmtDo&, void* param) {caseDefault(param);}
    virtual void caseStmtDo(ASTStmtDo& node) {caseStmtDo(node, NULL);}
    virtual void caseStmtReturn(ASTStmtReturn&, void* param) {caseDefault(param);}
    virtual void caseStmtReturn(ASTStmtReturn& node) {caseStmtReturn(node, NULL);}
    virtual void caseStmtReturnVal(ASTStmtReturnVal&, void* param) {caseDefault(param);}
    virtual void caseStmtReturnVal(ASTStmtReturnVal& node) {caseStmtReturnVal(node, NULL);}
    virtual void caseStmtBreak(ASTStmtBreak&, void* param) {caseDefault(param);}
    virtual void caseStmtBreak(ASTStmtBreak& node) {caseStmtBreak(node, NULL);}
    virtual void caseStmtContinue(ASTStmtContinue&, void* param) {caseDefault(param);}
    virtual void caseStmtContinue(ASTStmtContinue& node) {caseStmtContinue(node, NULL);}
    virtual void caseStmtEmpty(ASTStmtEmpty&, void* param) {caseDefault(param);}
    virtual void caseStmtEmpty(ASTStmtEmpty& node) {caseStmtEmpty(node, NULL);}
	// Declarations
    virtual void caseScript(ASTScript&, void* param) {caseDefault(param);}
    virtual void caseScript(ASTScript& node) {caseScript(node, NULL);}
    virtual void caseDeclList(ASTDeclList&, void* param) {caseDefault(param);}
    virtual void caseDeclList(ASTDeclList& node) {caseDeclList(node, NULL);}
    virtual void caseImportDecl(ASTImportDecl&, void* param) {caseDefault(param);}
    virtual void caseImportDecl(ASTImportDecl& node) {caseImportDecl(node, NULL);}
    virtual void caseFuncDecl(ASTFuncDecl&, void* param) {caseDefault(param);}
    virtual void caseFuncDecl(ASTFuncDecl& node) {caseFuncDecl(node, NULL);}
    virtual void caseArrayDecl(ASTArrayDecl&, void* param) {caseDefault(param);}
    virtual void caseArrayDecl(ASTArrayDecl& node) {caseArrayDecl(node, NULL);}
    virtual void caseArrayList(ASTArrayList&, void* param) {caseDefault(param);}
    virtual void caseArrayList(ASTArrayList& node) {caseArrayList(node, NULL);}
    virtual void caseVarDecl(ASTVarDecl&, void* param) {caseDefault(param);}
    virtual void caseVarDecl(ASTVarDecl& node) {caseVarDecl(node, NULL);}
    virtual void caseVarDeclInitializer(ASTVarDeclInitializer&, void* param) {caseDefault(param);}
    virtual void caseVarDeclInitializer(ASTVarDeclInitializer& node) {caseVarDeclInitializer(node, NULL);}
    virtual void caseTypeDef(ASTTypeDef&, void* param) {caseDefault(param);}
    virtual void caseTypeDef(ASTTypeDef& node) {caseTypeDef(node, NULL);}
	// Expressions
    virtual void caseExprConst(ASTExprConst&, void* param) {caseDefault(param);}
    virtual void caseExprConst(ASTExprConst& node) {caseExprConst(node, NULL);}
    virtual void caseNumConstant(ASTNumConstant&, void* param) {caseDefault(param);}
    virtual void caseNumConstant(ASTNumConstant& node) {caseNumConstant(node, NULL);}
    virtual void caseBoolConstant(ASTBoolConstant&, void* param) {caseDefault(param);}
    virtual void caseBoolConstant(ASTBoolConstant& node) {caseBoolConstant(node, NULL);}
    virtual void caseStringConstant(ASTStringConstant&, void* param) {caseDefault(param);}
    virtual void caseStringConstant(ASTStringConstant& node) {caseStringConstant(node, NULL);}
    virtual void caseExprDot(ASTExprDot&, void* param) {caseDefault(param);}
    virtual void caseExprDot(ASTExprDot& node) {caseExprDot(node, NULL);}
    virtual void caseExprArrow(ASTExprArrow&, void* param) {caseDefault(param);}
    virtual void caseExprArrow(ASTExprArrow& node) {caseExprArrow(node, NULL);}
    virtual void caseExprArray(ASTExprArray&, void* param) {caseDefault(param);}
    virtual void caseExprArray(ASTExprArray& node) {caseExprArray(node, NULL);}
    virtual void caseFuncCall(ASTFuncCall&, void* param) {caseDefault(param);}
    virtual void caseFuncCall(ASTFuncCall& node) {caseFuncCall(node, NULL);}
    virtual void caseExprNegate(ASTExprNegate&, void* param) {caseDefault(param);}
    virtual void caseExprNegate(ASTExprNegate& node) {caseExprNegate(node, NULL);}
    virtual void caseExprNot(ASTExprNot&, void* param) {caseDefault(param);}
    virtual void caseExprNot(ASTExprNot& node) {caseExprNot(node, NULL);}
    virtual void caseExprBitNot(ASTExprBitNot&, void* param) {caseDefault(param);}
    virtual void caseExprBitNot(ASTExprBitNot& node) {caseExprBitNot(node, NULL);}
    virtual void caseExprIncrement(ASTExprIncrement&, void* param) {caseDefault(param);}
    virtual void caseExprIncrement(ASTExprIncrement& node) {caseExprIncrement(node, NULL);}
    virtual void caseExprPreIncrement(ASTExprPreIncrement&, void* param) {caseDefault(param);}
    virtual void caseExprPreIncrement(ASTExprPreIncrement& node) {caseExprPreIncrement(node, NULL);}
    virtual void caseExprDecrement(ASTExprDecrement&, void* param) {caseDefault(param);}
    virtual void caseExprDecrement(ASTExprDecrement& node) {caseExprDecrement(node, NULL);}
    virtual void caseExprPreDecrement(ASTExprPreDecrement&, void* param) {caseDefault(param);}
    virtual void caseExprPreDecrement(ASTExprPreDecrement& node) {caseExprPreDecrement(node, NULL);}
    virtual void caseExprAnd(ASTExprAnd&, void* param) {caseDefault(param);}
    virtual void caseExprAnd(ASTExprAnd& node) {caseExprAnd(node, NULL);}
    virtual void caseExprOr(ASTExprOr&, void* param) {caseDefault(param);}
    virtual void caseExprOr(ASTExprOr& node) {caseExprOr(node, NULL);}
    virtual void caseExprGT(ASTExprGT&, void* param) {caseDefault(param);}
    virtual void caseExprGT(ASTExprGT& node) {caseExprGT(node, NULL);}
    virtual void caseExprGE(ASTExprGE&, void* param) {caseDefault(param);}
    virtual void caseExprGE(ASTExprGE& node) {caseExprGE(node, NULL);}
    virtual void caseExprLT(ASTExprLT&, void* param) {caseDefault(param);}
    virtual void caseExprLT(ASTExprLT& node) {caseExprLT(node, NULL);}
    virtual void caseExprLE(ASTExprLE&, void* param) {caseDefault(param);}
    virtual void caseExprLE(ASTExprLE& node) {caseExprLE(node, NULL);}
    virtual void caseExprEQ(ASTExprEQ&, void* param) {caseDefault(param);}
    virtual void caseExprEQ(ASTExprEQ& node) {caseExprEQ(node, NULL);}
    virtual void caseExprNE(ASTExprNE&, void* param) {caseDefault(param);}
    virtual void caseExprNE(ASTExprNE& node) {caseExprNE(node, NULL);}
    virtual void caseExprPlus(ASTExprPlus&, void* param) {caseDefault(param);}
    virtual void caseExprPlus(ASTExprPlus& node) {caseExprPlus(node, NULL);}
    virtual void caseExprMinus(ASTExprMinus&, void* param) {caseDefault(param);}
    virtual void caseExprMinus(ASTExprMinus& node) {caseExprMinus(node, NULL);}
    virtual void caseExprTimes(ASTExprTimes&, void* param) {caseDefault(param);}
    virtual void caseExprTimes(ASTExprTimes& node) {caseExprTimes(node, NULL);}
    virtual void caseExprDivide(ASTExprDivide&, void* param) {caseDefault(param);}
    virtual void caseExprDivide(ASTExprDivide& node) {caseExprDivide(node, NULL);}
    virtual void caseExprModulo(ASTExprModulo&, void* param) {caseDefault(param);}
    virtual void caseExprModulo(ASTExprModulo& node) {caseExprModulo(node, NULL);}
    virtual void caseExprBitAnd(ASTExprBitAnd&, void* param) {caseDefault(param);}
    virtual void caseExprBitAnd(ASTExprBitAnd& node) {caseExprBitAnd(node, NULL);}
    virtual void caseExprBitOr(ASTExprBitOr&, void* param) {caseDefault(param);}
    virtual void caseExprBitOr(ASTExprBitOr& node) {caseExprBitOr(node, NULL);}
    virtual void caseExprBitXor(ASTExprBitXor&, void* param) {caseDefault(param);}
    virtual void caseExprBitXor(ASTExprBitXor& node) {caseExprBitXor(node, NULL);}
    virtual void caseExprLShift(ASTExprLShift&, void* param) {caseDefault(param);}
    virtual void caseExprLShift(ASTExprLShift& node) {caseExprLShift(node, NULL);}
    virtual void caseExprRShift(ASTExprRShift&, void* param) {caseDefault(param);}
    virtual void caseExprRShift(ASTExprRShift& node) {caseExprRShift(node, NULL);}
	// Types
	virtual void caseScriptType(ASTScriptType&, void* param) {caseDefault(param);}
	virtual void caseScriptType(ASTScriptType& node) {caseScriptType(node, NULL);}
    virtual void caseVarType(ASTVarType&, void* param) {caseDefault(param);}
    virtual void caseVarType(ASTVarType& node) {caseVarType(node, NULL);}
};

//////////////////////////////////////////////////////////////////////////////
class LocationData
{
public:
    LocationData(YYLTYPE loc)
    {
        first_line = loc.first_line;
        last_line = loc.last_line;
        first_column = loc.first_column;
        last_column = loc.last_column;
        fname = curfilename;
    }
    int first_line;
    int last_line;
    int first_column;
    int last_column;
    string fname;
};

////////////////////////////////////////////////////////////////

class AST
{
public:
    AST(LocationData const& location) : loc(location) {}
	AST(AST const& base) : loc(base.loc) {}
	AST& operator=(AST const& rhs);

	virtual AST* clone() const = 0;
    LocationData const &getLocation() const {return loc;}
    LocationData &getLocation() {return loc;}
    virtual void execute(ASTVisitor &visitor, void *param)=0;
	virtual void execute(ASTVisitor &visitor) {execute(visitor, NULL);}
private:
    LocationData loc;
};

class ASTProgram : public AST
{
public:
    ASTProgram(LocationData const& location);
	ASTProgram(ASTProgram const& base);
	~ASTProgram();
	ASTProgram* clone() const {return new ASTProgram(*this);}

    void execute(ASTVisitor &visitor, void *param) {visitor.caseProgram(*this, param);}
    void execute(ASTVisitor &visitor) {visitor.caseProgram(*this);}

	void addDeclaration(ASTDecl* declaration);
	ASTProgram& merge(ASTProgram& other);

	// Public since we'll be clearing them and such.
	vector<ASTImportDecl*> imports;
	vector<ASTVarDecl*> variables;
	vector<ASTArrayDecl*> arrays;
	vector<ASTFuncDecl*> functions;
	vector<ASTTypeDef*> types;
	vector<ASTScript*> scripts;
};

class ASTFloat : public AST
{
public:
    ASTFloat(char *Value, int Type, LocationData Loc);
    ASTFloat(const char *Value, int Type, LocationData Loc);
    ASTFloat(string Value, int Type, LocationData Loc);
    ASTFloat(long Value, int Type, LocationData Loc);
	ASTFloat* clone() const;
    string getValue() const {return val;}
    pair<string,string> parseValue();
    int getType() const {return type;}
    void execute(ASTVisitor &visitor, void *param) {visitor.caseFloat(*this, param);}
    void execute(ASTVisitor &visitor) {visitor.caseFloat(*this);}
    void set_negative(bool neg) {negative = neg;}
    static const int TYPE_DECIMAL = 0;
    static const int TYPE_BINARY = 1;
    static const int TYPE_HEX = 2;
private:
    int type;
    string val;
    bool negative;
};

class ASTString : public AST
{
public:
	ASTString(const char *strval, LocationData Loc);
    ASTString(string Str, LocationData Loc);
	ASTString* clone() const;
    string getValue() const {return str;}
    void execute(ASTVisitor &visitor, void *param) {visitor.caseString(*this, param);}
    void execute(ASTVisitor &visitor) {visitor.caseString(*this);}
private:
    string str;
};

////////////////////////////////////////////////////////////////
// Statements

class ASTStmt : public AST
{
public:
    ASTStmt(LocationData const& location) : AST(location) {}
	ASTStmt(ASTStmt const& base) : AST(base) {}
	ASTStmt& operator=(ASTStmt const& rhs);
	virtual ASTStmt* clone() const = 0;
};

class ASTBlock : public ASTStmt
{
public:
    ASTBlock(LocationData Loc) : ASTStmt(Loc), statements() {}
    ~ASTBlock();
	ASTBlock* clone() const;

    list<ASTStmt*> const &getStatements() const {return statements;}
    list<ASTStmt*> &getStatements() {return statements;}
    void addStatement(ASTStmt *Stmt);
    void execute(ASTVisitor &visitor, void *param) {visitor.caseBlock(*this, param);}
    void execute(ASTVisitor &visitor) {visitor.caseBlock(*this);}
private:
    list<ASTStmt*> statements;
};

class ASTStmtAssign : public ASTStmt
{
public:
    ASTStmtAssign(ASTStmt *Lval, ASTExpr *Rval, LocationData Loc) : ASTStmt(Loc), lval(Lval), rval(Rval) {}
    ~ASTStmtAssign();
	ASTStmtAssign* clone() const;

    ASTStmt *getLVal() const {return lval;}
    ASTExpr *getRVal() const {return rval;}
    void execute(ASTVisitor &visitor, void *param) {visitor.caseStmtAssign(*this, param);}
    void execute(ASTVisitor &visitor) {visitor.caseStmtAssign(*this);}
private:
    ASTStmt *lval;
    ASTExpr *rval;
    //NOT IMPLEMENTED; DO NOT USE
    ASTStmtAssign(ASTStmtAssign &);
    ASTStmtAssign &operator=(ASTStmtAssign &);
};

class ASTStmtIf : public ASTStmt
{
public:
    ASTStmtIf(ASTExpr *Cond, ASTStmt *Stmt, LocationData Loc) : ASTStmt(Loc), cond(Cond), stmt(Stmt) {}
    virtual ~ASTStmtIf();
	ASTStmtIf* clone() const;

    ASTExpr *getCondition() const {return cond;}
    ASTStmt *getStmt() const {return stmt;}
    void execute(ASTVisitor &visitor, void *param) {return visitor.caseStmtIf(*this, param);}
    void execute(ASTVisitor &visitor) {return visitor.caseStmtIf(*this);}
private:
    ASTExpr *cond;
    ASTStmt *stmt;
    //NOT IMPLEMENTED; DO NOT USE
    ASTStmtIf(ASTStmtIf &);
    ASTStmtIf &operator=(ASTStmtIf &);
};

class ASTStmtIfElse : public ASTStmtIf
{
public:
    ASTStmtIfElse(ASTExpr *Cond, ASTStmt *Ifstmt, ASTStmt *Elsestmt, LocationData Loc);
    ~ASTStmtIfElse();
	ASTStmtIfElse* clone() const;

    ASTStmt *getElseStmt() const {return elsestmt;}
    void execute(ASTVisitor &visitor, void *param) {visitor.caseStmtIfElse(*this, param);}
    void execute(ASTVisitor &visitor) {visitor.caseStmtIfElse(*this);}
private:
    ASTStmt *elsestmt;
    //NOT IMPLEMENTED; DO NOT USE
    ASTStmtIfElse(ASTStmtIfElse &);
    ASTStmtIfElse &operator=(ASTStmtIfElse &);
};

class ASTStmtSwitch : public ASTStmt
{
public:
	ASTStmtSwitch(LocationData Loc) : ASTStmt(Loc), key(NULL), cases() {}
	~ASTStmtSwitch();
	ASTStmtSwitch* clone() const;

	void execute(ASTVisitor& visitor, void* param) {visitor.caseStmtSwitch(*this, param);}
	void execute(ASTVisitor& visitor) {visitor.caseStmtSwitch(*this);}
	void setKey(ASTExpr* k) {key = k;}
	ASTExpr* getKey() const {return key;}
	void addCases(ASTSwitchCases* c) {cases.push_back(c);}
	vector<ASTSwitchCases*> & getCases() {return cases;}
	vector<ASTSwitchCases*> const & getCases() const {return cases;}
private:
	ASTExpr* key;
	vector<ASTSwitchCases*> cases;
};

class ASTSwitchCases : public AST
{
public:
	ASTSwitchCases(LocationData Loc) : AST(Loc), isDefault(false), cases() {}
	~ASTSwitchCases();
	ASTSwitchCases* clone() const;

	void execute(ASTVisitor& visitor, void* param) {visitor.caseSwitchCases(*this, param);}
	void execute(ASTVisitor& visitor) {visitor.caseSwitchCases(*this);}
	void addCase(ASTExprConst* expr) {cases.push_back(expr);}
	vector<ASTExprConst*> & getCases() {return cases;}
	vector<ASTExprConst*> const & getCases() const {return cases;}
	void addDefaultCase() {isDefault = true;}
	bool isDefaultCase() const {return isDefault;}
	void setBlock(ASTBlock* b) {block = b;}
	ASTBlock* getBlock() const {return block;}
private:
	bool isDefault;
	vector<ASTExprConst*> cases;
	ASTBlock* block;
};


class ASTStmtFor : public ASTStmt
{
public:
    ASTStmtFor(ASTStmt *Prec, ASTExpr *Term, ASTStmt *Incr, ASTStmt *Stmt, LocationData Loc);
    ~ASTStmtFor();
	ASTStmtFor* clone() const;

    ASTStmt *getPrecondition() const {return prec;}
    ASTExpr *getTerminationCondition() const {return term;}
    ASTStmt *getIncrement() const {return incr;}
    ASTStmt *getStmt() const {return stmt;}
    void execute(ASTVisitor &visitor, void *param) {return visitor.caseStmtFor(*this, param);}
    void execute(ASTVisitor &visitor) {return visitor.caseStmtFor(*this);}
private:
    ASTStmt *prec;
    ASTExpr *term;
    ASTStmt *incr;
    ASTStmt *stmt;
    //NOT IMPLEMENTED; DO NOT USE
    ASTStmtFor(ASTStmtFor &);
    ASTStmtFor &operator=(ASTStmtFor &);
};

class ASTStmtWhile : public ASTStmt
{
public:
    ASTStmtWhile(ASTExpr *Cond, ASTStmt *Stmt, LocationData Loc);
    ~ASTStmtWhile();
	ASTStmtWhile* clone() const;

    ASTExpr *getCond() const {return cond;}
    ASTStmt *getStmt() const {return stmt;}
    void execute(ASTVisitor &visitor, void *param) {visitor.caseStmtWhile(*this, param);}
    void execute(ASTVisitor &visitor) {visitor.caseStmtWhile(*this);}
private:
    ASTExpr *cond;
    ASTStmt *stmt;
    //NOT IMPLEMENTED; DO NOT USE
    ASTStmtWhile(ASTStmtWhile &);
    ASTStmtWhile &operator=(ASTStmtWhile &);
};

class ASTStmtDo : public ASTStmt
{
public:
    ASTStmtDo(ASTExpr *Cond, ASTStmt *Stmt, LocationData Loc);
    ~ASTStmtDo();
	ASTStmtDo* clone() const;
	
    ASTExpr *getCond() const {return cond;}
    ASTStmt *getStmt() const {return stmt;}
    void execute(ASTVisitor &visitor, void *param) {visitor.caseStmtDo(*this, param);}
    void execute(ASTVisitor &visitor) {visitor.caseStmtDo(*this);}
private:
    ASTExpr *cond;
    ASTStmt *stmt;
    //NOT IMPLEMENTED; DO NOT USE
    ASTStmtDo(ASTStmtDo &);
    ASTStmtDo &operator=(ASTStmtDo &);
};

class ASTStmtReturn : public ASTStmt
{
public:
    ASTStmtReturn(LocationData Loc) : ASTStmt(Loc) {}
	ASTStmtReturn* clone() const;

    void execute(ASTVisitor &visitor, void *param) {visitor.caseStmtReturn(*this, param);}
    void execute(ASTVisitor &visitor) {visitor.caseStmtReturn(*this);}
private:
    //NOT IMPLEMENTED; DO NOT USE
    ASTStmtReturn(ASTStmtReturn &);
    ASTStmtReturn &operator=(ASTStmtReturn &);
};

class ASTStmtReturnVal : public ASTStmt
{
public:
    ASTStmtReturnVal(ASTExpr *Retval, LocationData Loc) : ASTStmt(Loc), retval(Retval) {}
    ~ASTStmtReturnVal();
	ASTStmtReturnVal* clone() const;

    ASTExpr *getReturnValue() const {return retval;}
    void execute(ASTVisitor &visitor, void *param) {visitor.caseStmtReturnVal(*this, param);}
    void execute(ASTVisitor &visitor) {visitor.caseStmtReturnVal(*this);}
private:
    ASTExpr *retval;
    //NOT IMPLEMENTED; DO NOT USE
    ASTStmtReturnVal(ASTStmtReturnVal &);
    ASTStmtReturnVal &operator=(ASTStmtReturnVal &);
};

class ASTStmtBreak : public ASTStmt
{
public:
    ASTStmtBreak(LocationData Loc) : ASTStmt(Loc) {}
	ASTStmtBreak* clone() const;

    void execute(ASTVisitor &visitor, void *param) {visitor.caseStmtBreak(*this, param);}
    void execute(ASTVisitor &visitor) {visitor.caseStmtBreak(*this);}
private:
    //NOT IMPLEMENTED; DO NOT USE
    ASTStmtBreak(ASTStmtBreak &);
    ASTStmtBreak &operator=(ASTStmtBreak &);
};

class ASTStmtContinue : public ASTStmt
{
public:
    ASTStmtContinue(LocationData Loc) : ASTStmt(Loc) {}
	ASTStmtContinue* clone() const;

    void execute(ASTVisitor &visitor, void *param) {visitor.caseStmtContinue(*this, param);}
    void execute(ASTVisitor &visitor) {visitor.caseStmtContinue(*this);}
private:
    //NOT IMPLEMENTED; DO NOT USE
    ASTStmtContinue(ASTStmtContinue &);
    ASTStmtContinue &operator=(ASTStmtContinue &);
};

class ASTStmtEmpty : public ASTStmt
{
public:
    ASTStmtEmpty(LocationData Loc) : ASTStmt(Loc) {}
	ASTStmtEmpty* clone() const;

    void execute(ASTVisitor &visitor, void *param) {visitor.caseStmtEmpty(*this, param);}
    void execute(ASTVisitor &visitor) {visitor.caseStmtEmpty(*this);}
private:
    //NOT IMPLEMENTED; DO NOT USE
    ASTStmtEmpty(ASTStmtEmpty &);
    ASTStmtEmpty &operator=(ASTStmtEmpty&);
};

////////////////////////////////////////////////////////////////
// Declarations

enum ASTDeclClassId
{
	ASTDECL_CLASSID_NONE,
	ASTDECL_CLASSID_SCRIPT,
	ASTDECL_CLASSID_IMPORT,
	ASTDECL_CLASSID_CONSTANT,
	ASTDECL_CLASSID_FUNCTION,
	ASTDECL_CLASSID_ARRAY,
	ASTDECL_CLASSID_VARIABLE,
	ASTDECL_CLASSID_TYPE
};

class ASTDecl : public ASTStmt
{
public:
    ASTDecl(LocationData Loc) : ASTStmt(Loc) {}
    virtual ~ASTDecl() {}
	virtual ASTDecl* clone() const = 0;
	virtual ASTDeclClassId declarationClassId() const {return ASTDECL_CLASSID_NONE;}
private:
    //NOT IMPLEMENTED; DO NOT USE
    ASTDecl(ASTDecl &);
    ASTDecl &operator=(ASTDecl &);
};

class ASTScript : public ASTDecl
{
public:
    ASTScript(ASTScriptType *Type, string Name, ASTDeclList *Sblock, LocationData Loc);
	virtual ~ASTScript();
	ASTScript* clone() const;
    ASTDeclList *getScriptBlock() const {return sblock;}
    ASTScriptType *getType() const {return type;}
    string getName() const {return name;}
    void execute(ASTVisitor &visitor, void *param) {visitor.caseScript(*this, param);}
    void execute(ASTVisitor &visitor) {visitor.caseScript(*this);}
	ASTDeclClassId declarationClassId() const {return ASTDECL_CLASSID_SCRIPT;}
private:
    ASTScriptType *type;
    string name;
    ASTDeclList *sblock;
};

class ASTDeclList : public AST
{
public:
    ASTDeclList(LocationData Loc) : AST(Loc), decls() {}
    ~ASTDeclList();
	ASTDeclList* clone() const;

    void addDeclaration(ASTDecl *newdecl);
    list<ASTDecl *> &getDeclarations() {return decls;}
    void execute(ASTVisitor &visitor, void *param) {visitor.caseDeclList(*this, param);}
    void execute(ASTVisitor &visitor) {visitor.caseDeclList(*this);}
private:
    list<ASTDecl *> decls;
};

class ASTImportDecl : public ASTDecl
{
public:
    ASTImportDecl(string file, LocationData Loc) : ASTDecl(Loc), filename(file) {}
	ASTImportDecl* clone() const;
    
    string getFilename() const {return filename;}
    void execute(ASTVisitor &visitor, void *param) {visitor.caseImportDecl(*this,param);}
    void execute(ASTVisitor &visitor) {visitor.caseImportDecl(*this);}
	ASTDeclClassId declarationClassId() const {return ASTDECL_CLASSID_IMPORT;}
private:
    string filename;
    //NOT IMPLEMENTED; DO NOT USE
    ASTImportDecl(ASTImportDecl &);
    ASTImportDecl &operator=(ASTImportDecl &);
};

class ASTFuncDecl : public ASTDecl
{
public:
    ASTFuncDecl(LocationData Loc) : ASTDecl(Loc), params() {}
    ~ASTFuncDecl();
	ASTFuncDecl* clone() const;
    
    void setName(string n) {name = n;}
    void setReturnType(ASTVarType *type) {rettype = type;}
    void setBlock(ASTBlock *b) {block = b;}
    
    void addParam(ASTVarDecl *param);
    list<ASTVarDecl *> const &getParams() const {return params;}
    list<ASTVarDecl *> &getParams() {return params;}
    ASTVarType *getReturnType() const {return rettype;}
    ASTBlock *getBlock() const {return block;}
    string getName() const {return name;}
    
    void execute(ASTVisitor &visitor, void *param) {visitor.caseFuncDecl(*this, param);}
    void execute(ASTVisitor &visitor) {visitor.caseFuncDecl(*this);}
	ASTDeclClassId declarationClassId() const {return ASTDECL_CLASSID_FUNCTION;}
private:
    string name;
    list<ASTVarDecl *> params;
    ASTVarType *rettype;
    ASTBlock *block;
};

class ASTArrayDecl : public ASTDecl
{
public:
    ASTArrayDecl(ASTVarType *Type, string Name, ASTExpr *Size, ASTArrayList *List, LocationData Loc);
    ~ASTArrayDecl();
	ASTArrayDecl* clone() const;

    ASTVarType *getType() const {return type;}
    string getName() const {return name;}

    ASTExpr *getSize() const {return size;}
    ASTArrayList *getList() const {return list;}
    void execute(ASTVisitor &visitor, void *param) {visitor.caseArrayDecl(*this, param);}
    void execute(ASTVisitor &visitor) {visitor.caseArrayDecl(*this);}
	ASTDeclClassId declarationClassId() const {return ASTDECL_CLASSID_ARRAY;}
private:
    string name;
    ASTArrayList *list;
    ASTExpr *size;
    ASTVarType *type;
    //NOT IMPLEMENTED; DO NOT USE
    ASTArrayDecl(ASTArrayDecl &);
    ASTArrayDecl &operator=(ASTArrayDecl &);
};

class ASTArrayList : public AST
{
public:
    ASTArrayList(LocationData Loc) : AST(Loc), listIsString(false) {}
    ~ASTArrayList();
	ASTArrayList* clone() const;

    list<ASTExpr *> const &getList() const {return exprs;}
    list<ASTExpr *> &getList() {return exprs;}

    void addParam(ASTExpr *expr);
	void addString(string const & str);
    bool isString() const {return listIsString;}
    void makeString() {listIsString = true;}

    // Just to allow us to instantiate the object.
    void execute(ASTVisitor&, void *) {}
    void execute(ASTVisitor&) {}
private:
    list<ASTExpr *> exprs;
    bool listIsString;
    //NOT IMPLEMENTED
    ASTArrayList(ASTArrayList &);
    ASTArrayList &operator=(ASTArrayList &);
};

class ASTVarDecl : public ASTDecl
{
public:
    ASTVarDecl(ASTVarType *Type, string Name, LocationData Loc) : ASTDecl(Loc), type(Type), name(Name) {}
    virtual ~ASTVarDecl();
	virtual ASTVarDecl* clone() const;

    ASTVarType *getType() const {return type;}
    string getName() const {return name;}
    void execute(ASTVisitor &visitor, void* param) {visitor.caseVarDecl(*this, param);}
    void execute(ASTVisitor &visitor) {visitor.caseVarDecl(*this);}
	ASTDeclClassId declarationClassId() const {return ASTDECL_CLASSID_VARIABLE;}
private:
    ASTVarType *type;
    string name;
};

class ASTVarDeclInitializer : public ASTVarDecl
{
public:
    ASTVarDeclInitializer(ASTVarType *Type, string Name, ASTExpr *Initial, LocationData Loc);
    ~ASTVarDeclInitializer();
	ASTVarDeclInitializer* clone() const;
    
    ASTExpr *getInitializer() const {return initial;}
    void execute(ASTVisitor &visitor, void *param) {visitor.caseVarDeclInitializer(*this, param);}
    void execute(ASTVisitor &visitor) {visitor.caseVarDeclInitializer(*this);}
private:
    ASTExpr *initial;
    //NOT IMPLEMENTED; DO NOT USE
    ASTVarDeclInitializer(ASTVarDeclInitializer &);
    ASTVarDeclInitializer &operator=(ASTVarDeclInitializer &);
};

class ASTTypeDef : public ASTDecl
{
public:
	ASTTypeDef(ASTVarType *type, string const& name, LocationData location) : ASTDecl(location), type(type), name(name) {}
	~ASTTypeDef();
	ASTTypeDef* clone() const;

	ASTVarType* getType() const {return type;}
	string getName() const {return name;}

    void execute(ASTVisitor &visitor, void *param) {visitor.caseTypeDef(*this, param);}
    void execute(ASTVisitor &visitor) {visitor.caseTypeDef(*this);}
	ASTDeclClassId declarationClassId() const {return ASTDECL_CLASSID_TYPE;}
private:
	ASTVarType* type;
	string name;
};

////////////////////////////////////////////////////////////////
// Expressions

// Partial or complete information about a given ASTExpr node's type and
// value. Gradually built up as the compilation progresses.
class ExprInfo
{
public:
	enum Type {UNKNOWN, DATA, VARIABLE, FUNCTION, SCOPE};

	static ExprInfo unknown;
	static ExprInfo data(ZVarType* dataType);
	static ExprInfo data(ZVarType* dataType, long dataValue);
	static ExprInfo variable(ZVarType* variableType, int variableId);
	static ExprInfo function(ZVarType* returnType, int functionId);
	static ExprInfo scope(Scope* scope);

	ExprInfo() : exprType(UNKNOWN), hasValue_(false), value(0L), valType(NULL), scope_(NULL) {}

	bool hasValue() const {return hasValue_;}
	Type getExprType() const {return exprType;}
	ZVarType const* getValueType() const {return valType;}
	void setValueType(ZVarType const* type) {valType = type;}
	void setValueType(ZVarType* type) {valType = (ZVarType const*)type;}

	long getDataValue() const {return exprType == DATA ? value : 0l;}
	void setDataValue(long v) {exprType = DATA; value = v; hasValue_ = true;}
	int getVariableId() const {return exprType == VARIABLE ? value : -1;}
	void setVariableId(int variableId) {exprType = VARIABLE; value = variableId; hasValue_ = true;}
	int getFunctionId() const {return exprType == FUNCTION ? value : -1;}
	void setFunctionId(int functionId) {exprType = FUNCTION; value = functionId; hasValue_ = true;}
	Scope* getScope() const {return scope_;}
	void setScope(Scope* scope) {exprType = SCOPE; scope_ = scope; hasValue_ = true;}

private:
	ExprInfo(Type type, bool hasValue, ZVarType* valType, long value, Scope* scope);

	Type exprType;
	ZVarType const* valType;
	bool hasValue_;
	long value;
	Scope* scope_;
};

class ASTExpr : public ASTStmt
{
public:
    ASTExpr(LocationData const& location) : ASTStmt(location) {}
	ASTExpr(ASTExpr const& base);
	ASTExpr& operator=(ASTExpr const& rhs);
	virtual ASTExpr* clone() const = 0;

	virtual bool isConstant() const = 0;

	ExprInfo& getInfo() {return info;}
	ExprInfo const& getInfo() const {return info;}
	void setInfo(ExprInfo const& i) {info = i;}

	// Convenience methods for info.
	bool hasValue() const {return info.hasValue();}
	long getDataValue() const {return info.getDataValue();}
	void setDataValue(long v) {info.setDataValue(v);}
	ZVarType const& getVarType() const {return *info.getValueType();}
	void setVarType(ZVarType const& type) {info.setValueType(&type);}
	void setVarType(ZVarType& type) {info.setValueType(&type);}
	void setVarType(ZVarType const* type) {info.setValueType(type);}
	void setVarType(ZVarType* type) {info.setValueType(type);}


private:
    ExprInfo info;
};

// Wrap around an expression to type it as constant.
class ASTExprConst : public ASTExpr
{
public:
    ASTExprConst(ASTExpr* content) : ASTExpr(content->getLocation()), content(content) {}
	ASTExprConst(ASTExpr* content, LocationData const& location) : ASTExpr(location), content(content) {}
	ASTExprConst(ASTExprConst const& base);
	ASTExprConst& operator=(ASTExprConst const& rhs);
	~ASTExprConst() {delete content;}
	ASTExprConst* clone() const {return new ASTExprConst(*this);}

	ASTExpr* getContent() const {return content;}
	bool isConstant() const {return true;}
    void execute(ASTVisitor &visitor, void *param) {visitor.caseExprConst(*this, param);}
    void execute(ASTVisitor &visitor) {visitor.caseExprConst(*this);}
private:
	ASTExpr* content;
};

class ASTNumConstant : public ASTExpr
{
public:
    ASTNumConstant(ASTFloat *value, LocationData Loc) : ASTExpr(Loc), val(value) {}
	ASTNumConstant(ASTNumConstant const& base);
	ASTNumConstant& operator=(ASTNumConstant const& rhs);
    ~ASTNumConstant() {delete val;}
	ASTNumConstant* clone() const {return new ASTNumConstant(*this);}

    ASTFloat* getValue() const {return val;}
	bool isConstant() const {return true;}
    void execute(ASTVisitor &visitor, void *param) {visitor.caseNumConstant(*this, param);}
    void execute(ASTVisitor &visitor) {visitor.caseNumConstant(*this);}
private:
    ASTFloat* val;
};

class ASTBoolConstant : public ASTExpr
{
public:
    ASTBoolConstant(bool Value, LocationData Loc) : ASTExpr(Loc), value(Value) {}
	ASTBoolConstant(ASTBoolConstant const& base);
	ASTBoolConstant& operator=(ASTBoolConstant const& base);
	ASTBoolConstant* clone() const {return new ASTBoolConstant(*this);}

    bool getValue() const {return value;}
	bool isConstant() const {return true;}
    void execute(ASTVisitor &visitor, void *param) {visitor.caseBoolConstant(*this, param);}
    void execute(ASTVisitor &visitor) {visitor.caseBoolConstant(*this);}
private:
    bool value;
};

class ASTStringConstant : public ASTExpr
{
public:
	ASTStringConstant(char const* str, LocationData const& location);
	ASTStringConstant(string const& str, LocationData const& location);
	ASTStringConstant(ASTString const& raw);
	ASTStringConstant(ASTStringConstant const& base);
	ASTStringConstant& operator=(ASTStringConstant const& rhs);
	ASTStringConstant* clone() const {return new ASTStringConstant(*this);}

	void execute (ASTVisitor& visitor, void* param) {visitor.caseStringConstant(*this, param);}
	void execute (ASTVisitor& visitor) {visitor.caseStringConstant(*this);}
	bool isConstant() const {return true;}
	string getValue() const {return str;}
private:
	string str;
};

class ASTExprDot : public ASTExpr
{
public:
    ASTExprDot(string const& nspace, string const& name, LocationData const& location);
	ASTExprDot(ASTExprDot const& base);
	ASTExprDot& operator=(ASTExprDot const& base);
	ASTExprDot* clone() const {return new ASTExprDot(*this);}

    string getName() const {return name;}
    string getNamespace() const {return nspace;}
	bool isConstant() const {return isConstant_;}
	void markConstant() {isConstant_ = true;}
    void execute(ASTVisitor &visitor, void *param) {visitor.caseExprDot(*this, param);}
    void execute(ASTVisitor &visitor) {visitor.caseExprDot(*this);}
private:
    string name;
    string nspace;
	bool isConstant_;
};

class ASTExprArrow : public ASTExpr
{
public:
    ASTExprArrow(ASTExpr* left, string const& right, LocationData const& location);
	ASTExprArrow(ASTExprArrow const& base);
	ASTExprArrow& operator=(ASTExprArrow const& rhs);
    ~ASTExprArrow();
	ASTExprArrow* clone() const {return new ASTExprArrow(*this);}

    ASTExpr* getLeft() const {return left;}
    string getRight() const {return right;}
    ASTExpr* getIndex() const {return index;}
    void setIndex(ASTExpr* e) {index = e;}
	bool isConstant() const {return false;}

    void execute(ASTVisitor &visitor, void *param) {visitor.caseExprArrow(*this, param);}
    void execute(ASTVisitor &visitor) {visitor.caseExprArrow(*this);}
private:
    ASTExpr* left;
    string right;
    ASTExpr* index;
};

class ASTExprArray : public ASTExpr
{
public:
    ASTExprArray(string const& nspace, string const& name, LocationData const& location);
	ASTExprArray(ASTExprArray const& base);
	ASTExprArray& operator=(ASTExprArray const& rhs);
    ~ASTExprArray() {delete index;}
	ASTExprArray* clone() const {return new ASTExprArray(*this);}

    string getNamespace() const {return nspace;}
    string getName() const {return name;}
    ASTExpr* getIndex() const {return index;}
    void setIndex(ASTExpr* e) {index = e;}
	bool isConstant() const {return false;}

    void execute(ASTVisitor &visitor, void *param) {visitor.caseExprArray(*this, param);}
    void execute(ASTVisitor &visitor) {visitor.caseExprArray(*this);}
private:
    string name;
    ASTExpr* index;
    string nspace;
};

class ASTFuncCall : public ASTExpr
{
public:
    ASTFuncCall(LocationData const& location);
	ASTFuncCall(ASTFuncCall const& base);
	ASTFuncCall& operator=(ASTFuncCall const& rhs);
    ~ASTFuncCall();
	ASTFuncCall* clone() const {return new ASTFuncCall(*this);}

    list<ASTExpr*> const &getParams() const {return params;}
    list<ASTExpr*> &getParams() {return params;}

    void setName(ASTExpr *n) {name = n;}
    ASTExpr* getName() const {return name;}
    void addParam(ASTExpr* param) {params.push_front(param);}
	bool isConstant() const {return false;}

    void execute(ASTVisitor& visitor, void* param) {visitor.caseFuncCall(*this, param);}
    void execute(ASTVisitor& visitor) {visitor.caseFuncCall(*this);}
private:
    ASTExpr* name;
    list<ASTExpr*> params;
};

class ASTUnaryExpr : public ASTExpr
{
public:
    ASTUnaryExpr(LocationData const& location) : ASTExpr(location) {}
	ASTUnaryExpr(ASTUnaryExpr const& base);
	ASTUnaryExpr& operator=(ASTUnaryExpr const& rhs);
    virtual ~ASTUnaryExpr() {delete operand;}
	virtual ASTUnaryExpr* clone() const = 0;

    ASTExpr* getOperand() const {return operand;}
    void setOperand(ASTExpr* e) {operand = e;}
	virtual bool isConstant() const {return operand->isConstant();}
private:
    ASTExpr* operand;
};

class ASTExprNegate : public ASTUnaryExpr
{
public:
    ASTExprNegate(LocationData const& location) : ASTUnaryExpr(location) {}
	ASTExprNegate* clone() const {return new ASTExprNegate(*this);}

    void execute(ASTVisitor& visitor, void* param) {visitor.caseExprNegate(*this, param);}
    void execute(ASTVisitor& visitor) {visitor.caseExprNegate(*this);}
};

class ASTExprNot : public ASTUnaryExpr
{
public:
    ASTExprNot(LocationData const& location) : ASTUnaryExpr(location) {}
	ASTExprNot* clone() const {return new ASTExprNot(*this);}

    void execute(ASTVisitor& visitor, void* param) {visitor.caseExprNot(*this, param);}
    void execute(ASTVisitor& visitor) {visitor.caseExprNot(*this);}
};

class ASTExprBitNot : public ASTUnaryExpr
{
public:
    ASTExprBitNot(LocationData const& location) : ASTUnaryExpr(location) {}
	ASTExprBitNot* clone() const {return new ASTExprBitNot(*this);}

    void execute(ASTVisitor& visitor, void* param) {visitor.caseExprBitNot(*this, param);}
    void execute(ASTVisitor& visitor) {visitor.caseExprBitNot(*this);}
};

class ASTExprIncrement : public ASTUnaryExpr
{
public:
    ASTExprIncrement(LocationData const& location) : ASTUnaryExpr(location) {}
	ASTExprIncrement* clone() const {return new ASTExprIncrement(*this);}

    void execute(ASTVisitor& visitor, void* param) {visitor.caseExprIncrement(*this, param);}
    void execute(ASTVisitor& visitor) {visitor.caseExprIncrement(*this);}
	bool isConstant() const {return false;}
};

class ASTExprPreIncrement : public ASTUnaryExpr
{
public:
    ASTExprPreIncrement(LocationData const& location) : ASTUnaryExpr(location) {}
	ASTExprPreIncrement* clone() const {return new ASTExprPreIncrement(*this);}

    void execute(ASTVisitor& visitor, void* param) {visitor.caseExprPreIncrement(*this, param);}
    void execute(ASTVisitor& visitor) {visitor.caseExprPreIncrement(*this);}
	bool isConstant() const {return false;}
};

class ASTExprDecrement : public ASTUnaryExpr
{
public:
    ASTExprDecrement(LocationData const& location) : ASTUnaryExpr(location) {}
	ASTExprDecrement* clone() const {return new ASTExprDecrement(*this);}

    void execute(ASTVisitor& visitor, void* param) {visitor.caseExprDecrement(*this, param);}
    void execute(ASTVisitor& visitor) {visitor.caseExprDecrement(*this);}
	bool isConstant() const {return false;}
};

class ASTExprPreDecrement : public ASTUnaryExpr
{
public:
    ASTExprPreDecrement(LocationData const& location) : ASTUnaryExpr(location) {}
	ASTExprPreDecrement* clone() const {return new ASTExprPreDecrement(*this);}

    void execute(ASTVisitor& visitor, void* param) {visitor.caseExprPreDecrement(*this, param);}
    void execute(ASTVisitor& visitor) {visitor.caseExprPreDecrement(*this);}
	bool isConstant() const {return false;}
};

class ASTBinaryExpr : public ASTExpr
{
public:
    ASTBinaryExpr(LocationData const& location) : ASTExpr(location) {}
	ASTBinaryExpr(ASTBinaryExpr const& base);
	ASTBinaryExpr& operator=(ASTBinaryExpr const& rhs);
    virtual ~ASTBinaryExpr();
	virtual ASTBinaryExpr* clone() const = 0;

    ASTExpr* getFirstOperand() const {return first;}
    void setFirstOperand(ASTExpr* e) {first = e;}
    ASTExpr* getSecondOperand() const {return second;}
    void setSecondOperand(ASTExpr* e) {second = e;}
	bool isConstant() const {return first->isConstant() && second->isConstant();}
private:
    ASTExpr* first;
    ASTExpr* second;
};

class ASTLogExpr : public ASTBinaryExpr
{
public:
    ASTLogExpr(LocationData const& location) : ASTBinaryExpr(location) {}
	virtual ASTLogExpr* clone() const = 0;
};

class ASTExprAnd : public ASTLogExpr
{
public:
    ASTExprAnd(LocationData const& location) : ASTLogExpr(location) {}
	ASTExprAnd* clone() const {return new ASTExprAnd(*this);}

    void execute(ASTVisitor& visitor, void* param) {visitor.caseExprAnd(*this, param);}
    void execute(ASTVisitor& visitor) {visitor.caseExprAnd(*this);}
};

class ASTExprOr : public ASTLogExpr
{
public:
    ASTExprOr(LocationData const& location) : ASTLogExpr(location) {}
	ASTExprOr* clone() const {return new ASTExprOr(*this);}

    void execute(ASTVisitor& visitor, void* param) {visitor.caseExprOr(*this, param);}
    void execute(ASTVisitor& visitor) {visitor.caseExprOr(*this);}
};

class ASTRelExpr : public ASTBinaryExpr
{
public:
    ASTRelExpr(LocationData const& location) : ASTBinaryExpr(location) {}
	virtual ASTRelExpr* clone() const = 0;
};

class ASTExprGT : public ASTRelExpr
{
public:
    ASTExprGT(LocationData const& location) : ASTRelExpr(location) {}
	ASTExprGT* clone() const {return new ASTExprGT(*this);}

    void execute(ASTVisitor& visitor, void* param) {visitor.caseExprGT(*this, param);}
    void execute(ASTVisitor& visitor) {visitor.caseExprGT(*this);}
};

class ASTExprGE : public ASTRelExpr
{
public:
    ASTExprGE(LocationData const& location) : ASTRelExpr(location) {}
	ASTExprGE* clone() const {return new ASTExprGE(*this);}

    void execute(ASTVisitor &visitor, void *param) {visitor.caseExprGE(*this, param);}
    void execute(ASTVisitor &visitor) {visitor.caseExprGE(*this);}
};

class ASTExprLT : public ASTRelExpr
{
public:
    ASTExprLT(LocationData const& location) : ASTRelExpr(location) {}
	ASTExprLT* clone() const {return new ASTExprLT(*this);}

	void execute(ASTVisitor& visitor, void* param) {visitor.caseExprLT(*this, param);}
	void execute(ASTVisitor& visitor) {visitor.caseExprLT(*this);}
};

class ASTExprLE : public ASTRelExpr
{
public:
    ASTExprLE(LocationData const& location) : ASTRelExpr(location) {}
	ASTExprLE* clone() const {return new ASTExprLE(*this);}

    void execute(ASTVisitor& visitor, void* param) {visitor.caseExprLE(*this, param);}
    void execute(ASTVisitor& visitor) {visitor.caseExprLE(*this);}
};

class ASTExprEQ : public ASTRelExpr
{
public:
    ASTExprEQ(LocationData const& location) : ASTRelExpr(location) {}
	ASTExprEQ* clone() const {return new ASTExprEQ(*this);}

    void execute(ASTVisitor& visitor, void* param) {visitor.caseExprEQ(*this, param);}
    void execute(ASTVisitor& visitor) {visitor.caseExprEQ(*this);}
};

class ASTExprNE : public ASTRelExpr
{
public:
    ASTExprNE(LocationData const& location) : ASTRelExpr(location) {}
	ASTExprNE* clone() const {return new ASTExprNE(*this);}

    void execute(ASTVisitor& visitor, void* param) {visitor.caseExprNE(*this, param);}
    void execute(ASTVisitor& visitor) {visitor.caseExprNE(*this);}
};

class ASTAddExpr : public ASTBinaryExpr
{
public:
    ASTAddExpr(LocationData const& location) : ASTBinaryExpr(location) {}
	virtual ASTAddExpr* clone() const = 0;
};

class ASTExprPlus : public ASTAddExpr
{
public:
    ASTExprPlus(LocationData const& location) : ASTAddExpr(location) {}
	ASTExprPlus* clone() const {return new ASTExprPlus(*this);}

    void execute(ASTVisitor& visitor, void* param) {visitor.caseExprPlus(*this, param);}
    void execute(ASTVisitor& visitor) {visitor.caseExprPlus(*this);}
};

class ASTExprMinus : public ASTAddExpr
{
public:
    ASTExprMinus(LocationData const& location) : ASTAddExpr(location) {}
	ASTExprMinus* clone() const {return new ASTExprMinus(*this);}

    void execute(ASTVisitor& visitor, void* param) {visitor.caseExprMinus(*this, param);}
    void execute(ASTVisitor& visitor) {visitor.caseExprMinus(*this);}
};

class ASTMultExpr : public ASTBinaryExpr
{
public:
    ASTMultExpr(LocationData const& location) : ASTBinaryExpr(location) {}
	virtual ASTMultExpr* clone() const = 0;
};

class ASTExprTimes : public ASTMultExpr
{
public:
    ASTExprTimes(LocationData const& location) : ASTMultExpr(location) {}
	ASTExprTimes* clone() const {return new ASTExprTimes(*this);}

    void execute(ASTVisitor& visitor, void* param) {visitor.caseExprTimes(*this, param);}
    void execute(ASTVisitor& visitor) {visitor.caseExprTimes(*this);}
};

class ASTExprDivide : public ASTMultExpr
{
public:
    ASTExprDivide(LocationData const& location) : ASTMultExpr(location) {}
	ASTExprDivide* clone() const {return new ASTExprDivide(*this);}

    void execute(ASTVisitor& visitor, void* param) {visitor.caseExprDivide(*this, param);}
    void execute(ASTVisitor& visitor) {visitor.caseExprDivide(*this);}
};

class ASTExprModulo : public ASTMultExpr
{
public:
    ASTExprModulo(LocationData const& location) : ASTMultExpr(location) {}
	ASTExprModulo* clone() const {return new ASTExprModulo(*this);}

    void execute(ASTVisitor& visitor, void* param) {visitor.caseExprModulo(*this, param);}
    void execute(ASTVisitor& visitor) {visitor.caseExprModulo(*this);}
};

class ASTBitExpr : public ASTBinaryExpr
{
public:
    ASTBitExpr(LocationData const& location) : ASTBinaryExpr(location) {}
	virtual ASTBitExpr* clone() const = 0;
};

class ASTExprBitAnd : public ASTBitExpr
{
public:
    ASTExprBitAnd(LocationData const& location) : ASTBitExpr(location) {}
	ASTExprBitAnd* clone() const {return new ASTExprBitAnd(*this);}

    void execute(ASTVisitor& visitor, void* param) {visitor.caseExprBitAnd(*this, param);}
    void execute(ASTVisitor& visitor) {visitor.caseExprBitAnd(*this);}
};

class ASTExprBitOr : public ASTBitExpr
{
public:
    ASTExprBitOr(LocationData const& location) : ASTBitExpr(location) {}
	ASTExprBitOr* clone() const {return new ASTExprBitOr(*this);}

    void execute(ASTVisitor& visitor, void* param) {visitor.caseExprBitOr(*this, param);}
    void execute(ASTVisitor& visitor) {visitor.caseExprBitOr(*this);}
};

class ASTExprBitXor : public ASTBitExpr
{
public:
    ASTExprBitXor(LocationData const& location) : ASTBitExpr(location) {}
	ASTExprBitXor* clone() const {return new ASTExprBitXor(*this);}

    void execute(ASTVisitor& visitor, void* param) {visitor.caseExprBitXor(*this, param);}
    void execute(ASTVisitor& visitor) {visitor.caseExprBitXor(*this);}

};

class ASTShiftExpr : public ASTBinaryExpr
{
public:
    ASTShiftExpr(LocationData const& location) : ASTBinaryExpr(location) {}
	virtual ASTShiftExpr* clone() const = 0;
};

class ASTExprLShift : public ASTShiftExpr
{
public:
    ASTExprLShift(LocationData const& location) : ASTShiftExpr(location) {}
	ASTExprLShift* clone() const {return new ASTExprLShift(*this);}

    void execute(ASTVisitor& visitor, void* param) {visitor.caseExprLShift(*this, param);}
    void execute(ASTVisitor& visitor) {visitor.caseExprLShift(*this);}
};

class ASTExprRShift : public ASTShiftExpr
{
public:
    ASTExprRShift(LocationData const& location) : ASTShiftExpr(location) {}
	ASTExprRShift* clone() const {return new ASTExprRShift(*this);}

    void execute(ASTVisitor& visitor, void* param) {visitor.caseExprRShift(*this, param);}
    void execute(ASTVisitor& visitor) {visitor.caseExprRShift(*this);}
};

// Types

class ASTScriptType : public AST
{
public:
	ASTScriptType(ScriptType Type, LocationData Loc) : AST(Loc), type(Type) {}
	ASTScriptType* clone() const {return new ASTScriptType(type, getLocation());}
	ScriptType getType() const {return type;}
    void execute(ASTVisitor &visitor, void *param) {visitor.caseScriptType(*this, param);}
    void execute(ASTVisitor &visitor) {visitor.caseScriptType(*this);}
private:
	ScriptType type;
};

class ASTVarType : public AST
{
public:
    ASTVarType(ZVarType const& type, LocationData Loc) : AST(Loc), type(type.clone()) {}
    ASTVarType(ZVarType* type, LocationData Loc) : AST(Loc), type(type) {}
	ASTVarType(ASTVarType const& base) : AST(base.getLocation()), type(base.type->clone()) {}
	~ASTVarType() {delete type;}
	ASTVarType* clone() const {return new ASTVarType(*this);}
	ASTVarType& operator=(ASTVarType const& base)
	{
		getLocation() = base.getLocation();
		type = base.type->clone();
	}
    void execute(ASTVisitor &visitor, void* param) {visitor.caseVarType(*this, param);}
    void execute(ASTVisitor &visitor) {visitor.caseVarType(*this);}
	ZVarType const& resolve(Scope& scope);
private:
	ZVarType* type;
};

#endif

