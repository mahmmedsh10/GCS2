#include "CommunicationPanel.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

CommunicationPanel::CommunicationPanel(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    statusLabel = new QLabel("Disconnected", this);
    connect(connectButton, &QPushButton::clicked, this, [this]() {emit connectClicked(); });

    layout->addWidget(statusLabel);
    layout->addWidget(connectButton);
}