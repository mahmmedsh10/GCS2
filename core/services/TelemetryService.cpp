#include "core/services/TelemetryService.h"

TelemetryService::TelemetryService(QObject* parent)
    : QObject(parent)
{
}

const TelemetrySnapshot& TelemetryService::currentSnapshot() const
{
    return snapshot_;
}

void TelemetryService::updateSnapshot(const TelemetrySnapshot& snapshot)
{
    snapshot_ = snapshot;
    emit snapshotUpdated(snapshot_);
}
