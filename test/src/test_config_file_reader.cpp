#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "ConfigFileReader.h"

using ::testing::_;

class ConfigFileReaderTest : public ::testing::Test {
    protected:
		virtual void SetUp() {
		}

		virtual void TearDown() {
		}
};

TEST(ConfigFileReaderTest, getDoubleFalse) {
	ConfigFileReader testReader("./test_resources/config_file_reader/test.ini"));
	double expected = 20;
	double actual = testReader.getDouble("DEFAULT", "GREET", 20);
	EXPECT_EQ(expected, actual);
}

TEST(ConfigFileReaderTest, getDoubleTrue) {
	double expected = 768;
	double actual = testReader.getDouble("SCREEN". "SCREEN", 20);
	EXPECT_EQ(expected, actual);
}

TEST(ConfigFileReaderTest, getString)
	std::string expected = 'SDL Screen';
	std::string actual = reader.getString("SCREEN", "SCREEN_TITLE", "Title Screen");
	EXPECT_EQ(expected, actual);
}

TEST(ConfigFileReaderTest, getBoolean) {
	bool expected = false;
	bool actual = reader.getBoolean("SCREEN", "SCREEN_ENABLE", true);
	EXPECT_EQ(expected, actual);
}