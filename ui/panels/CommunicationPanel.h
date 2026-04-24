#pragma once

#include <QWidget>

class QPushButton;
class QLabel;

class CommunicationPanel : public QWidget
{
    Q_OBJECT   // ⚠️ مهم جدًا

public:
    explicit CommunicationPanel(QWidget *parent = nullptr);

signals:
    void connectClicked();

private:
    QLabel *statusLabel;
    QPushButton *connectButton;
};