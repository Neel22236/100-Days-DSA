#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    double time;
} Car;

// Sort cars by position descending (closest to target first)
int compareCars(const void* a, const void* b) {
    return ((Car*)b)->pos - ((Car*)a)->pos;
}

int carFleet(int target, int* position, int* speed, int n) {
    if (n == 0) return 0;

    Car* cars = (Car*)malloc(n * sizeof(Car));
    for (int i = 0; i < n; i++) {
        cars[i].pos = position[i];
        // time = (target - current_position) / speed
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    // Sort cars by position descending
    qsort(cars, n, sizeof(Car), compareCars);

    int fleets = 0;
    double currentTimeLimit = 0.0;

    for (int i = 0; i < n; i++) {
        // If this car takes more time than the fleet in front,
        // it cannot catch up and thus starts a new fleet.
        if (cars[i].time > currentTimeLimit) {
            fleets++;
            currentTimeLimit = cars[i].time;
        }
    }

    free(cars);
    return fleets;
}

int main() {
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int n = sizeof(position) / sizeof(position[0]);

    printf("Number of fleets: %d\n", carFleet(target, position, speed, n));

    return 0;
}
