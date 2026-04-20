/********************************************************************************
** Form generated from reading UI file 'worklogdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKLOGDIALOG_H
#define UI_WORKLOGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_WorkLogDialog
{
public:
    QFormLayout *formLayout;
    QLabel *labelArtist;
    QComboBox *comboArtist;
    QLabel *labelShow;
    QComboBox *comboShow;
    QLabel *labelPay;
    QDoubleSpinBox *doubleSpinBoxPay;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *WorkLogDialog)
    {
        if (WorkLogDialog->objectName().isEmpty())
            WorkLogDialog->setObjectName("WorkLogDialog");
        formLayout = new QFormLayout(WorkLogDialog);
        formLayout->setObjectName("formLayout");
        labelArtist = new QLabel(WorkLogDialog);
        labelArtist->setObjectName("labelArtist");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelArtist);

        comboArtist = new QComboBox(WorkLogDialog);
        comboArtist->setObjectName("comboArtist");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, comboArtist);

        labelShow = new QLabel(WorkLogDialog);
        labelShow->setObjectName("labelShow");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelShow);

        comboShow = new QComboBox(WorkLogDialog);
        comboShow->setObjectName("comboShow");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, comboShow);

        labelPay = new QLabel(WorkLogDialog);
        labelPay->setObjectName("labelPay");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelPay);

        doubleSpinBoxPay = new QDoubleSpinBox(WorkLogDialog);
        doubleSpinBoxPay->setObjectName("doubleSpinBoxPay");
        doubleSpinBoxPay->setDecimals(2);
        doubleSpinBoxPay->setMaximum(999999999.990000009536743);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, doubleSpinBoxPay);

        buttonBox = new QDialogButtonBox(WorkLogDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(3, QFormLayout::ItemRole::SpanningRole, buttonBox);


        retranslateUi(WorkLogDialog);

        QMetaObject::connectSlotsByName(WorkLogDialog);
    } // setupUi

    void retranslateUi(QDialog *WorkLogDialog)
    {
        WorkLogDialog->setWindowTitle(QCoreApplication::translate("WorkLogDialog", "\320\222\321\213\321\205\320\276\320\264 \320\275\320\260 \321\200\320\260\320\261\320\276\321\202\321\203", nullptr));
        labelArtist->setText(QCoreApplication::translate("WorkLogDialog", "\320\220\321\200\321\202\320\270\321\201\321\202:", nullptr));
        labelShow->setText(QCoreApplication::translate("WorkLogDialog", "\320\250\320\276\321\203:", nullptr));
        labelPay->setText(QCoreApplication::translate("WorkLogDialog", "\320\236\320\277\320\273\320\260\321\202\320\260 \320\267\320\260 \320\262\321\213\321\205\320\276\320\264:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WorkLogDialog: public Ui_WorkLogDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKLOGDIALOG_H
