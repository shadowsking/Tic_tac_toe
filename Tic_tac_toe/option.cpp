#include "option.h"

Option::Option(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout();
    layout->addWidget(getGBoxEnemy());
    layout->addWidget(getGBoxXO());

    connect(rbtn[2],SIGNAL(clicked()),SLOT(enemyChecked()));
    connect(rbtn[3],SIGNAL(clicked()),SLOT(enemyChecked()));
    connect(rbtn[0],SIGNAL(clicked()),SLOT(XOChecked()));
    connect(rbtn[1],SIGNAL(clicked()),SLOT(XOChecked()));

    setLayout(layout);

}

QGroupBox *Option::getGBoxEnemy()
{
    gBoxEnemy = new QGroupBox("Выберите оппонента");
    rbtn[2] = new QRadioButton("Player");
    rbtn[3] = new QRadioButton("Computer");
    rbtn[2]->setChecked(true);
    enemy = new QVBoxLayout();
    enemy->addWidget(rbtn[2]);
    enemy->addWidget(rbtn[3]);

    gBoxEnemy->setLayout(enemy);
    return gBoxEnemy;
}

void Option::setGBoxEnemy(QGroupBox *value)
{
    gBoxEnemy = value;
}

QGroupBox *Option::getGBoxXO()
{
    gBoxXO = new QGroupBox("Крестик или Нолик???");
    rbtn[0] = new QRadioButton("X");
    rbtn[1] = new QRadioButton("0");
    rbtn[0]->setChecked(true);
    XO = new QVBoxLayout();
    XO->addWidget(rbtn[0]);
    XO->addWidget(rbtn[1]);

    gBoxXO->setLayout(XO);
    return gBoxXO;
}

void Option::setGBoxXO(QGroupBox *value)
{
    gBoxXO = value;
}

ConfigurationFile Option::getCfg()
{
    return cfg;
}

void Option::enemyChecked()
{
    if (rbtn[2]->isChecked()) cfg.setEnemy(cfg.Enemy::Player);
    else cfg.setEnemy(cfg.Enemy::Computer);
}

void Option::XOChecked()
{
    if (rbtn[0]->isChecked()) cfg.setMarkPlayer(cfg.Mark::X);
    else cfg.setMarkPlayer(cfg.Mark::O);
}
