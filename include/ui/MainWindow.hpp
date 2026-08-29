#pragma once
#include <QWidget>

class AppController; // 前置宣告，防止互相依賴

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);

private:

};