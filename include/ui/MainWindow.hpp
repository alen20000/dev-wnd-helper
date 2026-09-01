#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include "controller\AppController.hpp"


class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    void showMessage(const QString& text); 
private slots:
    void toggleCheckForegroundWindow();
    void checkWindowTimeout();
    void onSecond();
    void onThird();
private :
    QLineEdit* targetInputText;
    QPushButton* f_button;
    QPushButton* s_button;
    QPushButton* thi_button;
    QPushButton* m_exit_button;
    QLabel* outputLabel;

    QTimer* m_timer;
    bool m_isMonitoring = false;

    AppController m_controller;
};