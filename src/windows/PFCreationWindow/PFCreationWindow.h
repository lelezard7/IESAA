/**
 * PFCreationWindow -  Profile Field Creation Window
 */

#ifndef PFCREATIONWINDOW_H_
#define PFCREATIONWINDOW_H_

#include "../PFCreationWindow/FieldCreator.h"
#include "../PFCreationWindow/NamesSetsManager.h"

#include <QDialog>
#include <QComboBox>

//#include "../../LocalDB.h"
//#include "FieldCreator.h"












class FieldCreator
{
    QVector<std::pair<QString, IFieldWidget*>> assoc_;
    QComboBox* comboBox_;

public:
    FieldCreator();
    FieldCreator(QComboBox* comboBox);
    virtual ~FieldCreator();

    void setComboBox(QComboBox* comboBox);

    bool createAssociation(QString name, IFieldWidget* widget);
    IFieldWidget* getWidget(QString name);
    IFieldWidget* widget(QString name);
};




namespace Ui
{
    class PFCreationWindow;
}


class PFCreationWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::PFCreationWindow* ui_;
    TableManager_Profile* fieldCreator_;
    FieldCreator fieldAssoc_;
    NamesSetsManager namesSetsManager_;

public:
    explicit PFCreationWindow(TableManager_Profile* fieldCreator, QWidget* parent = nullptr);
    ~PFCreationWindow();

private slots:
    void on_buttonBox_accepted();

    void on_comboBox_currentTextChanged(const QString &arg1);
};

#endif
