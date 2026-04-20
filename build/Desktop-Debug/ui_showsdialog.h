/********************************************************************************
** Form generated from reading UI file 'showsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWSDIALOG_H
#define UI_SHOWSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_ShowsDialog
{
public:
    QFormLayout *formLayout;
    QLabel *labelName;
    QLineEdit *lineEditName;
    QLabel *labelVenue;
    QComboBox *comboVenue;
    QLabel *labelDate;
    QDateEdit *dateEdit;
    QLabel *labelPrice;
    QDoubleSpinBox *doubleSpinBoxPrice;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ShowsDialog)
    {
        if (ShowsDialog->objectName().isEmpty())
            ShowsDialog->setObjectName("ShowsDialog");
        formLayout = new QFormLayout(ShowsDialog);
        formLayout->setObjectName("formLayout");
        labelName = new QLabel(ShowsDialog);
        labelName->setObjectName("labelName");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelName);

        lineEditName = new QLineEdit(ShowsDialog);
        lineEditName->setObjectName("lineEditName");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEditName);

        labelVenue = new QLabel(ShowsDialog);
        labelVenue->setObjectName("labelVenue");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelVenue);

        comboVenue = new QComboBox(ShowsDialog);
        comboVenue->setObjectName("comboVenue");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, comboVenue);

        labelDate = new QLabel(ShowsDialog);
        labelDate->setObjectName("labelDate");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelDate);

        dateEdit = new QDateEdit(ShowsDialog);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setCalendarPopup(true);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, dateEdit);

        labelPrice = new QLabel(ShowsDialog);
        labelPrice->setObjectName("labelPrice");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, labelPrice);

        doubleSpinBoxPrice = new QDoubleSpinBox(ShowsDialog);
        doubleSpinBoxPrice->setObjectName("doubleSpinBoxPrice");
        doubleSpinBoxPrice->setDecimals(2);
        doubleSpinBoxPrice->setMaximum(999999999.990000009536743);

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, doubleSpinBoxPrice);

        buttonBox = new QDialogButtonBox(ShowsDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(4, QFormLayout::ItemRole::SpanningRole, buttonBox);


        retranslateUi(ShowsDialog);

        QMetaObject::connectSlotsByName(ShowsDialog);
    } // setupUi

    void retranslateUi(QDialog *ShowsDialog)
    {
        ShowsDialog->setWindowTitle(QCoreApplication::translate("ShowsDialog", "\320\250\320\276\321\203", nullptr));
        labelName->setText(QCoreApplication::translate("ShowsDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265:", nullptr));
        labelVenue->setText(QCoreApplication::translate("ShowsDialog", "\320\237\320\273\320\276\321\211\320\260\320\264\320\272\320\260:", nullptr));
        labelDate->setText(QCoreApplication::translate("ShowsDialog", "\320\224\320\260\321\202\320\260:", nullptr));
        labelPrice->setText(QCoreApplication::translate("ShowsDialog", "\320\246\320\265\320\275\320\260 \320\261\320\270\320\273\320\265\321\202\320\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowsDialog: public Ui_ShowsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWSDIALOG_H
