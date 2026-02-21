#pragma once
#include "types.hpp"
#include <QWidget>
#include <string>
#include <vector>

class Calculator
{
public:
	std::string eval(const std::vector<LexedValue *> & infix) const;

private:
	std::vector<Expr *> infixToPostfix(const std::vector<LexedValue *> & expr) const;
	float eval(float a, float b, char op) const;
	int precedence(const QString & op) const;
	int precedence(char op) const;
};