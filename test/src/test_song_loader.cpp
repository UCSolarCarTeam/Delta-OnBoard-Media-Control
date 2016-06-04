#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "song_loader.h"
#include "mocks/mock_song_loader_listener.h"

using ::testing::_;

class SongLoaderTest : public ::testing::Test {
    protected:
		virtual void SetUp() {
		}

		virtual void TearDown() {
		}
};

TEST(SongLoaderTest, Somename) {
    SongLoader *song_loader = new SongLoader("./test_resources/song_loader/singlefile");
    MockSongLoaderListener *mock_song_loader_listener = new MockSongLoaderListener();

    song_loader->add_listener(mock_song_loader_listener);

    EXPECT_CALL(*mock_song_loader_listener, current_song("./test_resources/song_loader/singlefile/aAbBcC123.mp3"));

    song_loader->next_song();
}



