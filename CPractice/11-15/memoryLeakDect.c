#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom data structure
typedef struct {
    int id;
    char* name;
} Data;

// Function to create a Data object
Data* create_data(int id, const char* name) {
    Data* data = (Data*)malloc(sizeof(Data));
    if (!data) {
        printf("Memory allocation failed for Data.\n");
        return NULL;
    }
    data->id = id;
    // Allocate memory for the name
    data->name = (char*)malloc(strlen(name) + 1);
    if (!data->name) {
        printf("Memory allocation failed for name.\n");
        free(data);
        return NULL;
    }
    strcpy(data->name, name);
    return data;
}

// Function to display the Data object
void display_data(Data* data) {
    if (data) {
        printf("ID: %d, Name: %s\n", data->id, data->name);
    }
}

// Function to simulate memory leaks
void simulate_memory_leak() {
    // Allocate memory for multiple Data objects
    Data* data1 = create_data(1, "Alice");
    Data* data2 = create_data(2, "Bob");
    Data* data3 = create_data(3, "Charlie");

    // Forget to free memory for data1
    display_data(data1);
    free(data1->name);
    free(data1);
    data1->name = NULL;
    data1 = NULL;

    // Free data2, but forget to free its name
    free(data2->name);
    free(data2);
    data2->name = NULL;
    data2 = NULL;

    // Forget to free both data3 and its name
    display_data(data3);
    free(data3->name);
    free(data3);
    data3->name = NULL;
    data3 = NULL;
}

// Main function
int main() {
    simulate_memory_leak();

    printf("Program completed. Use a memory profiler to detect leaks.\n");
    return 0;
}
