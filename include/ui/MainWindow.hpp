#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

class AppController; // 前置宣告
class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    void showMessage(const QString& text); 
private slots:
    void checkForegroundWindow(); // 預設
    void onSecond();
    void onThird();
private :
    QLineEdit* targetInputText;
    QPushButton* f_button;
    QPushButton* s_button;
    QPushButton* thi_button;
    QPushButton* m_exit_button;
    QLabel* outputLabel;



};