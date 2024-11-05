#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace ns
{
// a simple struct to model a person
struct person
{
    std::string name;
    std::string address;
    int age;
};

void to_json(json& j, const person& p)
{
    j = json{ {"name", p.name}, {"address", p.address}, {"age", p.age} };
}

void from_json(const json& j, person& p)
{
    j.at("name").get_to(p.name);
    j.at("address").get_to(p.address);
    j.at("age").get_to(p.age);
}

} // namespace ns


void test_vector() 
{
    // 创建一个 JSON 数组
    nlohmann::json j = {1, 2, 3, 4, 5};
    std::cout << j.dump(4) << std::endl;

    // 将 JSON 数组转换为 std::vector
    std::vector<int> vec = j.get<std::vector<int>>();

    // 输出 std::vector
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void test_vector2d() {
    // 创建一个嵌套的 std::vector
    std::vector<std::vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // 将嵌套的 std::vector 转换为 JSON 数组
    nlohmann::json j = vec;

    // 输出 JSON 数组 
    std::cout << j.dump(4) << std::endl;

    // 将 JSON 数组转换为嵌套的 std::vector
    std::vector<std::vector<int>> vec2 = j.get<std::vector<std::vector<int>>>();

    // 输出嵌套的 std::vector
    for (const auto& row : vec2) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    json j;
    j["name"] = "Ned Flanders";
    j["address"] = "744 Evergreen Terrace";
    j["age"] = 60;

    std::cout << j.dump() << std::endl;
    std::cout << j.dump(4) << std::endl;

    ns::person p = j.get<ns::person>();
    std::cout << p.name << " (" << p.age << ") lives in " << p.address << std::endl;

    ns::person q = {"Ned Flanders", "744 Evergreen Terrace", 55};
    json jj = q;

    std::cout << jj << std::endl;

    test_vector();
    test_vector2d();

    return 0;
}
