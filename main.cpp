#include <iostream>
#include <variant>
#include <vector>

std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

void print_variant(std::variant<int, std::string, std::vector<int>> &a) {
    if (std::holds_alternative<int>(a)) std::cout << std::get<int>(a);
    if (std::holds_alternative<std::string>(a)) std::cout << std::get<std::string>(a);
    if (std::holds_alternative<std::vector<int>>(a)) std::cout << std::for_each(std::get<std::vector<int>>(a).begin(), std::get<std::vector<int>>(a).end(), [](int &n) {std::cout << n << " ";});
    std::cout << std::endl;
}

int main() {
    auto var = get_variant();
    print_variant(var);
    
    return 0;
}