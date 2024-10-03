#include "env_config.h"
#include <iostream>

double EnvConfig::getEnvDouble(const std::string &envVarName, double defaultValue)
{
    const char *value = std::getenv(envVarName.c_str());
    if (value)
    {
        try
        {
            return std::stod(value);
        }
        catch (...)
        {
            std::cerr << "Invalid double value for environment variable: " << envVarName << "\n";
        }
    }
    return defaultValue;
}

int EnvConfig::getEnvInt(const std::string &envVarName, int defaultValue)
{
    const char *value = std::getenv(envVarName.c_str());
    if (value)
    {
        try
        {
            return std::stoi(value);
        }
        catch (...)
        {
            std::cerr << "Invalid integer value for environment variable: " << envVarName << "\n";
        }
    }
    return defaultValue;
}

std::string EnvConfig::getEnvString(const std::string &envVarName, const std::string &defaultValue)
{
    const char *value = std::getenv(envVarName.c_str());
    return value ? std::string(value) : defaultValue;
}