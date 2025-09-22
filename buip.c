#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product: The complex object to be built
typedef struct {
    char engine[20];
    char color[20];
    int doors;
    int gps; // 0 for false, 1 for true
} Car;

// Function to print the Car's details
void print_car(Car* car) {
    if (car) {
        printf("Car with %s engine, %s color, %d doors, and GPS: %s\n",
               car->engine, car->color, car->doors, car->gps ? "Yes" : "No");
    }
}

// Concrete Builder: Creates parts of the product and keeps state
typedef struct {
    Car* car;
} CarBuilder;

CarBuilder* createCarBuilder() {
    CarBuilder* builder = (CarBuilder*)malloc(sizeof(CarBuilder));
    if (builder) {
        builder->car = (Car*)malloc(sizeof(Car));
        if (builder->car) {
            // Initialize default values
            strcpy(builder->car->engine, "Standard");
            strcpy(builder->car->color, "White");
            builder->car->doors = 4;
            builder->car->gps = 0;
        }
    }
    return builder;
}

// Builder methods for setting attributes
CarBuilder* set_engine(CarBuilder* builder, const char* engine) {
    if (builder) {
        strcpy(builder->car->engine, engine);
    }
    return builder;
}

CarBuilder* set_color(CarBuilder* builder, const char* color) {
    if (builder) {
        strcpy(builder->car->color, color);
    }
    return builder;
}

CarBuilder* set_doors(CarBuilder* builder, int doors) {
    if (builder) {
        builder->car->doors = doors;
    }
    return builder;
}

CarBuilder* set_gps(CarBuilder* builder, int has_gps) {
    if (builder) {
        builder->car->gps = has_gps;
    }
    return builder;
}

// Final "build" method that returns the product
Car* build(CarBuilder* builder) {
    Car* built_car = builder->car;
    free(builder); // Clean up the builder itself
    return built_car;
}

// Main function to demonstrate the pattern
int main() {
    // Client code using the builder
    printf("Building a sports car with a director-like approach:\n");
    CarBuilder* sports_car_builder = createCarBuilder();

    // Use method chaining to configure the car
    CarBuilder* configured_builder = set_gps(set_doors(set_color(set_engine(sports_car_builder, "V8"), "Red"), 2), 1);
    
    // Call the build function to get the final Car object
    Car* my_sports_car = build(configured_builder);
    
    print_car(my_sports_car);
    free(my_sports_car); // Clean up the car object

    printf("\nBuilding a standard car with individual calls:\n");
    CarBuilder* standard_car_builder = createCarBuilder();
    set_engine(standard_car_builder, "V6");
    set_color(standard_car_builder, "Blue");
    set_doors(standard_car_builder, 4);
    set_gps(standard_car_builder, 0);

    Car* my_standard_car = build(standard_car_builder);
    print_car(my_standard_car);
    free(my_standard_car);

    return 0;
}
