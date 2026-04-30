#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int pos;
  double time;
} Car;

// Sort by position descending
int compare(const void *a, const void *b) {
  Car *c1 = (Car *)a;
  Car *c2 = (Car *)b;
  return c2->pos - c1->pos;
}

int main() {
  int n, target;
  scanf("%d %d", &n, &target);

  int position[n], speed[n];

  for (int i = 0; i < n; i++)
    scanf("%d", &position[i]);
  for (int i = 0; i < n; i++)
    scanf("%d", &speed[i]);

  Car cars[n];

  // Step 1: Compute time
  for (int i = 0; i < n; i++) {
    cars[i].pos = position[i];
    cars[i].time = (double)(target - position[i]) / speed[i];
  }

  // Step 2: Sort by position descending
  qsort(cars, n, sizeof(Car), compare);

  int fleets = 0;
  double maxTime = 0;

  // Step 3: Traverse
  for (int i = 0; i < n; i++) {
    if (cars[i].time > maxTime) {
      fleets++;
      maxTime = cars[i].time;
    }
  }

  printf("%d", fleets);

  return 0;
}