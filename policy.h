#ifndef POLICY_H
#define POLICY_H

#include <QWidget>

namespace Ui {
class Policy;
}

class Policy : public QWidget
{
    Q_OBJECT

public:
    explicit Policy(QWidget *parent = nullptr);
    ~Policy();
    void policyInterface();

private:
    Ui::Policy *ui;
};

#endif // POLICY_H
