#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

// 定义课程类
class Course {
public:
    int id; // 课程ID
    std::string class_name; // 课程名称
    std::string instructor; // 讲师
    double duration; // 课程时长

    Course(int id, std::string class_name, std::string instructor, double duration) // 构造函数
        : id(id), class_name(class_name), instructor(instructor), duration(duration) {} // 初始化成员变量
};

// 定义动态表类
class DynamicTable {
private:
    std::vector<Course> courses; // 课程列表

public:
    // 添加课程
    void addCourse(const Course& course) {
        courses.push_back(course); // 将课程添加到课程列表中
    }

    // 删除课程
    bool removeCourse(const std::string& courseName) {
        for (auto it = courses.begin(); it != courses.end(); ++it) {
            if (it->class_name == courseName) {
                courses.erase(it);
                return true;
            }
        }
        return false;
    }

    // 获取课程信息
    Course* getCourse(int index) {
        if (index >= 0 && index < courses.size()) {
            return &courses[index];
        }
        return nullptr;
    }

    // 检索课程
    std::vector<Course*> searchCourses(const std::string& keyword) {
        std::vector<Course*> results;
        for (auto& course : courses) {
            if (course.class_name.find(keyword) != std::string::npos ||
                course.instructor.find(keyword) != std::string::npos) {
                results.push_back(&course);
            }
        }
        return results;
    }
};

// 从CSV文件读取课程信息并添加到动态表中
void loadCoursesFromCSV(DynamicTable& table, const std::string& filename) {
    std::ifstream file(filename); // 打开CSV文件
    std::string line; // 读取文件的每一行
    while (std::getline(file, line)) {
        std::istringstream lineStream(line); // 使用字符串流解析每一行
        std::vector<std::string> tokens; // 保存每个字段
        std::string token;
        bool insideQuotes = false; // 标记是否位于引号内

        for (char ch : line) {
            if (ch == '\"') {
                insideQuotes = !insideQuotes; // 切换引号内外状态
            } else if (ch == ',' && !insideQuotes) {
                tokens.push_back(token); // 添加字段到tokens
                token.clear(); // 清空token以存储下一个字段
            } else {
                token += ch; // 将字符添加到当前字段
            }
        }
        if (!token.empty()) {
            tokens.push_back(token); // 添加最后一个字段
        }

        if (tokens.size() == 4) { // 确保有4个字段
            // 创建课程对象并添加到动态表中
            Course course(std::stoi(tokens[0]), tokens[1], tokens[2], std::stod(tokens[3]));
            table.addCourse(course);
        }
    }
}


int main() {
    DynamicTable table;
    loadCoursesFromCSV(table, "courses.csv");

    // 示例：添加课程
    Course newCourse(101, "C++编程基础", "张老师", 3.5);
    table.addCourse(newCourse);

    // 示例：删除课程
    table.removeCourse("过时课程");

    // 示例：检索课程
    auto results = table.searchCourses("编程");
    for (auto* course : results) {
        std::cout << "课程名称: " << course->class_name << ", 讲师: " << course->instructor << std::endl;
    }

    return 0;
}
