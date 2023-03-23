#include <iostream>
#include <iomanip>
// Compile with something like (Makefile excerpt):
// g++ -g -O0 -Wall -I/usr/local/xerces/include/ $(^) -L/usr/local/xerces/lib/ -lxerces-c

#include <fstream>
#include <sstream>

#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include "hello.hxx"

using namespace std;
using namespace xercesc_3_2;

int main(int argc, char* args[])
{
    try {
        XMLPlatformUtils::Initialize();
    } catch (const XMLException& toCatch) {
        char* message = XMLString::transcode(toCatch.getMessage());
        cout << "Error during initialization! :\n" << message << "\n";
        XMLString::release(&message);
        return 1;
    }
    cout<<"test\n";
    XercesDOMParser* parser = new XercesDOMParser();
    parser->setValidationScheme(XercesDOMParser::Val_Always);
    parser->setDoNamespaces(true); // optional

    ErrorHandler* errHandler = (ErrorHandler*) new HandlerBase();
    parser->setErrorHandler(errHandler);

    const char * xmlFile = "/mnt/c/Users/Josean/CLionProjects/hello1/hello.xml";
    cout<<"test2\n";

    try {
        parser->parse(xmlFile);

        hello_t hello1= hello_t(*parser->getDocument()->getDocumentElement());
        cout<<"greeting: "<< hello1.greeting() << endl;
        for (string name:  hello1.name()){
            cout<<"name: "<< name << endl;
        }

    } catch (const XMLException& toCatch) {
        char* message = XMLString::transcode(toCatch.getMessage());
        cout << "Exception message is: \n" << message << "\n";
        XMLString::release(&message);
        return -1;
    } catch (const DOMException& toCatch) {
        char* message = XMLString::transcode(toCatch.msg);
        cout << "Exception message is: \n" << message << "\n";
        XMLString::release(&message);
        return -1;
    } catch (...) {
        cout << "Unexpected Exception \n";
        return -1;
    }
    cout<<"test3\n";

    cout << xmlFile << ": parse OK" << endl;

    delete parser;
    delete errHandler;
    return 0;
}