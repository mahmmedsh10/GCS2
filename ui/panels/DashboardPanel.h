#pragma once

#include <QWidget>

class QLabel;

class DashboardPanel : public QWidget
{
    Q_OBJECT

public:
    explicit DashboardPanel(QWidget *parent = nullptr);

private:
    QLabel *statusLabel;
};