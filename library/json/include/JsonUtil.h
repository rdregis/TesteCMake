////////////////////////////////////////////////////////////////////////////
//   Copyright 2020 Teradici Corporation
//   All Rights Reserved
//   No portions of this material may be reproduced in any form without the
//   written permission of Teradici Corporation.  All information contained
//   in this document is Teradici Corporation company private, proprietary,
//   and trade secret.
////////////////////////////////////////////////////////////////////////////

#pragma once

#include <json/json.h>

#include <istream>
#include <vector>

namespace jsonUtil {

class JsonUtil {
 public:
  using SerializedString = std::string;


  static bool parse(istream &stream, const Json::Value &value, const std::string &errors)
  {
    return Json::parseFromStream(builder, stream, &value, &errors);

  }


  static bool parse(istream &stream, const Json::Value &value) 
  {
    std::string errors;
    return parse(stream, value, errors);
  }

  static bool parse(const std::string &data, Json::Value &value, std::string &errors) 
  {
    return parseFromContainer(data, value, errors);
  }

  static bool parse(const std::string &data, Json::Value &value) 
  {
    return parseFromContainer(data, value);
  }

  static bool parse(const vector<char> &data, Json::Value &value, std::string &errors) 
  {
    return parseFromContainer(data, value, errors);
  }

  static bool parse(const vector<char> &data, Json::Value &value) 
  {
    return parseFromContainer(data, value);
  }

  Json::Value convertToJsonValue(const SerializedString &serializedStr) {
    std::string errors;
    Json::Value jsonVal;
    if (!parse(serializedStr, jsonVal, errors)) {
      throw runtime_error("Failure in parsing json typed std::string: " + errors);
    }

    return jsonVal;
  }

  SerializedString convertToTypedString(const Json::Value &jsonValue) {
    Json::StreamWriterBuilder builder{};
    builder["indentation"] = "   ";
    return Json::writeString(builder, jsonValue);
  }
  private:

  template <typename T>
  bool parseFromContainer(const T &data, Json::Value &value, std::string &errors) 
  {
    Json::CharReaderBuilder builder;
    auto reader = unique_ptr<Json::CharReader>(builder.newCharReader());
    return reader->parse(data.data(), data.data() + data.size(), &value,
                         &errors);
  }

  template <typename T>
  bool parseFromContainer(const T &data, Json::Value &value) {
    std::string errors;
    return parseFromContainer(data, value, errors);
  }

  /*
  static bool parse(std::istream &stream, Json::Value &value,
                    std::string &errors);
  static bool parse(std::istream &stream, Json::Value &value);
  static bool parse(const std::string &data, Json::Value &value,
                    std::string &errors);
  static bool parse(const std::string &data, Json::Value &value);
  static bool parse(const std::vector<char> &data, Json::Value &value,
                    std::string &errors);
  static bool parse(const std::vector<char> &data, Json::Value &value);
  static Json::Value convertToJsonValue(const std::string &serializedStr);
  static std::string convertToTypedString(const Json::Value &jsonValue);
  static bool isJson(const std::string &str);
*/
  bool parse(std::istream &stream, Json::Value &value, std::string &errors);
  bool parse(std::istream &stream, Json::Value &value);
  bool parse(const std::string &data, Json::Value &value, std::string &errors);
  bool parse(const std::string &data, Json::Value &value);
  bool parse(const std::vector<char> &data, Json::Value &value,
             std::string &errors);
  bool parse(const std::vector<char> &data, Json::Value &value);

  using SerializedString = std::string;

  /**
   * @brief helper functions to convert between Json::Value and serialized
   * string which uses markers to retain the type information e.g.
   *   Json::Value("hello") and serialized string "\"hello\"\\n"
   *   Json::Value(true) and serialized string "true\\n"
   *   Json::Value(1234) and serialized string "1234\\n"
   */
  Json::Value convertToJsonValue(const SerializedString &serializedStr);
  SerializedString convertToTypedString(const Json::Value &jsonValue);

  /**
   * Determine if the given text is a JSON string.  Blanks strings are not JSON.
   * @returns @p true only if the string can be parsed as valid JSON.
   */
  bool isJson(const SerializedString &str);
};

} // namespace jsonUtil
