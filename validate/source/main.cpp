#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <json/json.h>

int main(int argc, char *argv[]) {

  std::string programName = argv[0];
  std::cout << "Program: " << programName << " is running" << std::endl;

  const std::string stdJson = "{\"name\":\"John\", \"age\":30, \"car\":null}";
  Json::Reader reader;
  Json::Value root;

  try {
    bool parse = reader.parse(stdJson, root);
    std::cout << "Parse: " << parse << std::endl;
    std::cout << "Name: " << root["name"].asString() << std::endl;
    std::cout << "Age: " << root["age"].asInt() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Error: " << std::endl;
  }
  return 0;
}