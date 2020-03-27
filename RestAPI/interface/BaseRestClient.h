#ifndef _BASE_REST_CLIENT_H_
#define _BASE_REST_CLIENT_H_

#include <string>
#include <vector>

namespace RestAPIClient {

class BaseClient {
  private:
    std::vector<char> requestData;
    bool requestSent = false;
    std::string response;
    std::string serverURL;

    static size_t handle_data(const char *data, size_t n, size_t l, void *userp);

  public:
    void sendRequest();
    BaseClient(const std::string fileName, const std::string serverURL);
    BaseClient(const std::vector<char> requestData, const std::string serverURL)
    : requestData(requestData), serverURL(serverURL) {};
    BaseClient(const std::vector<float> requestData, const std::string serverURL);
    std::string getReply();
};

}

#endif