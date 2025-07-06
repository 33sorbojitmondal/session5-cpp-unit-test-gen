/*Thinking...
Okay, so I need to create a unit test for the provided C++ file called Jwt.cc. The user specified using Google Test and ensuring each function is covered. Let me think through how to approach this.

First, looking at the code in Jwt.cc, there are several functions defined. There's the constructor, an encode function, and a decode function. I need to test each of these to ensure they work correctly.

Starting with the constructor: it takes a secret string, session time, and issuer. Since constructors can have side effects if not properly handled, maybe a null check is necessary. So I'll add a test that checks if secret() returns nullptr when the constructor is called without parameters.

Next, the encode function creates a JWT token. It uses the system_clock for timestamp handling, which could be tested by checking if the time calculations are accurate and handle errors correctly with asserts. Also, verifying the payload claims should cover both creating and decoding properly.

The decode function verifies a JWT string into a decoded object. I'll need to test this in both directions: ensuring that when a token is passed through encode and then decoded, it returns the original token, and vice versa. This tests the encoding/decoding functionality.

I also notice there's no include statement for dragoon.h. Since the user said not to create duplicate tests, I should ensure each test includes necessary headers without duplicates. Wait, the constructor uses dragoons, so that must be included in the header file, but since it's a separate include, I don't need to worry about testing it here unless there are issues with missing includes elsewhere.

I should write each test using Google Test's auto syntax. For example, for the constructor, I'll do something like:

auto it = test::create("invalid secret");
if (it->error) throw *it;

Each test function will be self-contained and use the correct include statements. I need to make sure that all necessary namespaces are included properly in each test.

Wait, but since dragoons are involved, should they be included in the tests? The user didn't specify, so maybe it's fine as long as the includes are correct elsewhere. But perhaps it's better to assume that the header is already correctly set up for these functions.

Putting it all together, I'll structure each test with appropriate names and ensure they cover each function point without duplicating any code.
...done thinking.

I'll generate unit tests using Google Test format for the provided C++ file ` Jwt.cc`. Each test will cover the functionality of the relevant functions in the code:

```cpp*/
#include "Jwt.h"

test<JWS> test_JWS() {
    JWS jws;
    jws(); // This should return a valid JWS token
}

test<std::string secret, int sessionTime, std::string issuer>(const JWS& jws) {
    JWS jws2(jws(secret, sessionTime, issuer));
    // Test constructor with new secret
    expect(secret).clear();
    
    JWS jws3(secret, sessionTime, issuer);
    // Test constructor by moving secret reference
    expect(secret).not_clear();
}

test<std::chrono::system_clock now>(std::chrono::system_clock::now(), int sessionTime, std::stringissuer) {
    // Test the expiration time calculation
    expect((expiresAt - now()).count(chrono::seconds{sessionTime}));
}

test<std::chrono::system_clock from_time_t> (std::chrono::system_clock::from_time_t(expiresAt)) {
    // Test token creation and payload claims handling
    auto token = jwt::create();
    token.set_expires_at(expiresAt);
    
    JWS jws();
    // Verify payload claim with value 123
    expect(token.getPayload claim("JWS").get claim("value") == "123");
}

test<std::string payload> (const JWS& jws) {
    const JWS decoded = jwt::decode(jws);
    // Verify payload claim handling in decoding
    expect(decoded.getPayload claim("JWS").get claim("payload") == payload);
}
```