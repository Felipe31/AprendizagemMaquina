#include "perceptron.h"


int main() {
    char file[] = "../test_weka.in";
    int size_database=435, quantity_atributes=17;
    int size_class_values = 2;

    struct database *data = mount_database(file, size_database, quantity_atributes);
    assert(data);
    data->class_values = (double *)calloc(size_class_values, sizeof(double));
    assert(data->class_values);
    data->size_class_values = size_class_values;
    data->class_values[0] = 1.0;
    data->class_values[1] = 0.0;

    perceptron(data, 50);

    free_database(data);
}
