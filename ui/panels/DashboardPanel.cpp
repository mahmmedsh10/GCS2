#include "DashboardPanel.h"
#include <QVBoxLayout>
#include <QLabel>

DashboardPanel::DashboardPanel(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    statusLabel = new QLabel("Telemetry: Not Connected", this);

    layout->addWidget(statusLabel);
}