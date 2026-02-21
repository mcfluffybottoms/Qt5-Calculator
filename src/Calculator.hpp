#pragma once
#include "types.hpp"
#include <QWidget>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

class Calculator
{
public:
	std::string eval(const std::vector<LexedValue *> & infix)
	{
		if(infix.empty()) return "0.0";
		std::stack<float> stack;
		auto expr = infixToPostfix(infix);
		for (int i = 0; i < expr.size(); ++i)
		{
			auto e = expr[i];
			if (e->isOp())
			{
				if (stack.empty())
					return "ERROR!";
				auto a = stack.top();
				stack.pop();
				if (stack.empty())
					return "ERROR!";
				auto b = stack.top();
				stack.pop();
				if (!e->isOp())
				{
					std::cerr << "Not an operation.\n";
					return "ERROR!";
				}
				stack.push(eval(a, b, static_cast<Op *>(e)->getOp()));
			}
			else if (e->isNum())
			{
				stack.push(static_cast<Num *>(e)->getNum());
			}
			else
			{
				return 0;
			}
		}

		for (int i = 0; i < expr.size(); ++i)
		{
			if (expr[i] != nullptr)
			{
				delete expr[i];
			}
		}

		if (stack.empty())
		{
			return "ERROR!";
		}
		else
		{
			return std::to_string(stack.top());
		}
	}

private:
	std::vector<Expr *> infixToPostfix(const std::vector<LexedValue *> & expr)
	{
		std::stack<Expr *> stack;
		std::vector<Expr *> res;
		for (int i = 0; i < expr.size(); ++i)
		{
			auto e = expr[i];
			if (e->isNum())
			{
				res.push_back(new Num(e->getValue().toStdString()));
			}
			else if (e->getValue() == '(')
			{
				stack.push(new Op{'('});
			}
			else if (e->getValue() == ')')
			{
				while (!stack.empty() && !stack.top()->isParenthesis())
				{
					res.push_back(stack.top());
					stack.pop();
				}
				if (!stack.empty()) {
					if(stack.top()) delete stack.top();
					stack.pop();
				}
			}
			else
			{
				if (!e->isOp())
					continue;
				while (!stack.empty() && !stack.top()->isParenthesis() && stack.top()->precedence() >= precedence(e->getValue()))
				{
					res.push_back(stack.top());
					stack.pop();
				}
				stack.push(new Op{e->getValue().toStdString().at(0)});
			}
		}


		while (!stack.empty())
		{
			res.push_back(stack.top());
			;
			stack.pop();
		}

		return res;
	}
	float eval(float a, float b, char op)
	{
		if (op == '+')
			return b + a;
		else if (op == '-')
			return b - a;
		else if (op == '*')
			return b * a;
		else if (op == '/')
			return b / a;
		else if (op == '%')
			return (int)b % (int)a;
		else
		{
			return INT_MIN;
		}
	}
	int precedence(const QString & op)
	{
		if (op == '+' || op == '-')
			return 1;
		else if (op == '*' || op == '/' || op == '%')
			return 2;
		else
			return -1;
	}
	int precedence(char op)
	{
		if (op == '+' || op == '-')
			return 1;
		else if (op == '*' || op == '/' || op == '%')
			return 2;
		else
			return -1;
	}
	bool isOperator(char op)
	{
		const std::vector<char> ops = {
			'+', '-', '*', '/', '%'};
		for (auto o: ops)
		{
			if (o == op)
			{
				return true;
			}
		}
		return false;
	}
	bool isNumber(char num)
	{
		return (num >= '0' && num <= '9') || num == '.';
	}
};