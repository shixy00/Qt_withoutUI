#include "qwdlgmanual.h"
#include<QHBoxLayout>
#include<QVBoxLayout>

void QWDlgManual::iniUI()
{
    //创建underline,Italic,Bold三个CheckBox，并水平布局
    chkBoxUnder=new QCheckBox(tr("UnderLine"));
    chkBoxItalic = new QCheckBox(tr("Italic"));
    chkBoxBold = new QCheckBox(tr("Bold"));
    QHBoxLayout *HLay1 = new QHBoxLayout;
    HLay1->addWidget(chkBoxUnder);
    HLay1->addWidget(chkBoxItalic);
    HLay1->addWidget(chkBoxBold);

    //创建black,blue,red三个rBtn，并水平布局
    rBtnBlack = new QRadioButton(tr("black"));
    rBtnBlack->setChecked(true);   //缺省被选中
    rBtnBlue = new QRadioButton(tr("Blue"));
    rBtnRed = new QRadioButton(tr("Red"));
    QHBoxLayout *HLay2 = new QHBoxLayout;
    HLay2->addWidget(rBtnBlack);
    HLay2->addWidget(rBtnBlue);
    HLay2->addWidget(rBtnRed);

    //创建 确定 取消 退出 三个 QPushbtn,并水平布局
    btnOK = new QPushButton(tr("确定"));
    btnCancel = new QPushButton(tr("取消"));
    btnClose = new QPushButton(tr("退出"));
    QHBoxLayout *HLay3 = new QHBoxLayout;
    HLay3->addStretch();
    HLay3->addWidget(btnOK);
    HLay3->addWidget(btnCancel);
    HLay3->addStretch();
    HLay3->addWidget(btnClose);

    //创建 文本框 并设置初始字体
    txtEdit = new QPlainTextEdit;
    //txtEdit->setPlainText("text");

    QFont font = txtEdit->font();
    font.setPointSize(20);
    txtEdit->setFont(font);

    //创建 垂直布局 并设置为主布局
    QVBoxLayout *Vlay = new QVBoxLayout;
    Vlay->addLayout(HLay1);
    Vlay->addLayout(HLay2);
    Vlay->addWidget(txtEdit);
    Vlay->addLayout(HLay3);

    setLayout(Vlay);   //设置为窗体的主布局

}

void QWDlgManual::iniSignalSlots()
{
    //三个颜色
    connect(rBtnBlue,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(rBtnBlack,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(rBtnRed,SIGNAL(clicked()),this,SLOT(setTextFontColor()));

    //三个字体
    connect(chkBoxUnder,SIGNAL(clicked(bool)),this,SLOT(on_chkBoxUnder(bool)));
    connect(chkBoxItalic,SIGNAL(clicked(bool)),this,SLOT(on_chkBoxItalic(bool)));
    connect(chkBoxBold,SIGNAL(clicked(bool)),this,SLOT(on_chkBoxBold(bool)));

    //三个按键
    connect(btnOK,SIGNAL(clicked()),this,SLOT(accept()));
    connect(btnCancel,SIGNAL(clicked()),this,SLOT(reject()));
    connect(btnClose,SIGNAL(clicked()),this,SLOT(close()));

}

void QWDlgManual::on_chkBoxUnder(bool checked)
{
    QFont font=txtEdit->font();
    font.setUnderline(checked);
    txtEdit->setFont(font);
}

void QWDlgManual::on_chkBoxBold(bool checked)
{
    QFont font = txtEdit->font();
    font.setBold(checked);
    txtEdit->setFont(font);
}

void QWDlgManual::on_chkBoxItalic(bool checked)
{
    QFont font = txtEdit->font();
    font.setItalic(checked);
    txtEdit->setFont(font);
}

void QWDlgManual::setTextFontColor()
{
    QPalette plet = txtEdit->palette();
    if(rBtnBlue->isChecked())
        plet.setColor(QPalette::Text,Qt::blue);
    else if (rBtnBlack->isChecked()) {
        plet.setColor(QPalette::Text,Qt::black);
    }
    else if (rBtnRed->isChecked()) {
        plet.setColor(QPalette::Text,Qt::red);
    }
    else
        plet.setColor(QPalette::Text,Qt::black);

    txtEdit->setPalette(plet);
}

QWDlgManual::QWDlgManual(QWidget *parent)
    : QDialog(parent)
{
    iniUI();  //界面创建与布局
    iniSignalSlots();  //信号与槽的关联
    setWindowTitle("Form created manually");
}

QWDlgManual::~QWDlgManual()
{

}
