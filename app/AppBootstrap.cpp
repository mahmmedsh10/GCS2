#include "app/AppBootstrap.h"

#include "core/communication/transport/SerialTransport.h"
#include "core/communication/protocol/CustomProtocol.h"
#include "core/communication/session/LinkSession.h"
#include "core/services/TelemetryService.h"
#include "core/services/CommandService.h"
#include "core/application/controllers/VehicleController.h"
#include "ui/main_window/MainWindow.h"

void AppBootstrap::initialize()
{
    transport_ = std::make_unique<SerialTransport>();
    protocol_ = std::make_unique<CustomProtocol>();
    session_ = std::make_unique<LinkSession>(transport_.get(), protocol_.get());
    telemetryService_ = std::make_unique<TelemetryService>();
    commandService_ = std::make_unique<CommandService>(session_.get());
    vehicleController_ = std::make_unique<VehicleController>(session_.get(), telemetryService_.get(), commandService_.get());
}

MainWindow* AppBootstrap::createMainWindow()
{
    if (!mainWindow_) {
        mainWindow_ = new MainWindow(vehicleController_.get(), telemetryService_.get());
    }
    return mainWindow_;
}
