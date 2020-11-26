/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label_24;
    QLabel *label_25;
    QLineEdit *lineEdit_objet;
    QTextEdit *textEdit_texte;
    QLabel *label_23;
    QLineEdit *lineEdit_adresse;
    QFrame *frame_12;
    QPushButton *pushButton_envoyer;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(841, 420);
        label_24 = new QLabel(Dialog);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(60, 81, 171, 20));
        label_25 = new QLabel(Dialog);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(60, 181, 91, 20));
        lineEdit_objet = new QLineEdit(Dialog);
        lineEdit_objet->setObjectName(QStringLiteral("lineEdit_objet"));
        lineEdit_objet->setGeometry(QRect(210, 132, 531, 21));
        textEdit_texte = new QTextEdit(Dialog);
        textEdit_texte->setObjectName(QStringLiteral("textEdit_texte"));
        textEdit_texte->setGeometry(QRect(210, 181, 531, 151));
        label_23 = new QLabel(Dialog);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(60, 131, 91, 20));
        lineEdit_adresse = new QLineEdit(Dialog);
        lineEdit_adresse->setObjectName(QStringLiteral("lineEdit_adresse"));
        lineEdit_adresse->setGeometry(QRect(210, 81, 531, 22));
        frame_12 = new QFrame(Dialog);
        frame_12->setObjectName(QStringLiteral("frame_12"));
        frame_12->setGeometry(QRect(0, 0, 841, 421));
        frame_12->setStyleSheet(QLatin1String("background:rgba(119,181,254,0.7);\n"
"border: 5px solid blue;\n"
""));
        frame_12->setFrameShape(QFrame::StyledPanel);
        frame_12->setFrameShadow(QFrame::Raised);
        pushButton_envoyer = new QPushButton(Dialog);
        pushButton_envoyer->setObjectName(QStringLiteral("pushButton_envoyer"));
        pushButton_envoyer->setGeometry(QRect(600, 350, 141, 31));
        pushButton_envoyer->setStyleSheet(QLatin1String("QPushButton{\n"
"\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #f7f7f7, stop: 0.4 #f0f0f0,\n"
"                                 stop: 0.5 #e8e8e8, stop: 1.0 #dcdcdc);\n"
"border-radius:20px;\n"
"border-radius:15px;\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:hover{\n"
"background:   qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #1b83fe, stop: 0.4 #4399fe,\n"
"                                 stop: 0.5 #5da7fe, stop: 1.0 #77b5fe);\n"
"color:white;\n"
"}"));
        frame_12->raise();
        label_24->raise();
        label_25->raise();
        lineEdit_objet->raise();
        textEdit_texte->raise();
        label_23->raise();
        lineEdit_adresse->raise();
        pushButton_envoyer->raise();

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        label_24->setText(QApplication::translate("Dialog", "E-mail du patient :", Q_NULLPTR));
        label_25->setText(QApplication::translate("Dialog", "Texte :", Q_NULLPTR));
        label_23->setText(QApplication::translate("Dialog", "Objet :", Q_NULLPTR));
        pushButton_envoyer->setText(QApplication::translate("Dialog", "Envoyer", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
