cmake_minimum_required(VERSION 3.21)

project(GCS2 VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS
    Core
    Widgets
    SerialPort
)

set(PROJECT_SOURCES
    app/main.cpp
    app/AppBootstrap.h
    app/AppBootstrap.cpp

    core/domain/AircraftState.h
    core/domain/TelemetrySnapshot.h
    core/domain/FlightMode.h

    core/communication/transport/ITransport.h
    core/communication/transport/SerialTransport.h
    core/communication/transport/SerialTransport.cpp

    core/communication/protocol/IProtocol.h
    core/communication/protocol/CustomProtocol.h
    core/communication/protocol/CustomProtocol.cpp

    core/communication/session/LinkSession.h
    core/communication/session/LinkSession.cpp

    core/services/TelemetryService.h
    core/services/TelemetryService.cpp
    core/services/CommandService.h
    core/services/CommandService.cpp

    core/application/controllers/VehicleController.h
    core/application/controllers/VehicleController.cpp

    ui/main_window/MainWindow.h
    ui/main_window/MainWindow.cpp
    ui/panels/DashboardPanel.h
    ui/panels/DashboardPanel.cpp
    ui/panels/CommunicationPanel.h
    ui/panels/CommunicationPanel.cpp
)

qt_add_executable(GCS2
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

target_include_directories(GCS2 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(GCS2 PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::SerialPort
)

qt_finalize_executable(GCS2)