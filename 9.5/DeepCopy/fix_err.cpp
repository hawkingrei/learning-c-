#include <iostream>
using namespace std;

class MyString
{
  private:
    char *Buffer;

  public:
    //Constructor
    MyString(const char *InitialInput)
    {
        if (InitialInput != NULL)
        {
            Buffer = new char[strlen(InitialInput) + 1];
            strcpy(Buffer, InitialInput);
        }
        else
        {
            Buffer = NULL;
        }
    }
    //copy constructor
    MyString(const MyString &CopySource)
    {
        cout << "Copy constructor: copying from MyString" << endl;
        if (CopySource.Buffer != NULL)
        {
            Buffer = new char[strlen(CopySource.Buffer) + 1];
            strcpy(Buffer, CopySource.Buffer);
            cout << "Buffer points to: 0x" << hex;
            cout << (unsigned int *)Buffer << endl;
        }
    }
    //Destructor
    ~MyString()
    {
        cout << "Invoking destructor, clearing up" << endl;
        if (Buffer != NULL)
        {
            delete[] Buffer;
        }
    }

    int GetLength()
    {
        return strlen(Buffer);
    }

    const char *GetString()
    {
        return Buffer;
    }
};

void UseMyString(MyString Input)
{
    cout << "String buffer in MyString is " << Input.GetLength();
    cout << " character long" << endl;
    cout << "Buffer contains: " << Input.GetString() << endl;
    return;
}

int main()
{
    MyString SayHello("Hello from String Class");
    UseMyString(SayHello);
    return 0;
}
