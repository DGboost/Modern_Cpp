#include "control_flow_statements/control_flow_examples.hpp"

#include <iostream>

std::string classifyScore(int score)
{
    if (score >= 90)
    {
        return "A";
    }
    else if (score >= 80)
    {
        return "B";
    }
    else if (score >= 70)
    {
        return "C";
    }
    else
    {
        return "F";
    }
}

std::string classifyScore2(int command)
{
    switch (command)
    {
    case 1:
        return "A";
    case 2:
        return "B";
    case 3:
        return "C";
    case 4:
        return "F";
    default:
        return "Unknown command";
    }
}

int sumScoreUntilStopValue(const std::vector<int> &values, int stop_value)
{
    int sum_score = 0;
    std::size_t idx = 0;
    std::size_t vector_size = values.size();

loop:
    if (idx >= vector_size)
    {
        return done:
    }
    else if (sum_score == stop_value)
    {
        return done;
    }

    sum_score += values[idx];
    ++idx;
    goto loop;

done:
    return sum_score;
}

int sumAllScoresUsingFor(const std::vector<int> &values)
{
    int sum_score = 0;

    for (int i = 0; i < values.size(); ++i)
    {
        sum_score += values[i];
    }

    // for (const auto & value : values)
    // {
    //     sum_score += value;
    // }

    return sum_score;
}

int sumAllScoresUsingWhile(const std::vector<int> &values)
{
    int sum_score = 0;
    std::size_t idx = 0;
    std::size_t vector_size = values.size();

    while (idx < vector_size)
    {
        sum_score += values[idx];
        ++idx;
    }

    return sum_score;
}

void run_control_flow_examples()
{
    const std::vector<int> values{4, 8, 15, 0, 16, 23, 42};

    std::cout << "if-else example, score 91 -> " << classifyScore(91) << '\n';
    std::cout << "switch example, command 2 -> " << classifyScore2(2) << '\n';
    std::cout << "for example, sum all scores -> "
              << sumAllScoresUsingFor(values) << '\n';
    std::cout << "while example, sum all scores -> "
              << sumAllScoresUsingWhile(values) << '\n';
}
