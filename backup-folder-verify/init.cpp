#include "init.h"
#include <filesystem>
#include <typeinfo>+
#include <vector>

void Init() {
	std::filesystem::path source = "C:/Users/krombus/Documents/_orig";
	//const char* target = "C:\Users\krombus\Documents\_new";

	std::cout << source;

	for (const auto& entry : std::filesystem::directory_iterator(source))
	{
		std::cout << entry << "\n";
		std::cout << typeid(entry.path()).name() << "\n";

		//File file(entry.path().string());
	}
}