#include "ui/main_window/MainWindow.h"

#include <QDockWidget>
#include <QTabWidget>

#include "ui/panels/DashboardPanel.h"
#include "ui/panels/CommunicationPanel.h"

MainWindow::MainWindow(VehicleController* vehicleController,
                       TelemetryService* telemetryService,
                       QWidget* parent)
    : QMainWindow(parent)
{
    setWindowTitle("GCS 2.0");
    resize(1200, 720);

    dashboardPanel_ = new DashboardPanel(vehicleController, telemetryService, this);
    setCentralWidget(dashboardPanel_);

    communicationPanel_ = new CommunicationPanel(vehicleController, this);
    auto* commDock = new QDockWidget("Communication", this);
    commDock->setWidget(communicationPanel_);
    addDockWidget(Qt::LeftDockWidgetArea, commDock);
}
