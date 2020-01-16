/********************************************************************************
** Form generated from reading UI file 'imageenhance.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEENHANCE_H
#define UI_IMAGEENHANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_imageEnhance
{
public:
    QWidget *centralWidget;
    QPushButton *means1;
    QPushButton *means2;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *imageEnhance)
    {
        if (imageEnhance->objectName().isEmpty())
            imageEnhance->setObjectName(QStringLiteral("imageEnhance"));
        imageEnhance->resize(400, 300);
        imageEnhance->setFocusPolicy(Qt::StrongFocus);
        centralWidget = new QWidget(imageEnhance);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        means1 = new QPushButton(centralWidget);
        means1->setObjectName(QStringLiteral("means1"));
        means1->setGeometry(QRect(20, 20, 361, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \347\271\201\351\273\221\351\253\224 Std B"));
        font.setPointSize(13);
        means1->setFont(font);
        means2 = new QPushButton(centralWidget);
        means2->setObjectName(QStringLiteral("means2"));
        means2->setGeometry(QRect(20, 120, 361, 61));
        means2->setFont(font);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 210, 221, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8(".\350\220\215\346\226\271-\347\256\200"));
        font1.setPointSize(10);
        label->setFont(font1);
        imageEnhance->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(imageEnhance);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        imageEnhance->setMenuBar(menuBar);
        mainToolBar = new QToolBar(imageEnhance);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        imageEnhance->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(imageEnhance);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        imageEnhance->setStatusBar(statusBar);

        retranslateUi(imageEnhance);

        QMetaObject::connectSlotsByName(imageEnhance);
    } // setupUi

    void retranslateUi(QMainWindow *imageEnhance)
    {
        imageEnhance->setWindowTitle(QApplication::translate("imageEnhance", "imageEnhance", nullptr));
        means1->setText(QApplication::translate("imageEnhance", "1 | filter-sharpen-median", nullptr));
        means2->setText(QApplication::translate("imageEnhance", "2 | filter-contrast", nullptr));
        label->setText(QApplication::translate("imageEnhance", "\347\273\223\346\235\237\345\220\216\344\274\232\346\234\211\346\217\220\347\244\272\357\274\214\345\210\253\344\270\200\347\233\264\347\202\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class imageEnhance: public Ui_imageEnhance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEENHANCE_H
