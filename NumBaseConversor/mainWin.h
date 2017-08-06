#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainWin.h"

class mainWin : public QMainWindow
{
	Q_OBJECT

public:
	mainWin(QWidget *parent = Q_NULLPTR);
	~mainWin();
	private slots:
	int ConverseAndShow();

private:
	Ui::mainWinClass ui;
};
