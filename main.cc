#include <string>
#include <iostream>

#include <google/protobuf/util/json_util.h>

#include "http.pb.h"


using google::protobuf::util::MessageToJsonString;
using google::protobuf::util::JsonPrintOptions;


int main() {
    HttpRequest request;
    request.set_major_version(1);
    request.set_minor_version(2);
    request.set_url("/index.html");
    StringStringPair *host = request.add_headers();
    host->set_first("Host");
    host->set_second("www.example.com");
    JsonPrintOptions options;
    options.add_whitespace = true;
    options.always_print_primitive_fields = false;
    std::string buf;
    MessageToJsonString(request, &buf, options);
    std::cout<<buf<<std::endl;
    return 0;
}
