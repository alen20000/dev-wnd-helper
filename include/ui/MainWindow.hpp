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

private slots:
    void toggleCheckForegroundWindow();
    void checkWindowTimeout();

private :

    QLineEdit* targetInputText;
	QPushButton* m_btnGetForegroundInfo;
    QPushButton* m_exit_button;

    QTimer* m_timer;
    bool m_isMonitoring = false;

    AppController m_controller;
};