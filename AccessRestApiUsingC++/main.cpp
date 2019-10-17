// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <iterator>

using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams


int main(int argc, char* argv[])
{
    web::http::client::http_client client(U("http://localhost:49421/api/"));
    pplx::task<web::http::http_response> resp = client.request(web::http::methods::GET,
        U("/students"));

    resp.then([=](pplx::task<web::http::http_response> task)
        {
            web::http::http_response  response = task.get();
            if (response.status_code() == status_codes::OK)
            {
                auto body = response.extract_string().get();
                std::wcout << body;
            }
        });
    while (1);
    return 0;
}