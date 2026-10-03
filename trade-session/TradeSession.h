#ifndef TRADE_SESSION_H
#define TRADE_SESSION_H

#include <string>

class TradeSession
{
private:
    std::string startTime;
    std::string endTime;

public:
    TradeSession(
        const std::string& start,
        const std::string& end
    );

    bool isActive() const;
};

#endif