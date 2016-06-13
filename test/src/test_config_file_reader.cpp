#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <string>

#include "ConfigFileReader.h"

using ::testing::_;


class ConfigFileReaderTest : public ::testing::Test {
    protected:
		virtual void SetUp() {
		}

		virtual void TearDown() {
		}
};

ConfigFileReader testReader("./test_resources/config_file_reader/test.ini");

TEST(ConfigFileReaderTest, getDoubleFalse) {
	double expected = 20;
	double actual = testReader.getDouble("DEFAULT", "GREET", 20);
	EXPECT_EQ(expected, actual);
}

TEST(ConfigFileReaderTest, getDoubleTrue) {
	double expected = 768;
	double actual = testReader.getDouble("SCREEN", "SCREEN_HEIGHT", 20);
	EXPECT_EQ(expected, actual);
}

TEST(ConfigFileReaderTest, getString) {
	std::string expected = "SDL Screen";
	std::string actual = testReader.getString("SCREEN", "SCREEN_TITLE", "Title Screen");
	EXPECT_EQ(expected, actual);
}

TEST(ConfigFileReaderTest, getBoolean) {
	bool expected = false;
	bool actual = testReader.getBoolean("SCREEN", "SCREEN_ENABLE", true);
	EXPECT_EQ(expected, actual);
}