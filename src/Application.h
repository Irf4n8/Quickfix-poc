#ifndef APPLICATION_H
#define APPLICATION_H

#include <Application.h>
#include <MessageCracker.h>
#include <SessionID.h>
#include <Message.h>

class Application : public FIX::Application,
                    public FIX::MessageCracker
{
public:

    void onCreate(const FIX::SessionID& sessionID) override;

    void onLogon(const FIX::SessionID& sessionID) override;

    void onLogout(const FIX::SessionID& sessionID) override;

    void toAdmin(
        FIX::Message& message,
        const FIX::SessionID& sessionID
    ) override;

    void fromAdmin(
        const FIX::Message& message,
        const FIX::SessionID& sessionID
    ) override;

    void toApp(
        FIX::Message& message,
        const FIX::SessionID& sessionID
    ) override;

    void fromApp(
        const FIX::Message& message,
        const FIX::SessionID& sessionID
    ) override;
};

#endif