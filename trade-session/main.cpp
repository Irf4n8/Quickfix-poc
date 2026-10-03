#include <iostream>
#include "TradeSession.h"

int main()
{
    TradeSession session("09:15", "15:30");

    if (session.isActive())
    {
        std::cout << "Trade Session: ACTIVE" << std::endl;
    }
    else
    {
        std::cout << "Trade Session: INACTIVE" << std::endl;
    }

    return 0;
}