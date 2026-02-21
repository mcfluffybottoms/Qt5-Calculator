#pragma once
#include <QDebug>
#include <QObject>
#include <string>

enum LexToken {
    NUM,
    BKT_OPEN,
    BKT_CLOSED,
    OP
};

struct LexedValue {
public:
	LexedValue(LexToken t) : val(""), token(t) {}
	void addChar(const QString& suf) {
		val += suf;
	}
	void changeValue(const QString& v) {
        if(v == ")") {
            token = LexToken::BKT_CLOSED;
        } else if(v == "(") {
            token = LexToken::BKT_OPEN;
        }
		val = v;
	}
	QString getValue() const {
		return val;
	}
	int changeSign() {
		if(!isNum()) return 0;
		if(val == "") return 0;
		if(val.at(0) == '-') {
			val = val.remove(0, 1);
			return val.size() + 1;
		} else {
			val = "-" + val;
			return val.size() - 1;
		}
	}
	bool isNum() const {
		return token == LexToken::NUM;
	}
    bool isBrkClosed() const {
		return token == LexToken::BKT_CLOSED;
	}
    bool isBrkOpened() const {
		return token == LexToken::BKT_OPEN;
	}
    bool isOp() const {
		return token == LexToken::OP;
	}
private:
	QString val;
    LexToken token;
};

struct Expr {
	virtual bool isNum() = 0;
	virtual bool isOp() = 0;
	virtual bool isParenthesis() = 0;
	virtual int precedence() = 0;
	virtual ~Expr() = default;
};
struct Op : Expr {
	Op(char o)
		: op(o)
	{}
	bool isNum() override
	{
		return false;
	}
	bool isOp() override
	{
		return true;
	}
	bool isParenthesis() override
	{
		return op == '(' || op == ')';
	}
	int precedence() override
	{
		if (op == '+' || op == '-')
			return 1;
		else if (op == '*' || op == '/' || op == '%')
			return 2;
		else
			return -1;
	}
	char getOp()
	{
		return op;
	}

private:
	char op;
};
struct Num : Expr {
	Num(const std::string & s)
		: num(std::stof(s))
	{}
	Num(float f)
		: num(f)
	{}
	bool isNum() override
	{
		return true;
	}
	bool isOp() override
	{
		return false;
	}
	bool isParenthesis() override
	{
		return false;
	}
	int precedence() override
	{
		return -1;
	}
	float getNum()
	{
		return num;
	}

private:
	float num;
};