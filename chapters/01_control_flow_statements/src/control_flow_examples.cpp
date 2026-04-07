#include "control_flow_statements/control_flow_examples.hpp"

#include <iostream>

std::string classify_score(int score)
{
    if (score >= 90) {
        return "A";
    } else if (score >= 80) {
        return "B";
    } else if (score >= 70) {
        return "C";
    } else {
        return "F";
    }
}

std::string describe_command(int command)
{
    switch (command) {
    case 1:
        return "Start";
    case 2:
        return "Stop";
    case 3:
        return "Pause";
    default:
        return "Unknown command";
    }
}

int sum_until_stop_value(const std::vector<int> &values, int stop_value)
{
    int sum = 0;

    for (auto &value : values) {
        if (value == stop_value) {
            break;
        }

        sum += value;
    }

    return sum;
}

void run_control_flow_examples()
{
    const std::vector<int> values{4, 8, 15, 0, 16, 23, 42};

    std::cout << "if-else example, score 91 -> " << classify_score(91) << '\n';
    std::cout << "switch example, command 2 -> " << describe_command(2) << '\n';
    std::cout << "goto example, sum until 0 -> "
              << sum_until_stop_value(values, 0) << '\n';
}
