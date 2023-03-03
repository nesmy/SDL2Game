#include "Shader.h"

Shader::Shader(const char *vertexPath, const char *fragmentPath)
{
    // 1. retrieve the vertex/fragment source code from filePath
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    //ensure ifstream objects can throw exceptions:
}

void Shader::use()
{
}

void Shader::setBool(const std::string &name, bool value) const
{
}

void Shader::setInt(const std::string &name, int value) const
{
}

void Shader::setFloat(const std::string &name, float value) const
{
}
