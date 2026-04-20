/********************************************************************************
** Form generated from reading UI file 'venuesdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENUESDIALOG_H
#define UI_VENUESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_VenuesDialog
{
public:
    QFormLayout *formLayout;
    QLabel *labelName;
    QLineEdit *lineEditName;
    QLabel *labelPrice;
    QDoubleSpinBox *doubleSpinBoxPrice;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *VenuesDialog)
    {
        if (VenuesDialog->objectName().isEmpty())
            VenuesDialog->setObjectName("VenuesDialog");
        formLayout = new QFormLayout(VenuesDialog);
        formLayout->setObjectName("formLayout");
        labelName = new QLabel(VenuesDialog);
        labelName->setObjectName("labelName");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelName);

        lineEditName = new QLineEdit(VenuesDialog);
        lineEditName->setObjectName("lineEditName");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEditName);

        labelPrice = new QLabel(VenuesDialog);
        labelPrice->setObjectName("labelPrice");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelPrice);

        doubleSpinBoxPrice = new QDoubleSpinBox(VenuesDialog);
        doubleSpinBoxPrice->setObjectName("doubleSpinBoxPrice");
        doubleSpinBoxPrice->setDecimals(2);
        doubleSpinBoxPrice->setMaximum(999999999.990000009536743);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, doubleSpinBoxPrice);

        buttonBox = new QDialogButtonBox(VenuesDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(2, QFormLayout::ItemRole::SpanningRole, buttonBox);


        retranslateUi(VenuesDialog);

        QMetaObject::connectSlotsByName(VenuesDialog);
    } // setupUi

    void retranslateUi(QDialog *VenuesDialog)
    {
        VenuesDialog->setWindowTitle(QCoreApplication::translate("VenuesDialog", "\320\237\320\273\320\276\321\211\320\260\320\264\320\272\320\260", nullptr));
        labelName->setText(QCoreApplication::translate("VenuesDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265:", nullptr));
        labelPrice->setText(QCoreApplication::translate("VenuesDialog", "\320\221\320\260\320\267\320\276\320\262\320\260\321\217 \321\206\320\265\320\275\320\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VenuesDialog: public Ui_VenuesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENUESDIALOG_H
