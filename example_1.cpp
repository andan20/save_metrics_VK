#include "save_metrics.h"

int main() {
    Metrics metrics;

    metrics.AddNewType("CPU", 58);
    metrics.Write("example_1.txt");
    metrics.AddNewType("Response", 66.67);
    metrics.Write("example_1.txt");
    std::string name = "CPU";
    metrics.AddValue(name, 11);
    metrics.Write("example_1.txt");
}