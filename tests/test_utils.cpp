Thinking...
Okay, I need to generate unit tests for the provided C++ file called utils.cc. The user has given me some specific instructions, so I should make sure I follow them carefully.

First, I remember that the user wants all necessary #include statements included. Looking at the input file, I see they've included "utils.h" and used several functions from utils.cc. So, I need to include those headers in my tests as well. That way, when someone compiles these tests, they can access the necessary definitions.

Next, each function in the input should have a test. The functions provided are 'badRequest', 'makeErrResp', and nothing else. Since there's only one function, I'll need to write a test for it. But wait, looking again, I notice that in the code, 'utils.h' includes more headers like std::string, drAGON::HttpResponse, etc. So maybe I should also include those? Or does the utils.h already cover them?

I think it's safer to check if there are any missing headers in the test. In this case, I don't see any, so perhaps including 'utils.h' is enough. But just to be thorough, I might add some necessary #include statements.

Now, for the function 'badRequest', which takes a function reference and two strings as parameters, returning a Json::Value. The test should cover different scenarios: when the callback is provided, when it's not, and perhaps what happens if the HTTP status code isn't set. I'll need to mock or create dummy responses and callbacks for these cases.

The 'makeErrResp' function creates a JSON value with an error string. Testing this would involve verifying that the returned JSON has the correct key "error" and the provided string. Again, testing different scenarios like when no error is provided versus when an error is provided will be important.

I should also think about how to mock the functions in the test. Since it's a C++ test, I'll use Google Test's fixtures for mocking. So each test method should include a mock for 'function' and 'string' to avoid relying on external implementations.

Each test function should return an empty result so that the tests don't fail due to side effects from other parts of the application. Then, in each test case, I'll set up the necessary inputs, call the functions with mocks, and check if the outputs are as expected.

For example, for 'makeErrResp', when makeErrResp is called without an error string, it should return a JSON with "error" empty. If an error is provided, it should have that value. I'll write separate test methods for these cases to ensure each scenario is covered.

Similarly, for 'badRequest', I'll set up scenarios where the callback function is provided and another where it's not, ensuring both success (status code 200) and failure (another status code) are tested. Also, testing when an error string is provided versus omitted will cover all possibilities.

I should structure each test method with appropriate fixtures to mock the functions. Using a results variable with an empty result container will make it easy to verify each test case's output against expectations.

Finally, I'll compile all these tests into a single file named test_<input_filename>.cpp. Since the original file name is utils.cc, the generated test file should be called utils_test.cpp, assuming that's how it's named in C++ projects.

I need to make sure each test is unique and not duplicated from the input. Each function will have its own test method, and I'll ensure all necessary headers are included so the tests compile correctly without issues.

In summary, my approach is:
1. Include all required headers in the tests.
2. Mock the functions using Google Test fixtures.
3. Write separate test methods for each C++ function to cover all scenarios.
4. Return empty results in each test method to avoid side effects from other code.
5. Verify each test case's output against expectations.
6. Compile all tests into a single file with the correct filename.

I think that covers everything the user asked for. Now, I'll structure these thoughts into actual code snippets, making sure each part is included and formatted properly.
...done thinking.

```
#include "utils.h"
#include <dragonHttpResponse.hpp>
#include <dragonHttpResponsePtr.hpp>
#include <string>

using namespace std;

void badRequest function(const dronge::function<void(dronext<HttpResponsePtr>>>& callback,
                       const string& err, int code) {
    // Implementation...
}

Json::Value makeErrResp(string err) {
    // Implementation...
}

// Unit tests for utils.cc

test UtilsTest
{
    results<mock_function>(mock_string);
    results<mock_string>(mock_empty);

    auto response = makeErrResp("error");
    expect(response["error"] == mock_string);
    expect(response["error"].empty());

    auto response = makeErrResp("error");
    expect(response["error"] == mock_string);
    expect(response["error"].equals(mock_string));

    auto response = badRequest(function, "some error", 400);
    expect(response["error"] == mock_string);

    auto response = badRequest(function, "some error");
    expect(response["error"] == mock_string);

    auto response = badRequest(
        function,
        mock_string,
        200
    );
    expect(response["error"] == mock_string);
    expect(response["error"].empty());
}
```