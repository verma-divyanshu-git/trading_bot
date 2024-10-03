#pragma once
#include <cstdlib>
#include <string>

class EnvConfig
{
public:
    static double getEnvDouble(const std::string &envVarName, double defaultValue);
    static int getEnvInt(const std::string &envVarName, int defaultValue);
    static std::string getEnvString(const std::string &envVarName, const std::string &defaultValue);
};
