#include "AppBootstrap.h"
#include "ui/main_window/MainWindow.h"

void AppBootstrap::initialize()
{
    // لاحقًا سننشئ هنا الخدمات والـ controllers
}

MainWindow* AppBootstrap::createMainWindow()
{
    if (!mainWindow_) {
        mainWindow_ = new MainWindow();
    }

    return mainWindow_;
}