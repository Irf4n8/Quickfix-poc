#include <iostream>
#include <filesystem>
#include <chrono>

namespace fs = std::filesystem;

int main()
{
    std::string logDirectory = "../logs";

    for (const auto& entry : fs::directory_iterator(logDirectory))
    {
        if (entry.is_regular_file())
        {
            auto fileTime = fs::last_write_time(entry);
            auto now = fs::file_time_type::clock::now();

            auto age = now - fileTime;

            auto ageInDays =
                std::chrono::duration_cast<std::chrono::hours>(age).count() / 24;

            std::cout << entry.path()
                      << " | Age: "
                      << ageInDays
                      << " days";

            if (ageInDays > 7)
            {
                fs::remove(entry.path());
                std::cout << " | DELETED";
            }
            else
            {
                std::cout << " | KEPT";
            }

            std::cout << std::endl;
        }
    }

    return 0;
}