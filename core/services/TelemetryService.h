#pragma once

#include <QObject>

#include "core/domain/TelemetrySnapshot.h"

class TelemetryService : public QObject
{
    Q_OBJECT
public:
    explicit TelemetryService(QObject* parent = nullptr);

    const TelemetrySnapshot& currentSnapshot() const;

public slots:
    void updateSnapshot(const TelemetrySnapshot& snapshot);

signals:
    void snapshotUpdated(const TelemetrySnapshot& snapshot);

private:
    TelemetrySnapshot snapshot_;
};
