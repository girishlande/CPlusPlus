// RESTUsingCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cpprest/filestream.h>
#include <cpprest/http_client.h>
#include <iostream>

using namespace utility; // Common utilities like string conversions
using namespace web; // Common features like URIs.
using namespace web::http; // Common HTTP functionality
using namespace web::http::client; // HTTP client features
using namespace concurrency::streams; // Asynchronous streams

int main()
{

    auto fileStream = std::make_shared<ostream>();

    // Open stream to output file.
    pplx::task<void> requestTask = fstream::open_ostream(U("results.html")).then([=](ostream outFile) {
                                                                               *fileStream = outFile;

                                                                               // Create http_client to send the request.
                                                                               http_client client(U("http://www.bing.com/"));

                                                                               // Build request URI and start the request.
                                                                               uri_builder builder(U("/search"));
                                                                               builder.append_query(U("q"), U("cpprestsdk github"));
                                                                               return client.request(methods::GET, builder.to_string());
                                                                           })

                                       // Handle response headers arriving.
                                       .then([=](http_response response) {
                                           printf("Received response status code:%u\n", response.status_code());

                                           // Write response body into the file.
                                           return response.body().read_to_end(fileStream->streambuf());
                                       })

                                       // Close the file stream.
                                       .then([=](size_t) {
                                           return fileStream->close();
                                       });

    // Wait for all the outstanding I/O to complete and handle any exceptions
    try {
        requestTask.wait();
    } catch (const std::exception& e) {
        printf("Error exception:%s\n", e.what());
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
