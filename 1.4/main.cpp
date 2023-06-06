#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Student {
    std::string record_book;
    std::string surname;
    std::string name;
    std::string birth_date;
    std::string phone_number;
    std::string enrollment_date;

    bool operator<(const Student& rhs) const {
        return record_book < rhs.record_book;
    }
};

// Функция считывает данные из файла
std::vector<Student> readData(const std::string& filename) {
    std::ifstream in(filename);
    if (!in.is_open()) {
        std::cout << "Can't open " << filename << " for reading\n";
        return {};
    }

    std::vector<Student> data;
    Student temp;

    while (in >> temp.record_book >> temp.surname >> temp.name >> temp.birth_date >> temp.phone_number >> temp.enrollment_date) {
        data.push_back(temp);
    }

    in.close();

    return data;
}

// Функция записывает данные в файл
void writeData(const std::string& filename, const std::vector<Student>& data) {
    std::ofstream out(filename);
    if (!out.is_open()) {
        std::cout << "Can't open " << filename << " for writing\n";
        return;
    }

    for (const auto& student : data) {
        out << student.record_book << " " << student.surname << " " << student.name << " " << student.birth_date << " "
            << student.phone_number << " " << student.enrollment_date << "\n";
    }

    out.close();
}

// Функция выполняет фазу разделения
void splitPhase(const std::string& filename) {
    std::vector<Student> data = readData(filename);

    std::vector<Student> part1(data.begin(), data.begin() + data.size() / 2);
    std::vector<Student> part2(data.begin() + data.size() / 2, data.end());

    writeData("temp1.txt", part1);
    writeData("temp2.txt", part2);
}

// Функция выполняет фазу слияния
void mergePhase(const std::string& filename) {
    std::vector<Student> part1 = readData("temp1.txt");
    std::vector<Student> part2 = readData("temp2.txt");

    std::sort(part1.begin(), part1.end());
    std::sort(part2.begin(), part2.end());

    std::vector<Student> data(part1.size() + part2.size());

    std::merge(part1.begin(), part1.end(), part2.begin(), part2.end(), data.begin());

    writeData(filename, data);


}

int main() {
    splitPhase("input.txt");
    mergePhase("input.txt");
    std::ofstream("temp1.txt", std::ios::trunc).close();
    std::ofstream("temp2.txt", std::ios::trunc).close();

    return 0;
}
