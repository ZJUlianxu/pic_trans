#include "httplib.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
using namespace httplib;

int main(void){
    Client cli("127.0.0.1", 9172);
    MultipartFormDataItems items;
    MultipartFormData item;
    item.filename = "lego.png";
    ifstream in(item.filename, ios::binary);
    if(in){
        ostringstream contents;
        contents << in.rdbuf();
        in.close();
        item.content = contents.str();
    }
    item.name = "lego";
    item.content_type = "image/png";
    items.push_back(item);
    if(auto res = cli.Post("/post", items)){
        if(res->status == 200){
            cout << res->body << endl;
        }
        else{
            cout << "connect failed" << endl;
        }
    };
}
