#include <httplib.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
using namespace httplib;

const string server_ip = "192.168.123.71:8080";

int main(void){
    Server svr;
    svr.Post("/post", [](const Request& req, Response& res){
        auto img = req.get_file_value("lego");
        cout << "image file length: " << img.content.length() << endl;
        cout << "image file name: " << img.filename << endl;
        ofstream file("lego1.png", ios::binary);
        file << img.content;
        res.set_content("done", "text/plain");
    });
    svr.listen("127.0.0.1", 9172);
    return 0;
}