#pragma once
#include <QWidget>
#include <QPushButton>

class AppController; // 前置宣告，防止互相依賴

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);

private :
    QPushButton* f_button;
    QPushButton* s_button;
    QPushButton* thi_button;
};