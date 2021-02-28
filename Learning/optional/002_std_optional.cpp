#include <iostream>
#include <fstream>
#include <optional>

// optional trong bai nay dung de read file
// neu read duoc file thi .has_value() = true va nguoc lai

std::optional<std::string> readFile(std::string file_name) {
	std::ifstream stream(file_name);
	if(stream) {
		std::string result;
		// doan doc file viet vao day
		stream.close();
		return result;	
	}
	return {}; // neu khong read duoc file thi tra ve rong
}

int main() {
	auto file_content = readFile("text.txt");
	if(file_content.has_value()){
		std::cout << "File read successful\n";
	} else {
		std::cout << "File read failed\n";
	}
}
