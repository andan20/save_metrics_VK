//
// Created by Андрей Данилов on 16.06.2025.
//

#ifndef VK_SAVE_METRICS_H
#define VK_SAVE_METRICS_H

#include <vector>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>


class Metrics{
public:
    Metrics();

    ~Metrics();

    size_t GetCountTypes() const;

    size_t GetAddedMetrics() const;

    bool AddNewType(std::string name);

    bool AddNewType(std::string name, double value);

    bool AddValue(std::string& name, double value);

    double GetValue(std::string& name);

    bool IsMetric(std::string& name);

    void Write(std::string filename);

private:
    size_t count_types_metrics_;
    size_t count_added_metrics_;
    std::unordered_map<std::string, int> metric_id_;
    std::unordered_map<int, std::string> metric_name_;
    std::vector<double> metric_value_;
    int next_free_id_;
};










#endif //VK_SAVE_METRICS_H


