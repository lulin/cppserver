#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/http_response.h>
#include <cppcms/service.h>
#include <iostream>

class hello : public cppcms::application {
public:
  hello(cppcms::service &srv) : cppcms::application(srv) {
    std::cout << "hello created" << std::endl;
  }

  virtual void main(std::string url);
};

void hello::main(std::string url) {
  response().out() << "<html>\n"
                      "<body>\n"
                      "  <h1>hello, world!</h1>\n"
                      "  <p>"
                   << url
                   << "</p>"
                      "</body>\n"
                      "</html>\n";
}

int main(int argc, char *argv[]) {
  std::cout << "Hello World!" << std::endl;
  // create a cppcms application
  try {
    cppcms::service srv(argc, argv);
    srv.applications_pool().mount(cppcms::applications_factory<hello>());
    srv.run();
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
