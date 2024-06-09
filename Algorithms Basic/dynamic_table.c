#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

//构建一个动态表，用于存储课程信息
typedef struct {
    int id;
    char class_name[50]; 
    float duration;
    char instructor[50];
} JettyCourse;

//动态表结构体
typedef struct {
    JettyCourse* courses;
    int size; //表当前的大小
    int capacity; //表的容量
} DynamicTable;

//初始化动态表
void initTable(DynamicTable* table, int initialCapacity) {
    table->courses = (JettyCourse*)malloc(sizeof(JettyCourse) * initialCapacity);
    table->size = 0;
    table->capacity = initialCapacity;
}

//添加课程
void addCourse(DynamicTable* table, const JettyCourse* course) {
    if (table->size == table->capacity) {
        table->capacity *= 2; //扩容(容量翻倍)
        //重新分配内存
        table->courses = (JettyCourse*)realloc(table->courses, sizeof(JettyCourse) * table->capacity);
    }
    table->courses[table->size++] = *course;
}

void releaseTable(DynamicTable* table) {
    if(table->size < (int)(table->capacity)/2){
        //缩容(容量减半)
        table->capacity = (int)(table->capacity)/2;
        table->courses = (JettyCourse*)realloc(table->courses, sizeof(JettyCourse) * table->capacity);
    }
}

//删除课程
bool removeCourse(DynamicTable* table, const char* courseName) {
    if(table->size == 0){
        return false; //表为空
    }
    for (int i = 0; i < table->size; i++) {
        if (strcmp(table->courses[i].class_name, courseName) == 0) { 
            for (int j = i; j < table->size - 1; j++) {
                table->courses[j] = table->courses[j + 1];
            }
            table->size--;
            releaseTable(table); //删除后释放内存
            return true;
        }
    }
    return false;
}

//获取课程信息
JettyCourse* getCourse(const DynamicTable* table, int index) {
    if (index < 0 || index >= table->size) {
        return NULL; //索引越界
    }
    return &table->courses[index];
}

void parseLine(char* line, JettyCourse* course) {
    char* start = line;
    char* end = strchr(line, ',');
    *end = '\0';
    course->id = atoi(start);
    start = end + 1;
    if (*start == '\"') {
        end = strchr(start + 1, '\"');
        *end = '\0';
        strcpy(course->class_name, start + 1);
        start = strchr(end + 1, ',') + 1;
    } else {
        end = strchr(start, ',');
        *end = '\0';
        strcpy(course->class_name, start);
        start = end + 1;
    }
    end = strchr(start, ',');
    *end = '\0';
    course->duration = strtod(start, NULL);
    start = end + 1;
    strcpy(course->instructor, start);
}


//从CSV文件中加载课程信息
void loadCSV(DynamicTable* table, const char* filename) {
    FILE* file = fopen(filename, "r");
    char line[200];
    while (fgets(line, sizeof(line), file)) {
        JettyCourse course;
        parseLine(line, &course);
        QueryPerformanceCounter(&start);
        addCourse(table, &course);
    }
    fclose(file);
}

int main() {
    DynamicTable table;
    initTable(&table, 10);
    loadCSV(&table, "courses1.csv");

    DynamicTable table2;
    initTable(&table2, 10);
    table2.courses[0] = *getCourse(&table, 2);
    return 0;
}
