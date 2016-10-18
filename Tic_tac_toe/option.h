#ifndef OPTION_H
#define OPTION_H

#include <QWidget>
#include "QRadioButton"
#include "QBoxLayout"
#include "QPushButton"
#include "QLabel"
#include "QGroupBox"
#include "configurationfile.h"
#include "QDebug"

class Option : public QWidget
{
    Q_OBJECT
public:
    explicit Option(QWidget *parent = 0);

    QGroupBox *getGBoxEnemy();
    void setGBoxEnemy(QGroupBox *value);

    QGroupBox *getGBoxXO();
    void setGBoxXO(QGroupBox *value);

    ConfigurationFile getCfg();

private:
    ConfigurationFile cfg;
    QRadioButton *rbtn[4];
    QVBoxLayout *layout;
    QVBoxLayout *enemy;
    QVBoxLayout *XO;
    QGroupBox *gBoxEnemy;
    QGroupBox *gBoxXO;
private slots:
    void enemyChecked();
    void XOChecked();
};

#endif // OPTION_H
