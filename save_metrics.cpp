//
// Created by Андрей Данилов on 16.06.2025.
//

#include "save_metrics.h"


Metrics::Metrics()
: count_added_metrics_(0)
, count_types_metrics_(0)
, metric_id_()
, metric_name_()
, metric_value_(1, 0)
, next_free_id_(1)
{}

Metrics::~Metrics() = default;


size_t Metrics::GetCountTypes() const {
    return count_types_metrics_;
}


size_t Metrics::GetAddedMetrics() const {
    return count_added_metrics_;
}


bool Metrics::AddNewType(std::string name, double value) {
    if (metric_id_[name] == 0) {
        metric_id_[name] = next_free_id_++;
        metric_name_[metric_id_[name]] = name;
        metric_value_.push_back(value);
        count_types_metrics_++;
        count_added_metrics_++;
        return true;
    }
    return false;
}


bool Metrics::AddNewType(std::string name) {
    return AddNewType(name, 0);
}


bool Metrics::AddValue(std::string& name, double value) {
    int id = metric_id_[name];
    if (id != 0) {
        count_added_metrics_++;
        metric_value_[id] += value;
        return true;
    }
    return false;
}

bool Metrics::IsMetric(std::string& name) {
    return (metric_id_[name] != 0);
}


double Metrics::GetValue(std::string& name) {
    if (IsMetric(name)) {
        return metric_value_[metric_id_[name]];
    }
    return 0;
}


void Metrics::Write(std::string filename) {
    std::ofstream file(filename, std::ios::app);

    if (!file.is_open()) {
        std::cerr << "Write_error" << std::endl;
    }

    auto now = std::chrono::system_clock::now();
    auto now_time = std::chrono::system_clock::to_time_t(now);
    auto local_time = *std::localtime(&now_time);

    file << std::put_time(&local_time, "%d.%m.%Y %H:%M:%S");
    for (int i = 1; i <= count_types_metrics_; i++) {
        file << " " << '"' << metric_name_[i] << '"' << " " << metric_value_[i];
        metric_value_[i] = 0;
    }
    file << std::endl;


    file.close();
}