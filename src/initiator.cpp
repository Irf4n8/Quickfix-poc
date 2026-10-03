#include "Application.h"

#include <FileLog.h>
#include <FileStore.h>
#include <SessionSettings.h>
#include <SocketInitiator.h>

#include <iostream>

int main()
{
    try
    {
        FIX::SessionSettings settings("config/initiator.cfg");

        Application application;

        FIX::FileStoreFactory storeFactory(settings);

        FIX::FileLogFactory logFactory(settings);

        FIX::SocketInitiator initiator(
            application,
            storeFactory,
            settings,
            logFactory
        );

        initiator.start();

        std::cout << "FIX Initiator started." << std::endl;
        std::cout << "Connecting to 127.0.0.1:9878..." << std::endl;
        std::cout << "Press ENTER to stop." << std::endl;

        std::cin.get();

        initiator.stop();

        std::cout << "FIX Initiator stopped." << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "ERROR: "
                  << e.what()
                  << std::endl;

        return 1;
    }

    return 0;
}