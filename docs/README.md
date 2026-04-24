# GCS 2.0 Template

This is a starter template for a modular Qt/CMake ground control station.

## Included
- Qt Widgets main window
- Serial transport abstraction
- Custom protocol stub
- Link session
- Telemetry service
- Command service
- Vehicle controller
- Dashboard panel
- Communication panel

## Build
```bash
cmake -S . -B build
cmake --build build
```

## Next steps
- Add map panel
- Add mission controller and repository
- Add logging and replay
- Replace protocol stub with full aircraft protocol parser
