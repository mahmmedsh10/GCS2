#pragma once

#include <QMainWindow>

class VehicleController;
class TelemetryService;
class DashboardPanel;
class CommunicationPanel;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(VehicleController* vehicleController,
               TelemetryService* telemetryService,
               QWidget* parent = nullptr);

private:
    DashboardPanel* dashboardPanel_;
    CommunicationPanel* communicationPanel_;
};
