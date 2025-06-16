#include "save_metrics.h"

int main() {
    Metrics metrics;

    std::string name = "CPU";

    metrics.AddNewType(name, 52);
    double cur = metrics.GetValue(name);
    while (cur > 2) {
        cur /= 1.5;
        metrics.AddValue(name, cur);
    }
    metrics.Write("example_2.txt");
}