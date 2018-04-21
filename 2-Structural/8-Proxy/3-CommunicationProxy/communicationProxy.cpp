#include <cpprest/filestream.h>
#include <cpprest/http_client.h>
#include <string>

using namespace utility;               // Common utilities like string conversions
using namespace web;                   // Common features like URIs.
using namespace web::http;             // Common HTTP functionality
using namespace web::http::client;     // HTTP client features
using namespace concurrency::streams;  // Asynchronous streams
using namespace std;

struct Pingable {
  virtual ~Pingable() = default;
  virtual string ping(const string& message) = 0;
};

// Local Pong
struct Pong : Pingable {
  string ping(const string& message) override { return message + " pong"; }
};

struct RemotePong : Pingable {
  string ping(const string& message) override {
    http_client client(U("https://sheetsu.com/"));
    uri_builder builder(U("apis/v1.0su/f32ee7ef7478"));
    pplx::task<string> task =
        client.request(methods::GET, builder.to_string())
            .then([=](http_response response) { return response.extract_string(); });
    task.wait();
    json::value jsonObj = json::value::parse(U(string(task.get())));
    auto jsonArray = jsonObj.as_array();
    return jsonArray[0].at(U("ping")).as_string();
  }
};

void tryit(Pingable& pp) { cout << pp.ping("ping") << "\n"; }

int main() {
  cout << "Local Pong:\n";
  Pong localPong;
  for (int i = 0; i < 5; ++i) {
    tryit(localPong);
  }

  // For a remote Pong you just have to implement the same interface Pingable.
  cout << "\nRemote Pong:\n";
  RemotePong remotePong;
  for (int i = 0; i < 5; ++i) {
    tryit(remotePong);
  }

  return 0;
}
