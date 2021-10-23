/**
 * PFCreationWindow -  Profile Field Creation Window
 */

#ifndef PFCREATIONWINDOW_H_
#define PFCREATIONWINDOW_H_

#include "PFCreationHelper.h"
#include "WindowHelper.h"
#include "AppStorage.h"
#include "MessageBar.h"

#include <QMessageBox>
#include <QDialog>

namespace Ui
{
    class PFCreationWindow;
}


class PFCreationWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::PFCreationWindow* ui_;
    PFCreationHelper pfCreationHelper_;
    MessageBar messageBar_;

    NamesSetsManager namesSetsManager_;
    AssociativePair<QString, unsigned> assocs_;

    FieldReceiver sendField;
    Field* field_;

public:
    explicit PFCreationWindow(FieldReceiver fieldReceiver, QWidget* parent = nullptr);
    explicit PFCreationWindow(Field* field, QWidget* parent = nullptr);
    ~PFCreationWindow();

private:
    void init();

private slots:
    void on_lineEdit_FieldName_textChanged(const QString&);
    void on_comboBox_DataType_currentTextChanged(const QString& currentText);
    void on_comboBox_RecFormat_currentTextChanged(const QString&);
    void on_pushButton_Apply_clicked();

};

#endif
