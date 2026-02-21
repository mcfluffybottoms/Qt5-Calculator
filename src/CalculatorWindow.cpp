#include "CalculatorWindow.hpp"


CalculatorWindow::CalculatorWindow(QObject * parent)
	: QObject(parent)
	, m_displayText("")
	, m_answerText("0")
{}

CalculatorWindow::~CalculatorWindow()
{
	clearExprs();
}

QString CalculatorWindow::displayText() const { return m_displayText; }
void CalculatorWindow::setDisplayText(const QString & text)
{
	m_displayText = text;
	emit displayTextChanged();
}

QString CalculatorWindow::answerText() const { return m_answerText; }
void CalculatorWindow::setAnswerText(const QString & text)
{
	m_answerText = text;
	emit answerTextChanged();
}

void CalculatorWindow::handleNumberClick(const QString & suffix)
{
	handleSecretPassword(suffix);
	LexedValue * value = nullptr;
	if (exprs.empty() || !exprs.back()->isNum())
	{
		value = new LexedValue(LexToken::NUM);
		exprs.push_back(value);
	}
	else
	{
		value = exprs.back();
	}
	assert(value);
	value->addChar(suffix);
	setDisplayText(m_displayText + suffix);
}
void CalculatorWindow::handleOperator(const QString & op)
{
	handleSecretPassword(".");
	LexedValue * value = nullptr;

	if (exprs.empty() || exprs.back()->isBrkOpened())
	{
		LexedValue * num = new LexedValue(LexToken::NUM);
		num->addChar("0");
		m_displayText += "0";
		exprs.push_back(num);
	}

	if (exprs.back()->isOp())
	{
		value = exprs.back();
	}
	else
	{
		value = new LexedValue(LexToken::OP);
		exprs.push_back(value);
	}

	assert(value);
	value->changeValue(op);

	auto visualOp = visuals.count(op) ? visuals.at(op) : op;
	setDisplayText(m_displayText + " " + visualOp + " ");
}

void CalculatorWindow::handleClear()
{
	handleSecretPassword(".");
	clearExprs();
	setDisplayText("");
	setAnswerText("0");
}

void CalculatorWindow::handleBracketChange()
{
	handleSecretPassword(".");
	if (
		!exprs.empty() && exprs.back() && !exprs.back()->isNum() && exprs.back()->getValue() == "(")
	{
		LexedValue * value = exprs.back();
		assert(value);
		value->changeValue(")");
		m_displayText.chop(1);
		setDisplayText(m_displayText + ")");
	}
	else if (
		!exprs.empty() && exprs.back() && !exprs.back()->isNum() && exprs.back()->getValue() == ")")
	{
		LexedValue * value = exprs.back();
		if (value)
			delete value;
		exprs.pop_back();
		if (!m_displayText.isEmpty())
			m_displayText.chop(1);
		setDisplayText(m_displayText);
	}
	else
	{
		LexedValue * value = new LexedValue(LexToken::BKT_OPEN);
		value->addChar("(");
		exprs.push_back(value);
		setDisplayText(m_displayText + "(");
		return;
	}
}

void CalculatorWindow::handleSignChange()
{
	handleSecretPassword(".");
	if (exprs.empty())
		return;
	LexedValue * value = exprs.back();
	assert(value);
	int toSubstract = value->changeSign();
	if (toSubstract != 0)
	{
		m_displayText = m_displayText.remove(m_displayText.size() - toSubstract, toSubstract);
		setDisplayText(m_displayText + value->getValue());
	}
}

void CalculatorWindow::handleSolver()
{
	handleSecretPassword(".");
	auto str = calc.eval(exprs);
	int last_not_of_0 =
		str.find('.') == std::string::npos ? str.size() - 1 : str.find_last_not_of('0');
	str.erase(last_not_of_0, std::string::npos);

	setAnswerText(
		QString::fromStdString(str));
}

void CalculatorWindow::enableWaitingForPassword()
{
	m_waitingForPassword = true;
	m_onePressed = false;
	m_twoPressed = false;
	m_threePressed = false;
}

void CalculatorWindow::disableWaitingForPassword()
{
	m_waitingForPassword = false;
	m_onePressed = false;
	m_twoPressed = false;
	m_threePressed = false;
}

void CalculatorWindow::handleSecretPassword(const QString & num)
{
	if (!m_waitingForPassword)
		return;
	if (num == "1" && !m_onePressed && !m_twoPressed && !m_threePressed)
	{
		m_onePressed = true;
	}
	else if (num == "2" && m_onePressed && !m_twoPressed && !m_threePressed)
	{
		m_twoPressed = true;
	}
	else if (num == "3" && m_onePressed && m_twoPressed && !m_threePressed)
	{
		m_threePressed = true;
	}
	else
	{
		m_onePressed = false;
		m_twoPressed = false;
		m_threePressed = false;
	}

	if (m_onePressed && m_twoPressed && m_threePressed)
	{
		emit passwordEntered();
		m_waitingForPassword = false;
	}
}

void CalculatorWindow::clearExprs()
{
	for (int i = 0; i < exprs.size(); ++i)
	{
		if (exprs[i] != nullptr)
		{
			delete exprs[i];
		}
	}
	exprs.clear();
}