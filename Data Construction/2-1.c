#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef enum {
    INT,FLOAT,DOUBLE,CHAR
} DataType;

// 定义通用元素结构体
typedef struct {
    DataType type;
    void* data;
} Element;

//定义结构体
typedef struct Queue {
    Element data[MAXSIZE];
    int rear, front, count;
} JettyQueue;

//初始化队列
void initQueue(JettyQueue* queue) {
    queue->rear = -1;
    queue->front = 0;
    queue->count = 0;
}

//判断队列是否为空
int isEmpty(JettyQueue* queue) {
    return queue->count == 0;
}

//入队
void enqueue(JettyQueue* queue, Element element) {
    if (queue->count == MAXSIZE) return;
    queue->data[(++queue->rear) % MAXSIZE] = element;
    queue->count++;
}

//出队
Element dequeue(JettyQueue* queue) {
    if(queue->count == 0) return;
    Element element = queue->data[queue->front++ % MAXSIZE];
    queue->count--;
    return element;
}

DataType getDataType(const char* typeName) {
    if (strcmp(typeName, "int") == 0) {
        return INT;
    } else if (strcmp(typeName, "float") == 0) {
        return FLOAT;
    } else if (strcmp(typeName, "char") == 0) {
        return CHAR;
    } else if (strcmp(typeName, "double") == 0) {
        return DOUBLE;
    }
}

int main() {
    char element_type_name[10];
    scanf("%s", element_type_name);

    DataType element_type = getDataType(element_type_name);

    JettyQueue queue;
    initQueue(&queue);

    int n1;
    scanf("%d", &n1);
    Element input[n1];
    if (element_type == INT) {
        for (int i = 0; i < n1; i++) {
            int* value = malloc(sizeof(int));
            scanf("%d", value);
            input[i].type = element_type;
            input[i].data = value;
            enqueue(&queue, input[i]);
        }
    } else if (element_type == DOUBLE) {
        for (int i = 0; i < n1; i++) {
            double* value = malloc(sizeof(double));
            scanf("%lf", value);
            input[i].type = element_type;
            input[i].data = value;
            enqueue(&queue, input[i]);
        }
    } else if (element_type == CHAR) {
        for (int i = 0; i < n1; i++) {
            char* value = malloc(sizeof(char));
            scanf("%s", value);
            input[i].type = element_type;
            input[i].data = value;
            enqueue(&queue, input[i]);
        }
    } else if (element_type == FLOAT) {
        for (int i = 0; i < n1; i++) {
            float* value = malloc(sizeof(float));
            scanf("%f", value);
            input[i].type = element_type;
            input[i].data = value;
            enqueue(&queue, input[i]);
        }
    }

    int out;
    scanf("%d", &out);
    for (int i = 0; i < out; i++) {
        dequeue(&queue);
    }

    int n2;
    scanf("%d", &n2);
    Element input2[n2];
    if (element_type == INT) {
        for (int i = 0; i < n2; i++) {
            int* value = malloc(sizeof(int));
            scanf("%d", value);
            input2[i].type = element_type;
            input2[i].data = value;
            enqueue(&queue, input2[i]);
        }
    } else if (element_type == DOUBLE) {
        for (int i = 0; i < n2; i++) {
            double* value = malloc(sizeof(double));
            scanf("%lf", value);
            input2[i].type = element_type;
            input2[i].data = value;
            enqueue(&queue, input2[i]);
        }
    } else if (element_type == CHAR) {
        for (int i = 0; i < n2; i++) {
            char* value = malloc(sizeof(char));
            scanf("%s", value);
            input2[i].type = element_type;
            input2[i].data = value;
            enqueue(&queue, input2[i]);
        }
    } else if (element_type == FLOAT) {
        for (int i = 0; i < n2; i++) {
            float* value = malloc(sizeof(float));
            scanf("%f", value);
            input2[i].type = element_type;
            input2[i].data = value;
            enqueue(&queue, input2[i]);
        }
    }

    for (int i = 0; i < n1 + n2 - out; i++) {
        Element element = dequeue(&queue);
        if (element.type == INT) printf("%d ", *((int*)element.data));
        else if (element.type == DOUBLE) printf("%lg ", *((double*)element.data));
        else if (element.type == CHAR) printf("%s ", (char*)element.data);
        else if (element.type == FLOAT) printf("%g ", *((float*)element.data));

        free(element.data);
    }

    return 0;
}