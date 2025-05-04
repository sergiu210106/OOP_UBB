#include <iostream>
#include <string>

using namespace std;

class FSComponent {
    protected:
        string m_path;
    public:
        FSComponent(string path) : m_path{path} {}

        virtual unsigned int getSize() const;
        void display() {
            cout << "File System component at " << m_path << '\n';
        }
};

class TextFile : public FSComponent {
    public:
        TextFile(string path) : FSComponent{path} {}

        unsigned int getSize() const {
            
        }
};