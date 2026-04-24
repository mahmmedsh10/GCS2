#pragma once

#include <QWidget>

class QComboBox;
class QPushButton;
class VehicleController;

class CommunicationPanel : public QWidget
{
    Q_OBJECT
public:
    explicit CommunicationPanel(VehicleController* vehicleController, QWidget* parent = nullptr);

private slots:
    void connectLink();
    void disconnectLink();

private:
    VehicleController* vehicleController_;
    QComboBox* portCombo_;
    QComboBox* baudCombo_;
    QPushButton* connectButton_;
    QPushButton* disconnectButton_;
};
