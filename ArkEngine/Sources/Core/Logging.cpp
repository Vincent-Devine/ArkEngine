#include "ArkEngine/Core/Logging.hpp"

#include <iostream>
#include <Windows.h>
#include <debugapi.h>
#include <format>
#include <chrono>

namespace ArkEngine::Core
{
    void DebugLog(const std::string& p_filename, const unsigned int p_line, const std::string& p_functionName, const std::string p_log, const LOG_LEVEL& p_logLevel)
    {
        std::string time = std::format("{:%T}", floor<std::chrono::seconds>(std::chrono::system_clock::now()));
        std::string message = "[" + time + "]" + p_filename + '(' + std::to_string(p_line) + "):" + p_functionName + ": " + p_log;
        OutputDebugStringA(message.c_str());
        Logging::Print(message, p_logLevel);
    }

    std::ofstream Logging::logFile;

    void Logging::OpenFile(const std::filesystem::path& p_filename)
    {
        if (logFile && logFile.is_open())
        {
            LOG("Log file already open", LOG_LEVEL::Warning);
            return;
        }

        logFile.open(p_filename, std::ios::out);
        if (!logFile)
        {
            LOG("Fail to open log file " + p_filename.string(), LOG_LEVEL::Warning);
            return;
        }
        else
        {
            LOG("Open log file " + p_filename.string(), LOG_LEVEL::Validation);
        }
    }

    void Logging::CloseFile()
    {
        logFile.close();
        LOG("Close log file", LOG_LEVEL::Info);
    }

    void Logging::Print(const std::string& p_log, const LOG_LEVEL& p_level)
    {
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        std::string log;

        switch (p_level)
        {
        case LOG_LEVEL::Info:
        {
            SetConsoleTextAttribute(handle, 11); // texte in blue
            std::cout << "[Info]       ";
            SetConsoleTextAttribute(handle, 15); // texte in white (default)
            std::cout << p_log << std::endl;
            log = "[Info] " + p_log + '\n';
            break;
        }

        case LOG_LEVEL::Validation:
        {
            SetConsoleTextAttribute(handle, 10); // texte in green
            std::cout << "[Validation] ";
            SetConsoleTextAttribute(handle, 15); // texte in white (default)
            std::cout << p_log << std::endl;
            log = "[Validation] " + p_log + '\n';
            break;
        }

        case LOG_LEVEL::Warning:
            SetConsoleTextAttribute(handle, 14); // texte in yellow
            std::cout << "[Warning]    ";
            SetConsoleTextAttribute(handle, 15); // texte in white (default)
            std::cout << p_log << std::endl;
            log = "[Warning] " + p_log + '\n';
            break;

        case LOG_LEVEL::Critical:
            SetConsoleTextAttribute(handle, 207); // background in red, texte in white
            std::cout << "[Critical]";
            SetConsoleTextAttribute(handle, 15); // texte in white (default)
            std::cout << "   " + p_log << std::endl;
            log = "[Critical] " + p_log + '\n';
            break;

        default:
            std::cout << p_log << std::endl;;
            log = p_log + '\n';
            break;
        }

        if (logFile.is_open())
        {
            logFile << log;
        }
    }
} // namespace