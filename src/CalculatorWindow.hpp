#pragma once
#include "Calculator.hpp"
#include "types.hpp"
#include <QDebug>
#include <QObject>
#include <qdebug.h>

class CalculatorWindow : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString displayText READ displayText WRITE setDisplayText NOTIFY displayTextChanged)
	Q_PROPERTY(QString answerText READ answerText WRITE setAnswerText NOTIFY answerTextChanged)
public:
	explicit CalculatorWindow(QObject * parent = nullptr);

	~CalculatorWindow();

	QString displayText() const;
	void setDisplayText(const QString & text);
	QString answerText() const;
	void setAnswerText(const QString & text);

public slots:
	void handleNumberClick(const QString & suffix);
	void handleOperator(const QString & op);
	void handleClear();
	void handleBracketChange();
	void handleSignChange();
	void handleSolver();
	void enableWaitingForPassword();
    void disableWaitingForPassword();

signals:
	void displayTextChanged();
	void answerTextChanged();
	void passwordEntered();

private:
	Calculator calc;
	QString m_displayText;
	QString m_answerText;

	bool m_waitingForPassword = false;
	bool m_onePressed = false;
	bool m_twoPressed = false;
	bool m_threePressed = false;

	std::vector<LexedValue *> exprs;
	const std::map<QString, QString> visuals{
		{"/", "÷"},
		{"*", "×"}};

	void handleSecretPassword(const QString& num);
	void clearExprs();
};