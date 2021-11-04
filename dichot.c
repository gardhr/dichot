#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double redichot(double p) {
  if (p == 0)
    return 0.5;
  if (p < 1 && p > -1)
    return p / 2;
  double s = p < 0 ? -1 : 1;
  if (s == -1)
    p = -p;
  double q = 2 * p;
  return s * (1 + q) / (2 + q);
}

double dedichot(double p) {
  if (p == 0.5)
    return 0;
  if (p > -0.5 && p < 0.5)
    return p * 2;
  double s = p < 0 ? 1 : -1;
  if (s == -1)
    p = -p;
  double q = 2 * p;
  return s * (1 + q) / (2 + q);
}

void process(double p) {
  printf("redichot(%g) = %g\n", p, redichot(p));
  printf("dedichot(redichot(%g)) = %g\n", p, dedichot(redichot(p)));
  printf("redichot(redichot(redichot(%g))) = %g\n", p,
         redichot(redichot(redichot(p))));
  printf(
      "dedichot(dedichot(dedichot(redichot(redichot(redichot(%g)))))) = %g\n\n",
      p, dedichot(dedichot(dedichot(redichot(redichot(redichot(p)))))));
}

int main(int argc, char** argv) {
  srand(time(0));
  if (argc > 1) {
    while (*(++argv))
      process(atof(*argv));
    return 0;
  }
  printf("Usage: %s [...VALUES...]\n", argv[0]);
  for (;;) {
    process((rand() & 1 ? -1 : 1) * (rand() % 1000001));
    getchar();
  }
  return 0;
}

