#include "MainWindow.h"
#include <QHBoxLayout>
#include "../panels/DashboardPanel.h"
#include "../panels/CommunicationPanel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("GCS 2.0");
    resize(1200, 700);

    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    QHBoxLayout *layout = new QHBoxLayout(central);

    DashboardPanel *dashboard = new DashboardPanel(this);
    CommunicationPanel *comm = new CommunicationPanel(this);

    layout->addWidget(dashboard, 3);  // أكبر
    layout->addWidget(comm, 1);       // أصغر
}