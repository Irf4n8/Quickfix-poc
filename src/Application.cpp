#include "Application.h"

#include <iostream>

void Application::onCreate(const FIX::SessionID& sessionID)
{
    std::cout << "[onCreate] "
              << sessionID.toString()
              << std::endl;
}

void Application::onLogon(const FIX::SessionID& sessionID)
{
    std::cout << "[onLogon] "
              << sessionID.toString()
              << std::endl;
}

void Application::onLogout(const FIX::SessionID& sessionID)
{
    std::cout << "[onLogout] "
              << sessionID.toString()
              << std::endl;
}

void Application::toAdmin(
    FIX::Message& message,
    const FIX::SessionID& sessionID)
{
    std::cout << "[toAdmin] "
              << message.toString()
              << std::endl;
}

void Application::fromAdmin(
    const FIX::Message& message,
    const FIX::SessionID& sessionID)
{
    std::cout << "[fromAdmin] "
              << message.toString()
              << std::endl;
}

void Application::toApp(
    FIX::Message& message,
    const FIX::SessionID& sessionID)
{
    std::cout << "[toApp] "
              << message.toString()
              << std::endl;
}

void Application::fromApp(
    const FIX::Message& message,
    const FIX::SessionID& sessionID)
{
    std::cout << "[fromApp] "
              << message.toString()
              << std::endl;
}