#include <chrono>
#include <iostream>
#include <tuple>
#include <utility>

std::pair<int, int> divide(int dividend, int divisor) {
    return std::make_pair(dividend/divisor, dividend%divisor);
}

std::tuple<std::string, std::chrono::system_clock::time_point, int>
    stock_info(const std::string& symbol) {

        return std::make_tuple("ABC Corporation", std::chrono::system_clock::now(), 103);
    }

int main(int argc, char** argv) {
    // Unpacking Pair
	auto [fraction, remainder] = divide(16, 3);
    std::cout << "16/3 returns " << fraction << " with a remainder of " << remainder << ".\n\n";

    // Unpacking Tuple
    const auto [name, time, price] = stock_info("abc");
    std::cout << "Stock Price Of " << name << " Is " << price << ".\n\n";
	
	return 0;
}