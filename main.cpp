#include <iostream>
#include <nlohmann/json.hpp>


int main() {
    // 使用nlohmann json库
    nlohmann::json j = R"({"key": "value"})"_json;
    std::cout << j << std::endl;
    return 0;
}


