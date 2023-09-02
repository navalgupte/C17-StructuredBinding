#include <chrono>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

std::pair<int, int> divide(int dividend, int divisor) {
    return std::make_pair(dividend/divisor, dividend%divisor);
}

std::tuple<std::string, std::chrono::system_clock::time_point, int>
    stock_info(const std::string& symbol) {

    return std::make_tuple("ABC Corporation", std::chrono::system_clock::now(), 103);
}

struct employee {
    unsigned id;
    std::string name;
    std::string role;
    unsigned salary;

    employee(unsigned a_id, std::string a_name, std::string a_role, unsigned a_salary): 
        id(a_id), name(a_name), role(a_role), salary(a_salary) {
    }
};

int main(int argc, char** argv) {
    // Unpacking Pair
	auto [fraction, remainder] = divide(16, 3);
    std::cout << "16/3 returns " << fraction << " with a remainder of " << remainder << ".\n\n";

    // Unpacking Tuple
    const auto [name, time, price] = stock_info("abc");
    std::cout << "Stock Price Of " << name << " Is " << price << ".\n\n";

    // Create Vector Of Employees
    std::vector<employee> employees;

    employee e1(1, "John Doe", "CEO", 1000000);
    employees.push_back(e1);
    employee e2(2, "Jane Doe", "CFO", 1000000);
    employees.push_back(e2);

    // Unpacking Struct
    for(const auto &[e_id,  e_name, e_role, e_salary]: employees) {
        std::cout << "Name: " << e_name << " Role: " << e_role << " Salary: " << e_salary << std::endl;
    }
	
	return 0;
}