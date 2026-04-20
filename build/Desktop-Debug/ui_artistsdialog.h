/********************************************************************************
** Form generated from reading UI file 'artistsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARTISTSDIALOG_H
#define UI_ARTISTSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ArtistsDialog
{
public:
    QFormLayout *formLayout;
    QLabel *labelFullname;
    QLineEdit *lineEditFullname;
    QLabel *labelCategory;
    QComboBox *comboCategory;
    QLabel *labelDescription;
    QTextEdit *textEditDescription;
    QLabel *labelRating;
    QDoubleSpinBox *doubleSpinBoxRating;
    QLabel *labelPhoto;
    QHBoxLayout *horizontalLayoutPhoto;
    QLineEdit *lineEditPhotoPath;
    QPushButton *btnBrowsePhoto;
    QPushButton *btnViewPhoto;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ArtistsDialog)
    {
        if (ArtistsDialog->objectName().isEmpty())
            ArtistsDialog->setObjectName("ArtistsDialog");
        formLayout = new QFormLayout(ArtistsDialog);
        formLayout->setObjectName("formLayout");
        labelFullname = new QLabel(ArtistsDialog);
        labelFullname->setObjectName("labelFullname");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelFullname);

        lineEditFullname = new QLineEdit(ArtistsDialog);
        lineEditFullname->setObjectName("lineEditFullname");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEditFullname);

        labelCategory = new QLabel(ArtistsDialog);
        labelCategory->setObjectName("labelCategory");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelCategory);

        comboCategory = new QComboBox(ArtistsDialog);
        comboCategory->setObjectName("comboCategory");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, comboCategory);

        labelDescription = new QLabel(ArtistsDialog);
        labelDescription->setObjectName("labelDescription");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelDescription);

        textEditDescription = new QTextEdit(ArtistsDialog);
        textEditDescription->setObjectName("textEditDescription");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, textEditDescription);

        labelRating = new QLabel(ArtistsDialog);
        labelRating->setObjectName("labelRating");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, labelRating);

        doubleSpinBoxRating = new QDoubleSpinBox(ArtistsDialog);
        doubleSpinBoxRating->setObjectName("doubleSpinBoxRating");
        doubleSpinBoxRating->setDecimals(1);
        doubleSpinBoxRating->setMaximum(5.000000000000000);

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, doubleSpinBoxRating);

        labelPhoto = new QLabel(ArtistsDialog);
        labelPhoto->setObjectName("labelPhoto");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, labelPhoto);

        horizontalLayoutPhoto = new QHBoxLayout();
        horizontalLayoutPhoto->setObjectName("horizontalLayoutPhoto");
        lineEditPhotoPath = new QLineEdit(ArtistsDialog);
        lineEditPhotoPath->setObjectName("lineEditPhotoPath");
        lineEditPhotoPath->setReadOnly(true);

        horizontalLayoutPhoto->addWidget(lineEditPhotoPath);

        btnBrowsePhoto = new QPushButton(ArtistsDialog);
        btnBrowsePhoto->setObjectName("btnBrowsePhoto");

        horizontalLayoutPhoto->addWidget(btnBrowsePhoto);

        btnViewPhoto = new QPushButton(ArtistsDialog);
        btnViewPhoto->setObjectName("btnViewPhoto");

        horizontalLayoutPhoto->addWidget(btnViewPhoto);


        formLayout->setLayout(4, QFormLayout::ItemRole::FieldRole, horizontalLayoutPhoto);

        buttonBox = new QDialogButtonBox(ArtistsDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(5, QFormLayout::ItemRole::SpanningRole, buttonBox);


        retranslateUi(ArtistsDialog);

        QMetaObject::connectSlotsByName(ArtistsDialog);
    } // setupUi

    void retranslateUi(QDialog *ArtistsDialog)
    {
        ArtistsDialog->setWindowTitle(QCoreApplication::translate("ArtistsDialog", "\320\220\321\200\321\202\320\270\321\201\321\202", nullptr));
        labelFullname->setText(QCoreApplication::translate("ArtistsDialog", "\320\244\320\230\320\236:", nullptr));
        labelCategory->setText(QCoreApplication::translate("ArtistsDialog", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217:", nullptr));
        labelDescription->setText(QCoreApplication::translate("ArtistsDialog", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265:", nullptr));
        labelRating->setText(QCoreApplication::translate("ArtistsDialog", "\320\240\320\265\320\271\321\202\320\270\320\275\320\263:", nullptr));
        labelPhoto->setText(QCoreApplication::translate("ArtistsDialog", "\320\244\320\276\321\202\320\276\320\263\321\200\320\260\321\204\320\270\321\217:", nullptr));
        btnBrowsePhoto->setText(QCoreApplication::translate("ArtistsDialog", "\320\236\320\261\320\267\320\276\321\200...", nullptr));
        btnViewPhoto->setText(QCoreApplication::translate("ArtistsDialog", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArtistsDialog: public Ui_ArtistsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTISTSDIALOG_H
