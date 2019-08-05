#include "authservice.h"
#include <grpcpp/grpcpp.h>
int main(int argc, char *argv[]){
    std::string server_address = "0.0.0.0:50061";
    AuthService* service = new AuthService();
    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address,grpc::InsecureServerCredentials());
    builder.SetMaxMessageSize(100*1024*1024);
    builder.RegisterService(service);
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "server listening"  << std::endl;
    server->Wait();
}
