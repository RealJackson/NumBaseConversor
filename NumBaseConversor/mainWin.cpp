#include "mainWin.h"
#include <qstring.h>
#include <string>
#include "NumBaseConversor.h"

mainWin::mainWin(QWidget *parent)
	: QMainWindow(parent)
{

	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(ConverseAndShow()));
}

mainWin::~mainWin()
{
}


int mainWin::ConverseAndShow()
{
	QString Qstr="";
	Qstr = ui.lineEditInput->text();
	Qstr = Qstr.toUpper();
	string TempStr = Qstr.toStdString();
	int mode = ui.comboBox->currentIndex();
	NumBaseConversor conversor(0);
	uint64_t DataInput = conversor.InputStr2Data(TempStr, mode);
	conversor.WriteAllProp(DataInput);
	QString QstrHex = QstrHex.fromStdString(conversor.GetHex());
	QString QstrDec = QstrDec.fromStdString(conversor.GetDec());
	QString QstrOct = QstrOct.fromStdString(conversor.GetOct());
	QString QstrBin = QstrBin.fromStdString(conversor.GetBin());
	int i = 0;
	for (i = 0; i < QstrDec.length() - 1; i++)
	{
		if (QstrDec[i] != "0" && QstrDec[i] != ",")
			break;
	}
	QstrDec = QstrDec.mid(i, QstrDec.length() - i);
	int ShowMode = ui.comboBox_2->currentIndex();
	if (ShowMode == 0)	//64bit show mode
	{
		QFont font;
		font.setFamily(QStringLiteral("Consolas"));
		font.setPointSize(8);
		ui.lineEditBin->setFont(font);
	}
	else if (ShowMode == 1)	//48bit show mode
	{
		QFont font;
		font.setFamily(QStringLiteral("Consolas"));
		font.setPointSize(10);
		ui.lineEditBin->setFont(font);
		QstrBin = QstrBin.mid(20, QstrBin.length()-20);
		QstrOct=QstrOct.mid(8,QstrOct.length()-8);
		QstrHex=QstrHex.mid(5,QstrHex.length()-5);
	}
	else if (ShowMode == 2)	//32bit show mode
	{
		QFont font;
		font.setFamily(QStringLiteral("Consolas"));
		font.setPointSize(12);
		ui.lineEditBin->setFont(font);
		QstrBin = QstrBin.mid(40, QstrBin.length() - 40);
		QstrOct = QstrOct.mid(15, QstrOct.length() -15);
		QstrHex = QstrHex.mid(10, QstrHex.length() - 10);
	}
	else if (ShowMode == 3)		//24bit show mode
	{
		QFont font;
		font.setFamily(QStringLiteral("Consolas"));
		font.setPointSize(14);
		ui.lineEditBin->setFont(font);
		QstrBin = QstrBin.mid(50, QstrBin.length() - 50);
		QstrOct = QstrOct.mid(19, QstrOct.length() - 19);
		QstrHex = QstrHex.mid(12, QstrHex.length() - 12);
	}
	else if (ShowMode == 4)		//16bit show mode
	{
		QFont font;
		font.setFamily(QStringLiteral("Consolas"));
		font.setPointSize(14);
		ui.lineEditBin->setFont(font);
		QstrBin = QstrBin.mid(60, QstrBin.length() - 60);
		QstrOct = QstrOct.mid(22, QstrOct.length() - 22);
		QstrHex = QstrHex.mid(15, QstrHex.length() - 15);
	}
	else if (ShowMode == 5)		//8bit show mode
	{
		QFont font;
		font.setFamily(QStringLiteral("Consolas"));
		font.setPointSize(14);
		ui.lineEditBin->setFont(font);
		QstrBin = QstrBin.mid(70, QstrBin.length() - 70);
		QstrOct = QstrOct.mid(26, QstrOct.length() - 26);
		QstrHex = QstrHex.mid(17, QstrHex.length() - 17);
	}
	ui.lineEditHex->clear();
	ui.lineEditDec->clear();
	ui.lineEditOct->clear();
	ui.lineEditBin->clear();

	ui.lineEditHex->setText(QstrHex);
	ui.lineEditDec->setText(QstrDec);
	ui.lineEditOct->setText(QstrOct);
	ui.lineEditBin->setText(QstrBin);

	return 0;
}