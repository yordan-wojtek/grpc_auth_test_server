#ifndef AUTHSERVICE_H
#define AUTHSERVICE_H

#include <ctime>
#include <chrono>
#include "jwt/jwt.hpp"
#include "login.grpc.pb.h"
#include "login.pb.h"


class AuthService : public LoginService::Service
{
public:
    AuthService();
    grpc::Status Login(grpc::ServerContext* context, const UserDetails* request, Token* response) override;
    ~AuthService() override;
};

#endif // AUTHSERVICE_H
