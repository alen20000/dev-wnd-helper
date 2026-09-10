#pragma once

#include <QWidget>

class ScreenToolTab : public QWidget {
    Q_OBJECT
public:
    explicit ScreenToolTab(QWidget* parent = nullptr);
    ~ScreenToolTab() = default;
};