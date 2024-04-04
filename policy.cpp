#include "policy.h"
#include "ui_policy.h"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QGroupBox"
#include "QLabel"
#include "QtDebug"
#include "QComboBox"

Policy::Policy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Policy)
{
    ui->setupUi(this);
    this->policyInterface();
}

Policy::~Policy()
{
    delete ui;
}

void Policy::policyInterface(){

    QHBoxLayout* centerLay = new QHBoxLayout();

    QGroupBox * policyChange = new QGroupBox("Change Policy");

    QVBoxLayout* policyChangeLay = new QVBoxLayout();

    QComboBox* cinput = new QComboBox();

    cinput->addItem("ACCEPT");
    cinput->addItem("DROP");

    connect(cinput,&QComboBox::currentTextChanged,this,[=](){
        if(cinput->currentText()=="ACCEPT"){
            qDebug() << "ACCEPT";
        }
        else if(cinput->currentText()=="DROP"){
            qDebug() << "DROP";
        }
    });

    QComboBox* cforward = new QComboBox();

    cforward->addItem("ACCEPT");
    cforward->addItem("DROP");

    connect(cforward,&QComboBox::currentTextChanged,this,[=](){
        if(cforward->currentText()=="ACCEPT"){
            qDebug() << "ACCEPT";
        }
        else if(cforward->currentText()=="DROP"){
            qDebug() << "DROP";
        }
    });

    QComboBox* coutput = new QComboBox();

    coutput->addItem("ACCEPT");
    coutput->addItem("DROP");

    connect(coutput,&QComboBox::currentTextChanged,this,[=](){
        if(coutput->currentText()=="ACCEPT"){
            qDebug() << "ACCEPT";
        }
        else if(coutput->currentText()=="DROP"){
            qDebug() << "DROP";
        }
    });

    policyChangeLay->addWidget(new QLabel("INPUT"));
    policyChangeLay->addWidget(cinput);
    policyChangeLay->addWidget(new QLabel("FORWARD"));
    policyChangeLay->addWidget(cforward);
    policyChangeLay->addWidget(new QLabel("OUTPUT"));
    policyChangeLay->addWidget(coutput);

    QGroupBox* policyView = new QGroupBox("Policy");

    QVBoxLayout* policyViewLay = new QVBoxLayout();

    policyViewLay->addWidget(new QLabel("INPUT"));
    policyViewLay->addWidget(new QLabel("FORWARD"));
    policyViewLay->addWidget(new QLabel("OUTPUT"));

    policyChange->setLayout(policyChangeLay);
    policyView->setLayout(policyViewLay);

    centerLay->addWidget(policyChange);
    centerLay->addWidget(policyView);

    this->setLayout(centerLay);
}

// void Policy::
