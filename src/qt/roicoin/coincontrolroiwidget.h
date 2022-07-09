// Copyright (c) 2019 The ROICOIN developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef COINCONTROLROIWIDGET_H
#define COINCONTROLROIWIDGET_H

#include <QDialog>

namespace Ui {
class CoinControlRoiWidget;
}

class CoinControlRoiWidget : public QDialog
{
    Q_OBJECT

public:
    explicit CoinControlRoiWidget(QWidget *parent = nullptr);
    ~CoinControlRoiWidget();

private:
    Ui::CoinControlRoiWidget *ui;
};

#endif // COINCONTROLROIWIDGET_H
