/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelLogin;
    QLineEdit *lineEditLogin;
    QLabel *labelPassword;
    QLineEdit *lineEditPassword;
    QCheckBox *checkBoxGuest;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonLogin;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName("LoginDialog");
        verticalLayout = new QVBoxLayout(LoginDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelLogin = new QLabel(LoginDialog);
        labelLogin->setObjectName("labelLogin");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelLogin);

        lineEditLogin = new QLineEdit(LoginDialog);
        lineEditLogin->setObjectName("lineEditLogin");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEditLogin);

        labelPassword = new QLabel(LoginDialog);
        labelPassword->setObjectName("labelPassword");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelPassword);

        lineEditPassword = new QLineEdit(LoginDialog);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, lineEditPassword);


        verticalLayout->addLayout(formLayout);

        checkBoxGuest = new QCheckBox(LoginDialog);
        checkBoxGuest->setObjectName("checkBoxGuest");

        verticalLayout->addWidget(checkBoxGuest);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonLogin = new QPushButton(LoginDialog);
        pushButtonLogin->setObjectName("pushButtonLogin");

        horizontalLayout->addWidget(pushButtonLogin);

        pushButtonCancel = new QPushButton(LoginDialog);
        pushButtonCancel->setObjectName("pushButtonCancel");

        horizontalLayout->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "\320\222\321\205\320\276\320\264 \320\262 \321\201\320\270\321\201\321\202\320\265\320\274\321\203", nullptr));
        labelLogin->setText(QCoreApplication::translate("LoginDialog", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        labelPassword->setText(QCoreApplication::translate("LoginDialog", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        checkBoxGuest->setText(QCoreApplication::translate("LoginDialog", "\320\222\320\276\320\271\321\202\320\270 \320\272\320\260\320\272 \320\263\320\276\321\201\321\202\321\214 (\321\202\320\276\320\273\321\214\320\272\320\276 \320\277\321\200\320\276\321\201\320\274\320\276\321\202\321\200)", nullptr));
        pushButtonLogin->setText(QCoreApplication::translate("LoginDialog", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        pushButtonCancel->setText(QCoreApplication::translate("LoginDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
