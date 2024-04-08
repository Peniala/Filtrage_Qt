#include "rules.h"
#include "ui_rules.h"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QGroupBox"
#include "QComboBox"
#include "QRadioButton"
#include "QLabel"
#include "QtDebug"
#include "QLineEdit"

Rules::Rules(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rules)
{
    ui->setupUi(this);

    this->rulesInterface();
}

Rules::~Rules()
{
    delete ui;
}

void Rules::rulesInterface(){
    QVBoxLayout* centerLayout = new QVBoxLayout();

    QGroupBox* block = new QGroupBox("Add rules");

    QVBoxLayout* field = new QVBoxLayout();

    QWidget* firstblock = new QWidget();

    QHBoxLayout* firstLay = new QHBoxLayout();

    QComboBox* chain = new QComboBox();

    chain->addItem("INPUT");
    chain->addItem("FORWARD");
    chain->addItem("OUTPUT");

    QGroupBox* Wtarget = new QGroupBox("Target");

    QHBoxLayout* targetLay = new QHBoxLayout();
    QRadioButton* accept = new QRadioButton("ACCEPT");
    QRadioButton* drop = new QRadioButton("DROP");

    targetLay->addWidget(accept);
    targetLay->addWidget(drop);

    Wtarget->setLayout(targetLay);

    QComboBox* interface = new QComboBox();

    interface->addItem("Interface");

    firstLay->addWidget(chain);
    firstLay->addWidget(Wtarget);
    firstLay->addWidget(interface);

    firstblock->setLayout(firstLay);

    QGroupBox* secondblock = new QGroupBox("Protocols");

    QVBoxLayout* secondLay = new QVBoxLayout();

    secondblock->setLayout(secondLay);

    QWidget* protocols = new QWidget();

    QHBoxLayout* protLay = new QHBoxLayout();

    protocols->setLayout(protLay);

    QRadioButton* tcp = new QRadioButton("tcp");
    QRadioButton* udp = new QRadioButton("udp");
    QRadioButton* ddp = new QRadioButton("ddp");
    QRadioButton* icmp = new QRadioButton("icmp");

    protLay->addWidget(tcp);
    protLay->addWidget(udp);
    protLay->addWidget(ddp);
    protLay->addWidget(icmp);

    secondLay->addWidget(protocols);

    QGroupBox* thirdblock = new QGroupBox("Source");

    QHBoxLayout* thirdLay = new QHBoxLayout();

    thirdblock->setLayout(thirdLay);

    QLineEdit* source = new QLineEdit();

    QRadioButton* smac = new QRadioButton("MAC");

    thirdLay->addWidget(source);
    thirdLay->addWidget(smac);

    QGroupBox* fourthblock = new QGroupBox("Destination");

    QHBoxLayout* fourthLay = new QHBoxLayout();

    fourthblock->setLayout(fourthLay);

    QLineEdit* dest = new QLineEdit();

    QRadioButton* dmac = new QRadioButton("MAC");

    fourthLay->addWidget(dest);
    fourthLay->addWidget(dmac);

    field->addWidget(firstblock);
    field->addWidget(secondblock);
    field->addWidget(thirdblock);
    field->addWidget(fourthblock);

    block->setLayout(field);

    centerLayout->addWidget(block);

    this->setLayout(centerLayout);

}
