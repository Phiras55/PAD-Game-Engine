/********************************************************************************
** Form generated from reading UI file 'transformwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFORMWIDGET_H
#define UI_TRANSFORMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TransformWidget
{
public:
    QGridLayout *gridLayout;
    QGroupBox *Transform;
    QGridLayout *gridLayout_2;
    QHBoxLayout *Rot;
    QLabel *label_Rot;
    QHBoxLayout *Rot_X;
    QLabel *label_Rot_X;
    QDoubleSpinBox *val_Rot_X;
    QHBoxLayout *Rot_Y;
    QLabel *label_Rot_Y;
    QDoubleSpinBox *val_Rot_Y;
    QHBoxLayout *Rot_Z;
    QLabel *label_Rot_Z;
    QDoubleSpinBox *val_Rot_Z;
    QHBoxLayout *Scale;
    QLabel *label_Scale;
    QHBoxLayout *Scale_X;
    QLabel *label_Scale_X;
    QDoubleSpinBox *val_Scale_X;
    QHBoxLayout *Scale_Y;
    QLabel *label_Scale_Y;
    QDoubleSpinBox *val_Scale_Y;
    QHBoxLayout *Scale_Z;
    QLabel *label_Scale_Z;
    QDoubleSpinBox *val_Scale_Z;
    QHBoxLayout *Pos;
    QLabel *label_Pos;
    QHBoxLayout *Pos_X;
    QLabel *label_Pos_X;
    QDoubleSpinBox *val_Pos_X;
    QHBoxLayout *Pos_Y;
    QLabel *label_Pos_Y;
    QDoubleSpinBox *val_Pos_Y;
    QHBoxLayout *Pos_Z;
    QLabel *label_Pos_Z;
    QDoubleSpinBox *val_Pos_Z;

    void setupUi(QWidget *TransformWidget)
    {
        if (TransformWidget->objectName().isEmpty())
            TransformWidget->setObjectName(QStringLiteral("TransformWidget"));
        TransformWidget->setEnabled(true);
        TransformWidget->resize(763, 140);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TransformWidget->sizePolicy().hasHeightForWidth());
        TransformWidget->setSizePolicy(sizePolicy);
        TransformWidget->setMinimumSize(QSize(360, 140));
        TransformWidget->setMaximumSize(QSize(16777215, 140));
        TransformWidget->setFocusPolicy(Qt::ClickFocus);
        TransformWidget->setStyleSheet(QLatin1String("QToolTip {\n"
"    border: 1px solid #76797C;\n"
"    background-color: #5A7566;\n"
"    color: white;\n"
"    padding: 0px;                /*remove padding, for fix combobox tooltip.*/\n"
"    opacity: 200;\n"
"}\n"
"\n"
"QWidget {\n"
"    color: #eff0f1;\n"
"    background-color: #31363b;\n"
"    selection-background-color: #3daee9;\n"
"    selection-color: #eff0f1;\n"
"    background-clip: border;\n"
"    border-image: none;\n"
"    border: 0px transparent black;\n"
"    outline: 0;\n"
"}\n"
"\n"
"QWidget:item:hover {\n"
"    background-color: #18465d;\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"QWidget:item:selected {\n"
"    background-color: #18465d;\n"
"}\n"
"\n"
"QCheckBox {\n"
"    spacing: 5px;\n"
"    outline: none;\n"
"    color: #eff0f1;\n"
"    margin-bottom: 2px;\n"
"}\n"
"\n"
"QCheckBox:disabled {\n"
"    color: #76797C;\n"
"}\n"
"\n"
"QCheckBox::indicator,\n"
"QGroupBox::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"}\n"
"\n"
"QGroupBox::indicator {\n"
"    margin-left: 2px;\n"
"}\n"
""
                        "\n"
"QCheckBox::indicator:unchecked,\n"
"QGroupBox::indicator:unchecked {\n"
"    image: url(:/qss_icons/rc/checkbox_unchecked.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover,\n"
"QCheckBox::indicator:unchecked:focus,\n"
"QCheckBox::indicator:unchecked:pressed,\n"
"QGroupBox::indicator:unchecked:hover,\n"
"QGroupBox::indicator:unchecked:focus,\n"
"QGroupBox::indicator:unchecked:pressed {\n"
"    border: none;\n"
"    image: url(:/qss_icons/rc/checkbox_unchecked_focus.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked,\n"
"QGroupBox::indicator:checked {\n"
"    image: url(:/qss_icons/rc/checkbox_checked.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:hover,\n"
"QCheckBox::indicator:checked:focus,\n"
"QCheckBox::indicator:checked:pressed,\n"
"QGroupBox::indicator:checked:hover,\n"
"QGroupBox::indicator:checked:focus,\n"
"QGroupBox::indicator:checked:pressed {\n"
"    border: none;\n"
"    image: url(:/qss_icons/rc/checkbox_checked_focus.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:indeterminate {\n"
"   "
                        " image: url(:/qss_icons/rc/checkbox_indeterminate.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:indeterminate:focus,\n"
"QCheckBox::indicator:indeterminate:hover,\n"
"QCheckBox::indicator:indeterminate:pressed {\n"
"    image: url(:/qss_icons/rc/checkbox_indeterminate_focus.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:disabled,\n"
"QGroupBox::indicator:checked:disabled {\n"
"    image: url(:/qss_icons/rc/checkbox_checked_disabled.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:disabled,\n"
"QGroupBox::indicator:unchecked:disabled {\n"
"    image: url(:/qss_icons/rc/checkbox_unchecked_disabled.png);\n"
"}\n"
"\n"
"QRadioButton {\n"
"    spacing: 5px;\n"
"    outline: none;\n"
"    color: #eff0f1;\n"
"    margin-bottom: 2px;\n"
"}\n"
"\n"
"QRadioButton:disabled {\n"
"    color: #76797C;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 21px;\n"
"    height: 21px;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked {\n"
"    image: url(:/qss_icons/rc/radio_unchecked.png);\n"
"}\n"
"\n"
"QRadioButton::indi"
                        "cator:unchecked:hover,\n"
"QRadioButton::indicator:unchecked:focus,\n"
"QRadioButton::indicator:unchecked:pressed {\n"
"    border: none;\n"
"    outline: none;\n"
"    image: url(:/qss_icons/rc/radio_unchecked_focus.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    border: none;\n"
"    outline: none;\n"
"    image: url(:/qss_icons/rc/radio_checked.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:hover,\n"
"QRadioButton::indicator:checked:focus,\n"
"QRadioButton::indicator:checked:pressed {\n"
"    border: none;\n"
"    outline: none;\n"
"    image: url(:/qss_icons/rc/radio_checked_focus.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:disabled {\n"
"    outline: none;\n"
"    image: url(:/qss_icons/rc/radio_checked_disabled.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:disabled {\n"
"    image: url(:/qss_icons/rc/radio_unchecked_disabled.png);\n"
"}\n"
"\n"
"QMenuBar {\n"
"    background-color: #31363b;\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"QMenuBar::item {\n"
"    background: "
                        "transparent;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background: transparent;\n"
"    border: 1px solid #76797C;\n"
"}\n"
"\n"
"QMenuBar::item:pressed {\n"
"    border: 1px solid #76797C;\n"
"    background-color: #3daee9;\n"
"    color: #eff0f1;\n"
"    margin-bottom: -1px;\n"
"    padding-bottom: 1px;\n"
"}\n"
"\n"
"QMenu {\n"
"    border: 1px solid #76797C;\n"
"    color: #eff0f1;\n"
"    margin: 2px;\n"
"}\n"
"\n"
"QMenu::icon {\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QMenu::item {\n"
"    padding: 5px 30px 5px 30px;\n"
"    border: 1px solid transparent;\n"
"    /* reserve space for selection border */\n"
"}\n"
"\n"
"QMenu::item:selected {\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"QMenu::separator {\n"
"    height: 2px;\n"
"    background: lightblue;\n"
"    margin-left: 10px;\n"
"    margin-right: 5px;\n"
"}\n"
"\n"
"QMenu::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"}\n"
"\n"
"\n"
"/* non-exclusive indicator = check box style indicator\n"
"   (see QActionGroup::setExclusive) */\n"
"\n"
""
                        "QMenu::indicator:non-exclusive:unchecked {\n"
"    image: url(:/qss_icons/rc/checkbox_unchecked.png);\n"
"}\n"
"\n"
"QMenu::indicator:non-exclusive:unchecked:selected {\n"
"    image: url(:/qss_icons/rc/checkbox_unchecked_disabled.png);\n"
"}\n"
"\n"
"QMenu::indicator:non-exclusive:checked {\n"
"    image: url(:/qss_icons/rc/checkbox_checked.png);\n"
"}\n"
"\n"
"QMenu::indicator:non-exclusive:checked:selected {\n"
"    image: url(:/qss_icons/rc/checkbox_checked_disabled.png);\n"
"}\n"
"\n"
"\n"
"/* exclusive indicator = radio button style indicator (see QActionGroup::setExclusive) */\n"
"\n"
"QMenu::indicator:exclusive:unchecked {\n"
"    image: url(:/qss_icons/rc/radio_unchecked.png);\n"
"}\n"
"\n"
"QMenu::indicator:exclusive:unchecked:selected {\n"
"    image: url(:/qss_icons/rc/radio_unchecked_disabled.png);\n"
"}\n"
"\n"
"QMenu::indicator:exclusive:checked {\n"
"    image: url(:/qss_icons/rc/radio_checked.png);\n"
"}\n"
"\n"
"QMenu::indicator:exclusive:checked:selected {\n"
"    image: url(:/qss_icons/rc/r"
                        "adio_checked_disabled.png);\n"
"}\n"
"\n"
"QMenu::right-arrow {\n"
"    margin: 5px;\n"
"    image: url(:/qss_icons/rc/right_arrow.png)\n"
"}\n"
"\n"
"QWidget:disabled {\n"
"    color: #454545;\n"
"    background-color: #31363b;\n"
"}\n"
"\n"
"QAbstractItemView {\n"
"    alternate-background-color: #31363b;\n"
"    color: #eff0f1;\n"
"    border: 1px solid #3A3939;\n"
"    border-radius: 2px;\n"
"}\n"
"\n"
"QWidget:focus,\n"
"QMenuBar:focus {\n"
"    border: 1px solid #3daee9;\n"
"}\n"
"\n"
"QTabWidget:focus,\n"
"QCheckBox:focus,\n"
"QRadioButton:focus,\n"
"QSlider:focus {\n"
"    border: none;\n"
"}\n"
"\n"
"QLineEdit {\n"
"    background-color: #232629;\n"
"    padding: 5px;\n"
"    border-style: solid;\n"
"    border: 1px solid #76797C;\n"
"    border-radius: 2px;\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"QAbstractItemView QLineEdit {\n"
"    padding: 0;\n"
"}\n"
"\n"
"QGroupBox {\n"
"    border: 1px solid #76797C;\n"
"    border-radius: 2px;\n"
"    margin-top: 20px;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    "
                        "subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding-left: 10px;\n"
"    padding-right: 10px;\n"
"    padding-top: 10px;\n"
"}\n"
"\n"
"QAbstractScrollArea {\n"
"    border-radius: 2px;\n"
"    border: 1px solid #76797C;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    height: 15px;\n"
"    margin: 3px 15px 3px 15px;\n"
"    border: 1px transparent #2A2929;\n"
"    border-radius: 4px;\n"
"    background-color: #2A2929;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background-color: #605F5F;\n"
"    min-width: 5px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal {\n"
"    margin: 0px 3px 0px 3px;\n"
"    border-image: url(:/qss_icons/rc/right_arrow_disabled.png);\n"
"    width: 10px;\n"
"    height: 10px;\n"
"    subcontrol-position: right;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal {\n"
"    margin: 0px 3px 0px 3px;\n"
"    border-image: url(:/qss_icons/rc/left_arrow_di"
                        "sabled.png);\n"
"    height: 10px;\n"
"    width: 10px;\n"
"    subcontrol-position: left;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal:hover,\n"
"QScrollBar::add-line:horizontal:on {\n"
"    border-image: url(:/qss_icons/rc/right_arrow.png);\n"
"    height: 10px;\n"
"    width: 10px;\n"
"    subcontrol-position: right;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal:hover,\n"
"QScrollBar::sub-line:horizontal:on {\n"
"    border-image: url(:/qss_icons/rc/left_arrow.png);\n"
"    height: 10px;\n"
"    width: 10px;\n"
"    subcontrol-position: left;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::up-arrow:horizontal,\n"
"QScrollBar::down-arrow:horizontal {\n"
"    background: none;\n"
"}\n"
"\n"
"QScrollBar::add-page:horizontal,\n"
"QScrollBar::sub-page:horizontal {\n"
"    background: none;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    background-color: #2A2929;\n"
"    width: 15px;\n"
"    margin: 15px 3px 15px 3px;\n"
"    bor"
                        "der: 1px transparent #2A2929;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background-color: #605F5F;\n"
"    min-height: 5px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical {\n"
"    margin: 3px 0px 3px 0px;\n"
"    border-image: url(:/qss_icons/rc/up_arrow_disabled.png);\n"
"    height: 10px;\n"
"    width: 10px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical {\n"
"    margin: 3px 0px 3px 0px;\n"
"    border-image: url(:/qss_icons/rc/down_arrow_disabled.png);\n"
"    height: 10px;\n"
"    width: 10px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical:hover,\n"
"QScrollBar::sub-line:vertical:on {\n"
"    border-image: url(:/qss_icons/rc/up_arrow.png);\n"
"    height: 10px;\n"
"    width: 10px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical:hover,\n"
""
                        "QScrollBar::add-line:vertical:on {\n"
"    border-image: url(:/qss_icons/rc/down_arrow.png);\n"
"    height: 10px;\n"
"    width: 10px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::up-arrow:vertical,\n"
"QScrollBar::down-arrow:vertical {\n"
"    background: none;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical,\n"
"QScrollBar::sub-page:vertical {\n"
"    background: none;\n"
"}\n"
"\n"
"QTextEdit {\n"
"    background-color: #232629;\n"
"    color: #eff0f1;\n"
"    border: 1px solid #76797C;\n"
"}\n"
"\n"
"QPlainTextEdit {\n"
"    background-color: #232629;\n"
"    ;\n"
"    color: #eff0f1;\n"
"    border-radius: 2px;\n"
"    border: 1px solid #76797C;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #76797C;\n"
"    color: #eff0f1;\n"
"    padding: 5px;\n"
"    border: 1px solid #76797C;\n"
"}\n"
"\n"
"QSizeGrip {\n"
"    image: url(:/qss_icons/rc/sizegrip.png);\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
"\n"
"QMainWindow::separator {\n"
""
                        "    background-color: #31363b;\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    spacing: 2px;\n"
"    border: 1px dashed #76797C;\n"
"}\n"
"\n"
"QMainWindow::separator:hover {\n"
"    background-color: #787876;\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #76797C;\n"
"    spacing: 2px;\n"
"}\n"
"\n"
"QMenu::separator {\n"
"    height: 1px;\n"
"    background-color: #76797C;\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    margin-left: 10px;\n"
"    margin-right: 5px;\n"
"}\n"
"\n"
"QFrame {\n"
"    border-radius: 2px;\n"
"    border: 1px solid #76797C;\n"
"}\n"
"\n"
"QFrame[frameShape=\"0\"] {\n"
"    border-radius: 2px;\n"
"    border: 1px transparent #76797C;\n"
"}\n"
"\n"
"QStackedWidget {\n"
"    border: 1px transparent black;\n"
"}\n"
"\n"
"QToolBar {\n"
"    border: 1px transparent #393838;\n"
"    background: 1px solid #31363b;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QToolBar::handle:horizontal {\n"
"    image: url(:/qss_icons/rc/Hmovetoolbar.png);\n"
"}\n"
""
                        "\n"
"QToolBar::handle:vertical {\n"
"    image: url(:/qss_icons/rc/Vmovetoolbar.png);\n"
"}\n"
"\n"
"QToolBar::separator:horizontal {\n"
"    image: url(:/qss_icons/rc/Hsepartoolbar.png);\n"
"}\n"
"\n"
"QToolBar::separator:vertical {\n"
"    image: url(:/qss_icons/rc/Vsepartoolbar.png);\n"
"}\n"
"\n"
"QToolButton#qt_toolbar_ext_button {\n"
"    background: #58595a\n"
"}\n"
"\n"
"QPushButton {\n"
"    color: #eff0f1;\n"
"    background-color: #31363b;\n"
"    border-width: 1px;\n"
"    border-color: #76797C;\n"
"    border-style: solid;\n"
"    padding: 5px;\n"
"    border-radius: 2px;\n"
"    outline: none;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #31363b;\n"
"    border-width: 1px;\n"
"    border-color: #454545;\n"
"    border-style: solid;\n"
"    padding-top: 5px;\n"
"    padding-bottom: 5px;\n"
"    padding-left: 10px;\n"
"    padding-right: 10px;\n"
"    border-radius: 2px;\n"
"    color: #454545;\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    background-color: #3daee9;\n"
"    color: w"
                        "hite;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #3daee9;\n"
"    padding-top: -15px;\n"
"    padding-bottom: -17px;\n"
"}\n"
"\n"
"QComboBox {\n"
"    selection-background-color: #3daee9;\n"
"    border-style: solid;\n"
"    border: 1px solid #76797C;\n"
"    border-radius: 2px;\n"
"    padding: 5px;\n"
"    min-width: 75px;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    background-color: #76797C;\n"
"    border-color: #6A6969;\n"
"}\n"
"\n"
"QComboBox:hover,\n"
"QPushButton:hover,\n"
"QAbstractSpinBox:hover,\n"
"QLineEdit:hover,\n"
"QTextEdit:hover,\n"
"QPlainTextEdit:hover,\n"
"QAbstractView:hover,\n"
"QTreeView:hover {\n"
"    border: 1px solid #3daee9;\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"QComboBox:on {\n"
"    padding-top: 3px;\n"
"    padding-left: 4px;\n"
"    selection-background-color: #4a4a4a;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #232629;\n"
"    border-radius: 2px;\n"
"    border: 1px solid #76797C;\n"
"    selection-background-color: #18465d;\n"
""
                        "}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"    border-left-width: 0px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/qss_icons/rc/down_arrow_disabled.png);\n"
"}\n"
"\n"
"QComboBox::down-arrow:on,\n"
"QComboBox::down-arrow:hover,\n"
"QComboBox::down-arrow:focus {\n"
"    image: url(:/qss_icons/rc/down_arrow.png);\n"
"}\n"
"\n"
"QAbstractSpinBox {\n"
"    padding: 5px;\n"
"    border: 1px solid #76797C;\n"
"    background-color: #232629;\n"
"    color: #eff0f1;\n"
"    border-radius: 2px;\n"
"    min-width: 75px;\n"
"}\n"
"\n"
"QAbstractSpinBox:up-button {\n"
"    background-color: transparent;\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: top right;\n"
"}\n"
"\n"
"QAbstractSpinBox:down-button {\n"
"    background-color: transparent;\n"
"    "
                        "subcontrol-origin: border;\n"
"    subcontrol-position: bottom right;\n"
"}\n"
"\n"
"QAbstractSpinBox::up-arrow,\n"
"QAbstractSpinBox::up-arrow:disabled,\n"
"QAbstractSpinBox::up-arrow:off {\n"
"    image: url(:/qss_icons/rc/up_arrow_disabled.png);\n"
"    width: 10px;\n"
"    height: 10px;\n"
"}\n"
"\n"
"QAbstractSpinBox::up-arrow:hover {\n"
"    image: url(:/qss_icons/rc/up_arrow.png);\n"
"}\n"
"\n"
"QAbstractSpinBox::down-arrow,\n"
"QAbstractSpinBox::down-arrow:disabled,\n"
"QAbstractSpinBox::down-arrow:off {\n"
"    image: url(:/qss_icons/rc/down_arrow_disabled.png);\n"
"    width: 10px;\n"
"    height: 10px;\n"
"}\n"
"\n"
"QAbstractSpinBox::down-arrow:hover {\n"
"    image: url(:/qss_icons/rc/down_arrow.png);\n"
"}\n"
"\n"
"QLabel {\n"
"    border: 0px solid black;\n"
"}\n"
"\n"
"QTabWidget {\n"
"    border: 0px transparent black;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    border: 1px solid #76797C;\n"
"    padding: 5px;\n"
"    margin: 0px;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"    /* left: 5px; move t"
                        "o the right by 5px */\n"
"}\n"
"\n"
"QTabBar {\n"
"    qproperty-drawBase: 0;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QTabBar:focus {\n"
"    border: 0px transparent black;\n"
"}\n"
"\n"
"QTabBar::close-button {\n"
"    image: url(:/qss_icons/rc/close.png);\n"
"    background: transparent;\n"
"}\n"
"\n"
"QTabBar::close-button:hover {\n"
"    image: url(:/qss_icons/rc/close-hover.png);\n"
"    background: transparent;\n"
"}\n"
"\n"
"QTabBar::close-button:pressed {\n"
"    image: url(:/qss_icons/rc/close-pressed.png);\n"
"    background: transparent;\n"
"}\n"
"\n"
"\n"
"/* TOP TABS */\n"
"\n"
"QTabBar::tab:top {\n"
"    color: #eff0f1;\n"
"    border: 1px solid #76797C;\n"
"    border-bottom: 1px transparent black;\n"
"    background-color: #31363b;\n"
"    padding: 5px;\n"
"    min-width: 50px;\n"
"    border-top-left-radius: 2px;\n"
"    border-top-right-radius: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:top:selected {\n"
"    color: #eff0f1;\n"
"    background-color: #54575B;\n"
"    border: 1px solid #76797C;\n"
" "
                        "   border-bottom: 2px solid #3daee9;\n"
"    border-top-left-radius: 2px;\n"
"    border-top-right-radius: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:top:!selected:hover {\n"
"    background-color: #3daee9;\n"
"}\n"
"\n"
"\n"
"/* BOTTOM TABS */\n"
"\n"
"QTabBar::tab:bottom {\n"
"    color: #eff0f1;\n"
"    border: 1px solid #76797C;\n"
"    border-top: 1px transparent black;\n"
"    background-color: #31363b;\n"
"    padding: 5px;\n"
"    border-bottom-left-radius: 2px;\n"
"    border-bottom-right-radius: 2px;\n"
"    min-width: 50px;\n"
"}\n"
"\n"
"QTabBar::tab:bottom:selected {\n"
"    color: #eff0f1;\n"
"    background-color: #54575B;\n"
"    border: 1px solid #76797C;\n"
"    border-top: 2px solid #3daee9;\n"
"    border-bottom-left-radius: 2px;\n"
"    border-bottom-right-radius: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:bottom:!selected:hover {\n"
"    background-color: #3daee9;\n"
"}\n"
"\n"
"\n"
"/* LEFT TABS */\n"
"\n"
"QTabBar::tab:left {\n"
"    color: #eff0f1;\n"
"    border: 1px solid #76797C;\n"
"    border-left: 1"
                        "px transparent black;\n"
"    background-color: #31363b;\n"
"    padding: 5px;\n"
"    border-top-right-radius: 2px;\n"
"    border-bottom-right-radius: 2px;\n"
"    min-height: 50px;\n"
"}\n"
"\n"
"QTabBar::tab:left:selected {\n"
"    color: #eff0f1;\n"
"    background-color: #54575B;\n"
"    border: 1px solid #76797C;\n"
"    border-left: 2px solid #3daee9;\n"
"    border-top-right-radius: 2px;\n"
"    border-bottom-right-radius: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:left:!selected:hover {\n"
"    background-color: #3daee9;\n"
"}\n"
"\n"
"\n"
"/* RIGHT TABS */\n"
"\n"
"QTabBar::tab:right {\n"
"    color: #eff0f1;\n"
"    border: 1px solid #76797C;\n"
"    border-right: 1px transparent black;\n"
"    background-color: #31363b;\n"
"    padding: 5px;\n"
"    border-top-left-radius: 2px;\n"
"    border-bottom-left-radius: 2px;\n"
"    min-height: 50px;\n"
"}\n"
"\n"
"QTabBar::tab:right:selected {\n"
"    color: #eff0f1;\n"
"    background-color: #54575B;\n"
"    border: 1px solid #76797C;\n"
"    border-right: 2px so"
                        "lid #3daee9;\n"
"    border-top-left-radius: 2px;\n"
"    border-bottom-left-radius: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:right:!selected:hover {\n"
"    background-color: #3daee9;\n"
"}\n"
"\n"
"QTabBar QToolButton::right-arrow:enabled {\n"
"    image: url(:/qss_icons/rc/right_arrow.png);\n"
"}\n"
"\n"
"QTabBar QToolButton::left-arrow:enabled {\n"
"    image: url(:/qss_icons/rc/left_arrow.png);\n"
"}\n"
"\n"
"QTabBar QToolButton::right-arrow:disabled {\n"
"    image: url(:/qss_icons/rc/right_arrow_disabled.png);\n"
"}\n"
"\n"
"QTabBar QToolButton::left-arrow:disabled {\n"
"    image: url(:/qss_icons/rc/left_arrow_disabled.png);\n"
"}\n"
"\n"
"QDockWidget {\n"
"    background: #31363b;\n"
"    border: 1px solid #403F3F;\n"
"    titlebar-close-icon: url(:/qss_icons/rc/close.png);\n"
"    titlebar-normal-icon: url(:/qss_icons/rc/undock.png);\n"
"}\n"
"\n"
"QDockWidget::close-button,\n"
"QDockWidget::float-button {\n"
"    border: 1px solid transparent;\n"
"    border-radius: 2px;\n"
"    background: transparent;\n"
""
                        "}\n"
"\n"
"QDockWidget::close-button:hover,\n"
"QDockWidget::float-button:hover {\n"
"    background: rgba(255, 255, 255, 10);\n"
"}\n"
"\n"
"QDockWidget::close-button:pressed,\n"
"QDockWidget::float-button:pressed {\n"
"    padding: 1px -1px -1px 1px;\n"
"    background: rgba(255, 255, 255, 10);\n"
"}\n"
"\n"
"QTreeView,\n"
"QListView {\n"
"    border: 1px solid #76797C;\n"
"    background-color: #232629;\n"
"}\n"
"\n"
"QTreeView:branch:selected,\n"
"QTreeView:branch:hover {\n"
"    background: url(:/qss_icons/rc/transparent.png);\n"
"}\n"
"\n"
"QTreeView::branch:has-siblings:!adjoins-item {\n"
"    border-image: url(:/qss_icons/rc/transparent.png);\n"
"}\n"
"\n"
"QTreeView::branch:has-siblings:adjoins-item {\n"
"    border-image: url(:/qss_icons/rc/transparent.png);\n"
"}\n"
"\n"
"QTreeView::branch:!has-children:!has-siblings:adjoins-item {\n"
"    border-image: url(:/qss_icons/rc/transparent.png);\n"
"}\n"
"\n"
"QTreeView::branch:has-children:!has-siblings:closed,\n"
"QTreeView::branch:closed:has-children:h"
                        "as-siblings {\n"
"    image: url(:/qss_icons/rc/branch_closed.png);\n"
"}\n"
"\n"
"QTreeView::branch:open:has-children:!has-siblings,\n"
"QTreeView::branch:open:has-children:has-siblings {\n"
"    image: url(:/qss_icons/rc/branch_open.png);\n"
"}\n"
"\n"
"QTreeView::branch:has-children:!has-siblings:closed:hover,\n"
"QTreeView::branch:closed:has-children:has-siblings:hover {\n"
"    image: url(:/qss_icons/rc/branch_closed-on.png);\n"
"}\n"
"\n"
"QTreeView::branch:open:has-children:!has-siblings:hover,\n"
"QTreeView::branch:open:has-children:has-siblings:hover {\n"
"    image: url(:/qss_icons/rc/branch_open-on.png);\n"
"}\n"
"\n"
"QListView::item:!selected:hover,\n"
"QTreeView::item:!selected:hover {\n"
"    background: #18465d;\n"
"    outline: 0;\n"
"    color: #eff0f1\n"
"}\n"
"\n"
"QListView::item:selected:hover,\n"
"QTreeView::item:selected:hover {\n"
"    background: #287399;\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"QTreeView::indicator:checked,\n"
"QListView::indicator:checked {\n"
"    image: url(:/qss_ic"
                        "ons/rc/checkbox_checked.png);\n"
"}\n"
"\n"
"QTreeView::indicator:unchecked,\n"
"QListView::indicator:unchecked {\n"
"    image: url(:/qss_icons/rc/checkbox_unchecked.png);\n"
"}\n"
"\n"
"QTreeView::indicator:checked:hover,\n"
"QTreeView::indicator:checked:focus,\n"
"QTreeView::indicator:checked:pressed,\n"
"QListView::indicator:checked:hover,\n"
"QListView::indicator:checked:focus,\n"
"QListView::indicator:checked:pressed {\n"
"    image: url(:/qss_icons/rc/checkbox_checked_focus.png);\n"
"}\n"
"\n"
"QTreeView::indicator:unchecked:hover,\n"
"QTreeView::indicator:unchecked:focus,\n"
"QTreeView::indicator:unchecked:pressed,\n"
"QListView::indicator:unchecked:hover,\n"
"QListView::indicator:unchecked:focus,\n"
"QListView::indicator:unchecked:pressed {\n"
"    image: url(:/qss_icons/rc/checkbox_unchecked_focus.png);\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    border: 1px solid #565a5e;\n"
"    height: 4px;\n"
"    background: #565a5e;\n"
"    margin: 0px;\n"
"    border-radius: 2px;\n"
"}\n"
"\n"
"QSlider"
                        "::handle:horizontal {\n"
"    background: #232629;\n"
"    border: 1px solid #565a5e;\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    margin: -8px 0;\n"
"    border-radius: 9px;\n"
"}\n"
"\n"
"QSlider::groove:vertical {\n"
"    border: 1px solid #565a5e;\n"
"    width: 4px;\n"
"    background: #565a5e;\n"
"    margin: 0px;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QSlider::handle:vertical {\n"
"    background: #232629;\n"
"    border: 1px solid #565a5e;\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    margin: 0 -8px;\n"
"    border-radius: 9px;\n"
"}\n"
"\n"
"QToolButton {\n"
"    background-color: transparent;\n"
"    border: 1px transparent #76797C;\n"
"    border-radius: 2px;\n"
"    margin: 3px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QToolButton[popupMode=\"1\"] {\n"
"    /* only for MenuButtonPopup */\n"
"    padding-right: 20px;\n"
"    /* make way for the popup button */\n"
"    border: 1px #76797C;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QToolButton[popupMode=\"2\"] {\n"
"    /* only for Instant"
                        "Popup */\n"
"    padding-right: 10px;\n"
"    /* make way for the popup button */\n"
"    border: 1px #76797C;\n"
"}\n"
"\n"
"QToolButton:hover,\n"
"QToolButton::menu-button:hover {\n"
"    background-color: transparent;\n"
"    border: 1px solid #3daee9;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QToolButton:checked,\n"
"QToolButton:pressed,\n"
"QToolButton::menu-button:pressed {\n"
"    background-color: #3daee9;\n"
"    border: 1px solid #3daee9;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"\n"
"/* the subcontrol below is used only in the InstantPopup or DelayedPopup mode */\n"
"\n"
"QToolButton::menu-indicator {\n"
"    image: url(:/qss_icons/rc/down_arrow.png);\n"
"    top: -7px;\n"
"    left: -2px;\n"
"    /* shift it a bit */\n"
"}\n"
"\n"
"\n"
"/* the subcontrols below are used only in the MenuButtonPopup mode */\n"
"\n"
"QToolButton::menu-button {\n"
"    border: 1px transparent #76797C;\n"
"    border-top-right-radius: 6px;\n"
"    border-bottom-right-radius: 6px;\n"
"    /* 16px width + 4px for border = 20px allo"
                        "cated above */\n"
"    width: 16px;\n"
"    outline: none;\n"
"}\n"
"\n"
"QToolButton::menu-arrow {\n"
"    image: url(:/qss_icons/rc/down_arrow.png);\n"
"}\n"
"\n"
"QToolButton::menu-arrow:open {\n"
"    border: 1px solid #76797C;\n"
"}\n"
"\n"
"QPushButton::menu-indicator {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: bottom right;\n"
"    left: 8px;\n"
"}\n"
"\n"
"QTableView {\n"
"    border: 1px solid #76797C;\n"
"    gridline-color: #31363b;\n"
"    background-color: #232629;\n"
"}\n"
"\n"
"QTableView,\n"
"QHeaderView {\n"
"    border-radius: 0px;\n"
"}\n"
"\n"
"QTableView::item:pressed,\n"
"QListView::item:pressed,\n"
"QTreeView::item:pressed {\n"
"    background: #18465d;\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"QTableView::item:selected:active,\n"
"QTreeView::item:selected:active,\n"
"QListView::item:selected:active {\n"
"    background: #287399;\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"QHeaderView {\n"
"    background-color: #31363b;\n"
"    border: 1px transparent;\n"
"    border-radi"
                        "us: 0px;\n"
"    margin: 0px;\n"
"    padding: 0px;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #31363b;\n"
"    color: #eff0f1;\n"
"    padding: 5px;\n"
"    border: 1px solid #76797C;\n"
"    border-radius: 0px;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QHeaderView::section::vertical::first,\n"
"QHeaderView::section::vertical::only-one {\n"
"    border-top: 1px solid #76797C;\n"
"}\n"
"\n"
"QHeaderView::section::vertical {\n"
"    border-top: transparent;\n"
"}\n"
"\n"
"QHeaderView::section::horizontal::first,\n"
"QHeaderView::section::horizontal::only-one {\n"
"    border-left: 1px solid #76797C;\n"
"}\n"
"\n"
"QHeaderView::section::horizontal {\n"
"    border-left: transparent;\n"
"}\n"
"\n"
"QHeaderView::section:checked {\n"
"    color: white;\n"
"    background-color: #334e5e;\n"
"}\n"
"\n"
"\n"
"/* style the sort indicator */\n"
"\n"
"QHeaderView::down-arrow {\n"
"    image: url(:/qss_icons/rc/down_arrow.png);\n"
"}\n"
"\n"
"QHeaderView::up-arrow {\n"
"    image: url(:/qss_icons/rc/"
                        "up_arrow.png);\n"
"}\n"
"\n"
"QTableCornerButton::section {\n"
"    background-color: #31363b;\n"
"    border: 1px transparent #76797C;\n"
"    border-radius: 0px;\n"
"}\n"
"\n"
"QToolBox {\n"
"    padding: 5px;\n"
"    border: 1px transparent black;\n"
"}\n"
"\n"
"QToolBox::tab {\n"
"    color: #eff0f1;\n"
"    background-color: #31363b;\n"
"    border: 1px solid #76797C;\n"
"    border-bottom: 1px transparent #31363b;\n"
"    border-top-left-radius: 5px;\n"
"    border-top-right-radius: 5px;\n"
"}\n"
"\n"
"QToolBox::tab:selected {\n"
"    /* italicize selected tabs */\n"
"    font: italic;\n"
"    background-color: #31363b;\n"
"    border-color: #3daee9;\n"
"}\n"
"\n"
"QStatusBar::item {\n"
"    border: 0px transparent dark;\n"
"}\n"
"\n"
"QFrame[height=\"3\"],\n"
"QFrame[width=\"3\"] {\n"
"    background-color: #76797C;\n"
"}\n"
"\n"
"QSplitter::handle {\n"
"    border: 1px dashed #76797C;\n"
"}\n"
"\n"
"QSplitter::handle:hover {\n"
"    background-color: #787876;\n"
"    border: 1px solid #76797C;\n"
"}\n"
""
                        "\n"
"QSplitter::handle:horizontal {\n"
"    width: 1px;\n"
"}\n"
"\n"
"QSplitter::handle:vertical {\n"
"    height: 1px;\n"
"}\n"
"\n"
"QProgressBar {\n"
"    border: 1px solid #76797C;\n"
"    border-radius: 5px;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #05B8CC;\n"
"}\n"
"\n"
"QDateEdit {\n"
"    selection-background-color: #3daee9;\n"
"    border-style: solid;\n"
"    border: 1px solid #3375A3;\n"
"    border-radius: 2px;\n"
"    padding: 1px;\n"
"    min-width: 75px;\n"
"}\n"
"\n"
"QDateEdit:on {\n"
"    padding-top: 3px;\n"
"    padding-left: 4px;\n"
"    selection-background-color: #4a4a4a;\n"
"}\n"
"\n"
"QDateEdit QAbstractItemView {\n"
"    background-color: #232629;\n"
"    border-radius: 2px;\n"
"    border: 1px solid #3375A3;\n"
"    selection-background-color: #3daee9;\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"    border-left-width: 0px;\n"
"    border-le"
                        "ft-color: darkgray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QDateEdit::down-arrow {\n"
"    image: url(:/qss_icons/rc/down_arrow_disabled.png);\n"
"}\n"
"\n"
"QDateEdit::down-arrow:on,\n"
"QDateEdit::down-arrow:hover,\n"
"QDateEdit::down-arrow:focus {\n"
"    image: url(:/qss_icons/rc/down_arrow.png);\n"
"}\n"
""));
        gridLayout = new QGridLayout(TransformWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Transform = new QGroupBox(TransformWidget);
        Transform->setObjectName(QStringLiteral("Transform"));
        Transform->setEnabled(true);
        sizePolicy.setHeightForWidth(Transform->sizePolicy().hasHeightForWidth());
        Transform->setSizePolicy(sizePolicy);
        Transform->setFocusPolicy(Qt::ClickFocus);
        gridLayout_2 = new QGridLayout(Transform);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_2->setHorizontalSpacing(0);
        gridLayout_2->setVerticalSpacing(10);
        gridLayout_2->setContentsMargins(5, 5, 5, 5);
        Rot = new QHBoxLayout();
        Rot->setObjectName(QStringLiteral("Rot"));
        Rot->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_Rot = new QLabel(Transform);
        label_Rot->setObjectName(QStringLiteral("label_Rot"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_Rot->sizePolicy().hasHeightForWidth());
        label_Rot->setSizePolicy(sizePolicy1);
        label_Rot->setMinimumSize(QSize(25, 0));

        Rot->addWidget(label_Rot);

        Rot_X = new QHBoxLayout();
        Rot_X->setSpacing(2);
        Rot_X->setObjectName(QStringLiteral("Rot_X"));
        Rot_X->setSizeConstraint(QLayout::SetDefaultConstraint);
        Rot_X->setContentsMargins(6, -1, -1, -1);
        label_Rot_X = new QLabel(Transform);
        label_Rot_X->setObjectName(QStringLiteral("label_Rot_X"));
        sizePolicy1.setHeightForWidth(label_Rot_X->sizePolicy().hasHeightForWidth());
        label_Rot_X->setSizePolicy(sizePolicy1);
        label_Rot_X->setLayoutDirection(Qt::LeftToRight);
        label_Rot_X->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Rot_X->addWidget(label_Rot_X);

        val_Rot_X = new QDoubleSpinBox(Transform);
        val_Rot_X->setObjectName(QStringLiteral("val_Rot_X"));
        sizePolicy.setHeightForWidth(val_Rot_X->sizePolicy().hasHeightForWidth());
        val_Rot_X->setSizePolicy(sizePolicy);
        val_Rot_X->setFocusPolicy(Qt::ClickFocus);
        val_Rot_X->setMinimum(-1.67772e+7);
        val_Rot_X->setMaximum(1.67772e+7);

        Rot_X->addWidget(val_Rot_X);


        Rot->addLayout(Rot_X);

        Rot_Y = new QHBoxLayout();
        Rot_Y->setSpacing(2);
        Rot_Y->setObjectName(QStringLiteral("Rot_Y"));
        Rot_Y->setSizeConstraint(QLayout::SetDefaultConstraint);
        Rot_Y->setContentsMargins(6, -1, -1, -1);
        label_Rot_Y = new QLabel(Transform);
        label_Rot_Y->setObjectName(QStringLiteral("label_Rot_Y"));
        sizePolicy1.setHeightForWidth(label_Rot_Y->sizePolicy().hasHeightForWidth());
        label_Rot_Y->setSizePolicy(sizePolicy1);
        label_Rot_Y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Rot_Y->addWidget(label_Rot_Y);

        val_Rot_Y = new QDoubleSpinBox(Transform);
        val_Rot_Y->setObjectName(QStringLiteral("val_Rot_Y"));
        sizePolicy.setHeightForWidth(val_Rot_Y->sizePolicy().hasHeightForWidth());
        val_Rot_Y->setSizePolicy(sizePolicy);
        val_Rot_Y->setFocusPolicy(Qt::ClickFocus);
        val_Rot_Y->setMinimum(-1.67772e+7);
        val_Rot_Y->setMaximum(1.67772e+7);

        Rot_Y->addWidget(val_Rot_Y);


        Rot->addLayout(Rot_Y);

        Rot_Z = new QHBoxLayout();
        Rot_Z->setSpacing(2);
        Rot_Z->setObjectName(QStringLiteral("Rot_Z"));
        Rot_Z->setSizeConstraint(QLayout::SetDefaultConstraint);
        Rot_Z->setContentsMargins(6, -1, -1, -1);
        label_Rot_Z = new QLabel(Transform);
        label_Rot_Z->setObjectName(QStringLiteral("label_Rot_Z"));
        sizePolicy1.setHeightForWidth(label_Rot_Z->sizePolicy().hasHeightForWidth());
        label_Rot_Z->setSizePolicy(sizePolicy1);
        label_Rot_Z->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Rot_Z->addWidget(label_Rot_Z);

        val_Rot_Z = new QDoubleSpinBox(Transform);
        val_Rot_Z->setObjectName(QStringLiteral("val_Rot_Z"));
        sizePolicy.setHeightForWidth(val_Rot_Z->sizePolicy().hasHeightForWidth());
        val_Rot_Z->setSizePolicy(sizePolicy);
        val_Rot_Z->setFocusPolicy(Qt::ClickFocus);
        val_Rot_Z->setMinimum(-1.67772e+7);
        val_Rot_Z->setMaximum(1.67772e+7);

        Rot_Z->addWidget(val_Rot_Z);


        Rot->addLayout(Rot_Z);


        gridLayout_2->addLayout(Rot, 1, 0, 1, 1);

        Scale = new QHBoxLayout();
        Scale->setObjectName(QStringLiteral("Scale"));
        Scale->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_Scale = new QLabel(Transform);
        label_Scale->setObjectName(QStringLiteral("label_Scale"));
        sizePolicy1.setHeightForWidth(label_Scale->sizePolicy().hasHeightForWidth());
        label_Scale->setSizePolicy(sizePolicy1);
        label_Scale->setMinimumSize(QSize(25, 0));

        Scale->addWidget(label_Scale);

        Scale_X = new QHBoxLayout();
        Scale_X->setSpacing(2);
        Scale_X->setObjectName(QStringLiteral("Scale_X"));
        Scale_X->setSizeConstraint(QLayout::SetDefaultConstraint);
        Scale_X->setContentsMargins(6, -1, -1, -1);
        label_Scale_X = new QLabel(Transform);
        label_Scale_X->setObjectName(QStringLiteral("label_Scale_X"));
        sizePolicy1.setHeightForWidth(label_Scale_X->sizePolicy().hasHeightForWidth());
        label_Scale_X->setSizePolicy(sizePolicy1);
        label_Scale_X->setLayoutDirection(Qt::LeftToRight);
        label_Scale_X->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Scale_X->addWidget(label_Scale_X);

        val_Scale_X = new QDoubleSpinBox(Transform);
        val_Scale_X->setObjectName(QStringLiteral("val_Scale_X"));
        sizePolicy.setHeightForWidth(val_Scale_X->sizePolicy().hasHeightForWidth());
        val_Scale_X->setSizePolicy(sizePolicy);
        val_Scale_X->setFocusPolicy(Qt::ClickFocus);
        val_Scale_X->setMinimum(-1.67772e+7);
        val_Scale_X->setMaximum(1.67772e+7);

        Scale_X->addWidget(val_Scale_X);


        Scale->addLayout(Scale_X);

        Scale_Y = new QHBoxLayout();
        Scale_Y->setSpacing(2);
        Scale_Y->setObjectName(QStringLiteral("Scale_Y"));
        Scale_Y->setSizeConstraint(QLayout::SetDefaultConstraint);
        Scale_Y->setContentsMargins(6, -1, -1, -1);
        label_Scale_Y = new QLabel(Transform);
        label_Scale_Y->setObjectName(QStringLiteral("label_Scale_Y"));
        sizePolicy1.setHeightForWidth(label_Scale_Y->sizePolicy().hasHeightForWidth());
        label_Scale_Y->setSizePolicy(sizePolicy1);
        label_Scale_Y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Scale_Y->addWidget(label_Scale_Y);

        val_Scale_Y = new QDoubleSpinBox(Transform);
        val_Scale_Y->setObjectName(QStringLiteral("val_Scale_Y"));
        sizePolicy.setHeightForWidth(val_Scale_Y->sizePolicy().hasHeightForWidth());
        val_Scale_Y->setSizePolicy(sizePolicy);
        val_Scale_Y->setFocusPolicy(Qt::ClickFocus);
        val_Scale_Y->setMinimum(-1.67772e+7);
        val_Scale_Y->setMaximum(1.67772e+7);

        Scale_Y->addWidget(val_Scale_Y);


        Scale->addLayout(Scale_Y);

        Scale_Z = new QHBoxLayout();
        Scale_Z->setSpacing(2);
        Scale_Z->setObjectName(QStringLiteral("Scale_Z"));
        Scale_Z->setSizeConstraint(QLayout::SetDefaultConstraint);
        Scale_Z->setContentsMargins(6, -1, -1, -1);
        label_Scale_Z = new QLabel(Transform);
        label_Scale_Z->setObjectName(QStringLiteral("label_Scale_Z"));
        sizePolicy1.setHeightForWidth(label_Scale_Z->sizePolicy().hasHeightForWidth());
        label_Scale_Z->setSizePolicy(sizePolicy1);
        label_Scale_Z->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Scale_Z->addWidget(label_Scale_Z);

        val_Scale_Z = new QDoubleSpinBox(Transform);
        val_Scale_Z->setObjectName(QStringLiteral("val_Scale_Z"));
        sizePolicy.setHeightForWidth(val_Scale_Z->sizePolicy().hasHeightForWidth());
        val_Scale_Z->setSizePolicy(sizePolicy);
        val_Scale_Z->setFocusPolicy(Qt::ClickFocus);
        val_Scale_Z->setMinimum(-1.67772e+7);
        val_Scale_Z->setMaximum(1.67772e+7);

        Scale_Z->addWidget(val_Scale_Z);


        Scale->addLayout(Scale_Z);


        gridLayout_2->addLayout(Scale, 2, 0, 1, 1);

        Pos = new QHBoxLayout();
        Pos->setObjectName(QStringLiteral("Pos"));
        Pos->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_Pos = new QLabel(Transform);
        label_Pos->setObjectName(QStringLiteral("label_Pos"));
        sizePolicy1.setHeightForWidth(label_Pos->sizePolicy().hasHeightForWidth());
        label_Pos->setSizePolicy(sizePolicy1);
        label_Pos->setMinimumSize(QSize(25, 0));

        Pos->addWidget(label_Pos);

        Pos_X = new QHBoxLayout();
        Pos_X->setSpacing(2);
        Pos_X->setObjectName(QStringLiteral("Pos_X"));
        Pos_X->setSizeConstraint(QLayout::SetDefaultConstraint);
        Pos_X->setContentsMargins(6, -1, -1, -1);
        label_Pos_X = new QLabel(Transform);
        label_Pos_X->setObjectName(QStringLiteral("label_Pos_X"));
        sizePolicy1.setHeightForWidth(label_Pos_X->sizePolicy().hasHeightForWidth());
        label_Pos_X->setSizePolicy(sizePolicy1);
        label_Pos_X->setLayoutDirection(Qt::LeftToRight);
        label_Pos_X->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Pos_X->addWidget(label_Pos_X);

        val_Pos_X = new QDoubleSpinBox(Transform);
        val_Pos_X->setObjectName(QStringLiteral("val_Pos_X"));
        sizePolicy.setHeightForWidth(val_Pos_X->sizePolicy().hasHeightForWidth());
        val_Pos_X->setSizePolicy(sizePolicy);
        val_Pos_X->setFocusPolicy(Qt::ClickFocus);
        val_Pos_X->setMinimum(-1.67772e+7);
        val_Pos_X->setMaximum(1.67772e+7);

        Pos_X->addWidget(val_Pos_X);


        Pos->addLayout(Pos_X);

        Pos_Y = new QHBoxLayout();
        Pos_Y->setSpacing(2);
        Pos_Y->setObjectName(QStringLiteral("Pos_Y"));
        Pos_Y->setSizeConstraint(QLayout::SetDefaultConstraint);
        Pos_Y->setContentsMargins(6, -1, -1, -1);
        label_Pos_Y = new QLabel(Transform);
        label_Pos_Y->setObjectName(QStringLiteral("label_Pos_Y"));
        sizePolicy1.setHeightForWidth(label_Pos_Y->sizePolicy().hasHeightForWidth());
        label_Pos_Y->setSizePolicy(sizePolicy1);
        label_Pos_Y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Pos_Y->addWidget(label_Pos_Y);

        val_Pos_Y = new QDoubleSpinBox(Transform);
        val_Pos_Y->setObjectName(QStringLiteral("val_Pos_Y"));
        sizePolicy.setHeightForWidth(val_Pos_Y->sizePolicy().hasHeightForWidth());
        val_Pos_Y->setSizePolicy(sizePolicy);
        val_Pos_Y->setFocusPolicy(Qt::ClickFocus);
        val_Pos_Y->setMinimum(-1.67772e+7);
        val_Pos_Y->setMaximum(1.67772e+7);

        Pos_Y->addWidget(val_Pos_Y);


        Pos->addLayout(Pos_Y);

        Pos_Z = new QHBoxLayout();
        Pos_Z->setSpacing(2);
        Pos_Z->setObjectName(QStringLiteral("Pos_Z"));
        Pos_Z->setSizeConstraint(QLayout::SetDefaultConstraint);
        Pos_Z->setContentsMargins(6, -1, -1, -1);
        label_Pos_Z = new QLabel(Transform);
        label_Pos_Z->setObjectName(QStringLiteral("label_Pos_Z"));
        sizePolicy1.setHeightForWidth(label_Pos_Z->sizePolicy().hasHeightForWidth());
        label_Pos_Z->setSizePolicy(sizePolicy1);
        label_Pos_Z->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Pos_Z->addWidget(label_Pos_Z);

        val_Pos_Z = new QDoubleSpinBox(Transform);
        val_Pos_Z->setObjectName(QStringLiteral("val_Pos_Z"));
        sizePolicy.setHeightForWidth(val_Pos_Z->sizePolicy().hasHeightForWidth());
        val_Pos_Z->setSizePolicy(sizePolicy);
        val_Pos_Z->setFocusPolicy(Qt::ClickFocus);
        val_Pos_Z->setMinimum(-1.67772e+7);
        val_Pos_Z->setMaximum(1.67772e+7);

        Pos_Z->addWidget(val_Pos_Z);


        Pos->addLayout(Pos_Z);


        gridLayout_2->addLayout(Pos, 0, 0, 1, 1);


        gridLayout->addWidget(Transform, 0, 0, 1, 1);


        retranslateUi(TransformWidget);

        QMetaObject::connectSlotsByName(TransformWidget);
    } // setupUi

    void retranslateUi(QWidget *TransformWidget)
    {
        TransformWidget->setWindowTitle(QApplication::translate("TransformWidget", "Form", nullptr));
        Transform->setTitle(QApplication::translate("TransformWidget", "Transform", nullptr));
        label_Rot->setText(QApplication::translate("TransformWidget", "Rot", nullptr));
        label_Rot_X->setText(QApplication::translate("TransformWidget", "X", nullptr));
        label_Rot_Y->setText(QApplication::translate("TransformWidget", "Y", nullptr));
        label_Rot_Z->setText(QApplication::translate("TransformWidget", "Z", nullptr));
        label_Scale->setText(QApplication::translate("TransformWidget", "Scale", nullptr));
        label_Scale_X->setText(QApplication::translate("TransformWidget", "X", nullptr));
        label_Scale_Y->setText(QApplication::translate("TransformWidget", "Y", nullptr));
        label_Scale_Z->setText(QApplication::translate("TransformWidget", "Z", nullptr));
        label_Pos->setText(QApplication::translate("TransformWidget", "Pos", nullptr));
        label_Pos_X->setText(QApplication::translate("TransformWidget", "X", nullptr));
        label_Pos_Y->setText(QApplication::translate("TransformWidget", "Y", nullptr));
        label_Pos_Z->setText(QApplication::translate("TransformWidget", "Z", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TransformWidget: public Ui_TransformWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFORMWIDGET_H
