#pragma once
#include <QWidget>
#include <QPushButton>
#include <QLabel>

class AppController; // 前置宣告，防止互相依賴

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    void showMessage(const QString& text); 
private slots:
    void onFirst(); // 預設
    void onSecond();
    void onThird();
private :

    QPushButton* f_button;
    QPushButton* s_button;
    QPushButton* thi_button;
    QLabel* outputLabel;
};