#include <iostream>
#include <string>
#include <map>

int main() {
    std::map<std::string, int> examScores;
    examScores["Alice"] = 85;
    examScores["Bob"] = 90;
    examScores["Charlie"] = 78;
    std::string searchName;
    std::cout << "Enter student's name: ";
    std::cin >> searchName;
    if (examScores.find(searchName) != examScores.end()) {
        std::cout << searchName << " scored: "
                  << examScores[searchName] << std::endl;
    } else {
        std::cout << "Record not found." << std::endl;
    }
}
