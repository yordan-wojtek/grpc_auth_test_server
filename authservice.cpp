#include "authservice.h"

AuthService::AuthService() : LoginService::Service(){

}

AuthService::~AuthService()
{

}



grpc::Status AuthService::Login(::grpc::ServerContext* context, const UserDetails* request, ::Token* response){
    std::string email = request->email();
    std::string password = request->password();
    auto key = "e3ab995b228c456b386d1e35cc3a6308";
    jwt::jwt_object obj{jwt::params::algorithm("HS256"), jwt::params::payload({{"email", email}}), jwt::params::secret(key)};
    obj.add_claim("exp", std::chrono::system_clock::now() + std::chrono::seconds{60})
       .add_claim("id", "a-b-c-d-e-f-1-2-3")
       .add_claim("licenceKey", "a-b-c-d-e-f-1-2-3");
    auto enc_str = obj.signature();
    response->set_token(enc_str);
    return  grpc::Status::OK;

//    return grpc::Status(grpc::StatusCode::PERMISSION_DENIED,"bad credentials");
}
