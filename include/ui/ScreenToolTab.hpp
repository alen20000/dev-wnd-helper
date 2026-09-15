#pragma once

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class ScreenToolTab : public QWidget {
	Q_OBJECT

public:
    explicit ScreenToolTab(QWidget* parent = nullptr);
    ~ScreenToolTab() = default;
private slots:
	/* * @brief 「放大鏡」按鈕點擊事件，切換放大鏡功能
	 */
	void toggleMagnifier();

private:

	//Layout
	QVBoxLayout* layout;

	//Btn
	QPushButton* m_maginifer;

	//Display
	QWidget* m_magnifierDisplay;

};