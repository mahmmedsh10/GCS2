#pragma once

class LinkSession;

class CommandService
{
public:
    explicit CommandService(LinkSession* session);

    bool sendHeartbeat();
    bool setAltitude(double altitudeM);

private:
    LinkSession* session_;
};
