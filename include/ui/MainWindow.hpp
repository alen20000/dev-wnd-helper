#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QPlainTextEdit>
#include "controller\AppController.hpp"
#include <QMainWindow>
#include <QToolBar>


/**
 * @brief 主視窗，負責 UI 佈局與使用者互動事件
 */
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    /**
     * @brief 建構主視窗，並初始化所有 UI 元件與訊號/槽連接
     * @param parent 父物件，預設為 nullptr
     */
    MainWindow(QWidget* parent = nullptr);

private slots:
    /**
     * @brief 「頂層視窗檢測」按鈕點擊事件
     * @note 切換 m_isMonitoring 狀態，並啟動/停止 m_timer 輪詢，設定是100ns
     */
    void toggleCheckForegroundWindow();

    /**
     * @brief m_timer 逾時觸發，實際查詢前景視窗並輸出結果
     */
    void doCheckForegroundWindow();

    /**
     * @brief 「列出所有頂層視窗」按鈕點擊事件
     */
    void getAllWindows();

    /**
     * @brief 「清空」按鈕點擊事件，清除輸出欄位內容
     */
    void clearOutput();

private :


    QTimer* m_timer;

    //ToolBar
    QToolBar* toolBar;
    // Layout
    QHBoxLayout* mainLayout;
    QHBoxLayout* leftLayout;
    QHBoxLayout* rightLayout;
    //Btn
     
	QPushButton* m_btnGetForegroundInfo;
    QPushButton* m_showAllTopWindows;
    QPushButton* m_btnCheckWindowByTitle;

    QPushButton* tb_exitBtn;
	QPushButton* tb_clearBtn;
    // Text Box
    QLineEdit* targetInputText;
    QPlainTextEdit* outputText;

	// Controller
    bool m_isMonitoring = false;
    AppController m_controller;
};