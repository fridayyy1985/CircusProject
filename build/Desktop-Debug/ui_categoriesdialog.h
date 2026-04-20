/********************************************************************************
** Form generated from reading UI file 'categoriesdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATEGORIESDIALOG_H
#define UI_CATEGORIESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_CategoriesDialog
{
public:
    QFormLayout *formLayout;
    QLabel *labelName;
    QLineEdit *lineEditName;
    QLabel *labelGenre;
    QLineEdit *lineEditGenre;
    QLabel *labelArtists;
    QSpinBox *spinBoxArtists;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CategoriesDialog)
    {
        if (CategoriesDialog->objectName().isEmpty())
            CategoriesDialog->setObjectName("CategoriesDialog");
        formLayout = new QFormLayout(CategoriesDialog);
        formLayout->setObjectName("formLayout");
        labelName = new QLabel(CategoriesDialog);
        labelName->setObjectName("labelName");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelName);

        lineEditName = new QLineEdit(CategoriesDialog);
        lineEditName->setObjectName("lineEditName");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEditName);

        labelGenre = new QLabel(CategoriesDialog);
        labelGenre->setObjectName("labelGenre");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelGenre);

        lineEditGenre = new QLineEdit(CategoriesDialog);
        lineEditGenre->setObjectName("lineEditGenre");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, lineEditGenre);

        labelArtists = new QLabel(CategoriesDialog);
        labelArtists->setObjectName("labelArtists");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelArtists);

        spinBoxArtists = new QSpinBox(CategoriesDialog);
        spinBoxArtists->setObjectName("spinBoxArtists");
        spinBoxArtists->setMinimum(0);
        spinBoxArtists->setMaximum(999999);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, spinBoxArtists);

        buttonBox = new QDialogButtonBox(CategoriesDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(3, QFormLayout::ItemRole::SpanningRole, buttonBox);


        retranslateUi(CategoriesDialog);

        QMetaObject::connectSlotsByName(CategoriesDialog);
    } // setupUi

    void retranslateUi(QDialog *CategoriesDialog)
    {
        CategoriesDialog->setWindowTitle(QCoreApplication::translate("CategoriesDialog", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217 \320\260\321\200\321\202\320\270\321\201\321\202\320\276\320\262", nullptr));
        labelName->setText(QCoreApplication::translate("CategoriesDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265:", nullptr));
        labelGenre->setText(QCoreApplication::translate("CategoriesDialog", "\320\226\320\260\320\275\321\200:", nullptr));
        labelArtists->setText(QCoreApplication::translate("CategoriesDialog", "\320\232\320\276\320\273-\320\262\320\276 \320\260\321\200\321\202\320\270\321\201\321\202\320\276\320\262:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CategoriesDialog: public Ui_CategoriesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATEGORIESDIALOG_H
