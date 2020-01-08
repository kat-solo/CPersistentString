#ifndef CPersistentString_H
#define CPersistentString_H
#include <iostream>
    using namespace std;

    class CPersistentString
    {
    private:
        string content;
        int length;
    public:
        CPersistentString();
        ~CPersistentString();
        string load();
        void setContent(string _content);
        string getContent();
        int calculateLength();
        void setLength(int _length);
        int getLength();
        bool isPalindrome();
        void persist();
    };
#endif