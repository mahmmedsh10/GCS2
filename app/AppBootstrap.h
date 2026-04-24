#pragma once

#include <memory>

class MainWindow;
class ITransport;
class IProtocol;
class LinkSession;
class TelemetryService;
class CommandService;
class VehicleController;

class AppBootstrap
{
public:
    void initialize();
    MainWindow* createMainWindow();

private:
    std::unique_ptr<ITransport> transport_;
    std::unique_ptr<IProtocol> protocol_;
    std::unique_ptr<LinkSession> session_;
    std::unique_ptr<TelemetryService> telemetryService_;
    std::unique_ptr<CommandService> commandService_;
    std::unique_ptr<VehicleController> vehicleController_;
    MainWindow* mainWindow_ = nullptr;
};
