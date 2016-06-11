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

TEST(SongLoaderTest, single_file) {
    SongLoader *song_loader = new SongLoader("./test_resources/song_loader/singlefile");
    MockSongLoaderListener *mock_song_loader_listener = new MockSongLoaderListener();

    song_loader->add_listener(mock_song_loader_listener);

    EXPECT_CALL(*mock_song_loader_listener, current_song("./test_resources/song_loader/singlefile/aAbBcC123.mp3"));

    song_loader->next_song();
    delete mock_song_loader_listener;
}
TEST(SongLoaderTest, previous_song_wraparound){		
     SongLoader *song_loader = new SongLoader("./test_resources/song_loader/randomfiles");		
     MockSongLoaderListener *mock_song_loader_listener = new MockSongLoaderListener();		
		
    song_loader->add_listener(mock_song_loader_listener);		
		
    EXPECT_CALL(*mock_song_loader_listener, current_song(_))		
        .Times(500);		
    for(int i = 500; i > 0; i--){		
        song_loader->previous_song();
    }		
    delete mock_song_loader_listener;		
}
TEST(SongLoaderTest, next_song_wraparound){
     SongLoader *song_loader = new SongLoader("./test_resources/song_loader/randomfiles");
     MockSongLoaderListener *mock_song_loader_listener = new MockSongLoaderListener();

     song_loader->add_listener(mock_song_loader_listener);
     
     EXPECT_CALL(*mock_song_loader_listener, current_song(_))
             .Times(500);
     for(int i = 0; i < 500 ; i++){
        song_loader->next_song();
     }
    delete mock_song_loader_listener;
}
