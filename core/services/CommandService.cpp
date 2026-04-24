#include "core/services/CommandService.h"
#include "core/communication/session/LinkSession.h"

CommandService::CommandService(LinkSession* session)
    : session_(session)
{
}

bool CommandService::sendHeartbeat()
{
    return session_->sendHeartbeat();
}

bool CommandService::setAltitude(double altitudeM)
{
    return session_->sendSetAltitude(altitudeM);
}
