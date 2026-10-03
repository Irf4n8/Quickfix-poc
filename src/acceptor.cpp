#include "Application.h"

#include <FileLog.h>
#include <FileStore.h>
#include <SessionSettings.h>
#include <SocketAcceptor.h>

#include <iostream>

int main()
{
    try
    {
        FIX::SessionSettings settings("config/acceptor.cfg");

        Application application;

        FIX::FileStoreFactory storeFactory(settings);

        FIX::FileLogFactory logFactory(settings);

        FIX::SocketAcceptor acceptor(
            application,
            storeFactory,
            settings,
            logFactory
        );

        acceptor.start();

        std::cout << "FIX Acceptor started." << std::endl;
        std::cout << "Listening on port 9878..." << std::endl;
        std::cout << "Press ENTER to stop." << std::endl;

        std::cin.get();

        acceptor.stop();

        std::cout << "FIX Acceptor stopped." << std::endl;
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