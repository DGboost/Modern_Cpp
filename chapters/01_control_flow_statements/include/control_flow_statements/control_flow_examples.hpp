#pragma once

#include <string>
#include <vector>

std::string classify_score(int score);
std::string describe_command(int command);
int sum_until_stop_value(const std::vector<int> &values, int stop_value);
void run_control_flow_examples();
