#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include "controller\AppController.hpp"
#include <QMainWindow>
#include <QToolBar>
class MainWindow : public QMainWindow {
    Q_OBJECT

public:

    MainWindow(QWidget* parent = nullptr);

private slots:
    void toggleCheckForegroundWindow();
    void checkWindowTimeout();

private :
    bool m_isMonitoring = false;
    QLineEdit* targetInputText;
    QTimer* m_timer;

    //ToolBar
    QToolBar* toolBar;
    // Layout
    QHBoxLayout* mainLayout;
    QHBoxLayout* leftLayout;
    QHBoxLayout* rightLayout;
    //Btn
     
	QPushButton* m_btnGetForegroundInfo;
    QPushButton* tb_exitBtn;


    AppController m_controller;
};