#include <iostream>
#include <memory>
#include <grpcpp/grpcpp.h>
#include "example.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using example::ExampleService;
using example::HelloRequest;
using example::HelloResponse;

class ExampleClient {
public:
    ExampleClient(std::shared_ptr<Channel> channel) : stub_(ExampleService::NewStub(channel)) {}

    std::string SayHello(const std::string& name) {
        HelloRequest request;
        request.set_name(name);

        HelloResponse response;
        ClientContext context;

        Status status = stub_->SayHello(&context, request, &response);
        if (status.ok()) {
            return response.message();
        } else {
            std::cout << "RPC failed: " << status.error_message() << std::endl;
            return "RPC failed";
        }
    }

private:
    std::unique_ptr<ExampleService::Stub> stub_;
};

int main(int argc, char** argv) {
    ExampleClient client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
    std::string user("world");
    std::string reply = client.SayHello(user);
    std::cout << "Received: " << reply << std::endl;

    return 0;
}
