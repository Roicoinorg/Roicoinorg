// Copyright (c) 2017-2019 The ROICOIN developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZROICONTROLDIALOG_H
#define ZROICONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zroi/zerocoin.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZRoiControlDialog;
}

class CZRoiControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZRoiControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZRoiControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZRoiControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZRoiControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZRoiControlDialog(QWidget *parent);
    ~ZRoiControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZRoiControlDialog *ui;
    WalletModel* model;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_PRECOMPUTE,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZRoiControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZROICONTROLDIALOG_H
