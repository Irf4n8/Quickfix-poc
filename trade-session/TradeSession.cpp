#include "TradeSession.h"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

TradeSession::TradeSession(
    const std::string& start,
    const std::string& end
)
{
    startTime = start;
    endTime = end;
}

bool TradeSession::isActive() const
{
    auto now = std::chrono::system_clock::now();

    std::time_t currentTime =
        std::chrono::system_clock::to_time_t(now);

    std::tm localTime{};

    localtime_s(&localTime, &currentTime);

    std::stringstream currentTimeStream;

    currentTimeStream
        << std::setfill('0')
        << std::setw(2) << localTime.tm_hour
        << ":"
        << std::setw(2) << localTime.tm_min;

    std::string currentTimeString =
        currentTimeStream.str();

    return currentTimeString >= startTime &&
           currentTimeString <= endTime;
}