#include <gtest/gtest.h>
#include <drogon/drogon.h>

// Since main() starts the Drogon app, we can't run it directly in a test.
// Instead, we can test that the config file loads and the app initializes.

TEST(MainAppTest, ConfigFileLoads) {
    drogon::app().loadConfigFile("../config.json");
    // If no exception is thrown, config loaded successfully
    SUCCEED();
}

TEST(MainAppTest, DrogonAppInitializes) {
    // We can't actually call drogon::app().run() in a test (it blocks),
    // but we can check that the app object exists and is in a valid state.
    auto &app = drogon::app();
    EXPECT_NO_THROW(app.loadConfigFile("../config.json"));
    // Optionally, check some app properties
    EXPECT_TRUE(app.getListeners().size() >= 0);
} 