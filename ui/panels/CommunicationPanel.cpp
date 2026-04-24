#include "ui/panels/CommunicationPanel.h"

#include <QComboBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>

#include "core/application/controllers/VehicleController.h"

CommunicationPanel::CommunicationPanel(VehicleController* vehicleController, QWidget* parent)
    : QWidget(parent), vehicleController_(vehicleController)
{
    portCombo_ = new QComboBox(this);
    portCombo_->addItems({"COM1", "COM2", "COM3", "COM4"});

    baudCombo_ = new QComboBox(this);
    baudCombo_->addItems({"57600", "115200", "230400"});
    baudCombo_->setCurrentText("115200");

    connectButton_ = new QPushButton("Connect", this);
    disconnectButton_ = new QPushButton("Disconnect", this);

    auto* form = new QFormLayout;
    form->addRow("Port", portCombo_);
    form->addRow("Baud", baudCombo_);

    auto* buttons = new QHBoxLayout;
    buttons->addWidget(connectButton_);
    buttons->addWidget(disconnectButton_);

    auto* root = new QVBoxLayout(this);
    root->addLayout(form);
    root->addLayout(buttons);
    root->addStretch();

    connect(connectButton_, &QPushButton::clicked, this, &CommunicationPanel::connectLink);
    connect(disconnectButton_, &QPushButton::clicked, this, &CommunicationPanel::disconnectLink);
}

void CommunicationPanel::connectLink()
{
    vehicleController_->connectVehicle(portCombo_->currentText(), baudCombo_->currentText().toInt());
}

void CommunicationPanel::disconnectLink()
{
    vehicleController_->disconnectVehicle();
}
