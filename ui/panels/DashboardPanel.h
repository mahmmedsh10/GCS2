#pragma once

#include <QWidget>

class QLabel;
class QLineEdit;
class QPushButton;
class VehicleController;
class TelemetryService;
struct TelemetrySnapshot;

class DashboardPanel : public QWidget
{
    Q_OBJECT
public:
    DashboardPanel(VehicleController* vehicleController,
                   TelemetryService* telemetryService,
                   QWidget* parent = nullptr);

private slots:
    void refreshView(const TelemetrySnapshot& snapshot);
    void sendAltitudeCommand();

private:
    VehicleController* vehicleController_;
    TelemetryService* telemetryService_;
    QLabel* connectionLabel_;
    QLabel* altitudeLabel_;
    QLabel* airspeedLabel_;
    QLabel* attitudeLabel_;
    QLineEdit* altitudeInput_;
    QPushButton* sendAltitudeButton_;
};
