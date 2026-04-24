#include "ui/panels/DashboardPanel.h"

#include <QFormLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

#include "core/application/controllers/VehicleController.h"
#include "core/services/TelemetryService.h"
#include "core/domain/TelemetrySnapshot.h"

DashboardPanel::DashboardPanel(VehicleController* vehicleController,
                               TelemetryService* telemetryService,
                               QWidget* parent)
    : QWidget(parent),
      vehicleController_(vehicleController),
      telemetryService_(telemetryService)
{
    connectionLabel_ = new QLabel("Disconnected", this);
    altitudeLabel_ = new QLabel("0 m", this);
    airspeedLabel_ = new QLabel("0 m/s", this);
    attitudeLabel_ = new QLabel("Roll 0 | Pitch 0", this);
    altitudeInput_ = new QLineEdit(this);
    altitudeInput_->setPlaceholderText("Altitude (m)");
    sendAltitudeButton_ = new QPushButton("Send Altitude", this);

    auto* form = new QFormLayout;
    form->addRow("Link", connectionLabel_);
    form->addRow("Altitude", altitudeLabel_);
    form->addRow("Airspeed", airspeedLabel_);
    form->addRow("Attitude", attitudeLabel_);

    auto* sendLayout = new QHBoxLayout;
    sendLayout->addWidget(altitudeInput_);
    sendLayout->addWidget(sendAltitudeButton_);

    auto* root = new QVBoxLayout(this);
    root->addLayout(form);
    root->addLayout(sendLayout);
    root->addStretch();

    connect(sendAltitudeButton_, &QPushButton::clicked, this, &DashboardPanel::sendAltitudeCommand);
    connect(telemetryService_, &TelemetryService::snapshotUpdated, this, &DashboardPanel::refreshView);
    connect(vehicleController_, &VehicleController::connectionStateChanged, this, [this](bool connected) {
        connectionLabel_->setText(connected ? "Connected" : "Disconnected");
    });
}

void DashboardPanel::refreshView(const TelemetrySnapshot& snapshot)
{
    altitudeLabel_->setText(QString::number(snapshot.aircraft.altitude_m, 'f', 1) + " m");
    airspeedLabel_->setText(QString::number(snapshot.aircraft.airspeed_mps, 'f', 1) + " m/s");
    attitudeLabel_->setText(QString("Roll %1 | Pitch %2")
                                .arg(snapshot.aircraft.roll_deg, 0, 'f', 1)
                                .arg(snapshot.aircraft.pitch_deg, 0, 'f', 1));
}

void DashboardPanel::sendAltitudeCommand()
{
    vehicleController_->setAltitude(altitudeInput_->text().toDouble());
}
