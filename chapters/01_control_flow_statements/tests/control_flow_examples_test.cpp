#include <gtest/gtest.h>

#include "control_flow_statements/control_flow_examples.hpp"

TEST(ClassifyScoreTest, ReturnsExpectedGrades)
{
    EXPECT_EQ(classify_score(95), "A");
    EXPECT_EQ(classify_score(80), "B");
    EXPECT_EQ(classify_score(70), "C");
    EXPECT_EQ(classify_score(69), "F");
}

TEST(DescribeCommandTest, MapsKnownCommands)
{
    EXPECT_EQ(describe_command(1), "Start");
    EXPECT_EQ(describe_command(2), "Stop");
    EXPECT_EQ(describe_command(3), "Pause");
}

TEST(DescribeCommandTest, FallsBackToUnknownCommand)
{
    EXPECT_EQ(describe_command(99), "Unknown command");
}

TEST(SumUntilStopValueTest, StopsAtSentinel)
{
    EXPECT_EQ(sum_until_stop_value({1, 2, 3, 0, 4}, 0), 6);
}

TEST(SumUntilStopValueTest, ReturnsZeroWhenSentinelIsFirst)
{
    EXPECT_EQ(sum_until_stop_value({0, 1, 2}, 0), 0);
}

TEST(SumUntilStopValueTest, SumsAllValuesWhenSentinelIsMissing)
{
    EXPECT_EQ(sum_until_stop_value({5, 5, 5}, 0), 15);
}

TEST(SumUntilStopValueTest, ReturnsZeroForEmptyInput)
{
    EXPECT_EQ(sum_until_stop_value({}, 0), 0);
}