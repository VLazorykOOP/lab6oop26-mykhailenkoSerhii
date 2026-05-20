#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Data
{
protected:
    int value;
public:
    Data() : value(0)
    {
        cout << "[+] Data" << endl;
    }

    virtual ~Data()
    {
        cout << "[-] Data" << endl;
    }

    void setValue(int v)
    {
        value = v;
    }
    int getValue() const
    {
        return value;
    }

    virtual void printInfo() const = 0;
};

class Signal : virtual public Data
{
public:
    Signal()
    {
        cout << "[+] Signal" << endl;
    }
    ~Signal() override
    {
        cout << "[-] Signal" << endl;
    }

    virtual void generateRandom()
    {
        value = rand() % 100;
        cout << "Random value: " << value << endl;
    }

    void printInfo() const override
    {
        cout << "Signal value: " << value << endl;
    }
};

class ProcessingResult : virtual public Data
{
public:
    ProcessingResult()
    {
        cout << "[+] ProcessingResult" << endl;
    }
    ~ProcessingResult() override
    {
        cout << "[-] ProcessingResult" << endl;
    }

    virtual void processData()
    {
        value *= 2;
        cout << "Processed. New value: " << value << endl;
    }

    void printInfo() const override
    {
        cout << "ProcessingResult value: " << value << endl;
    }
};


class ProcessedSignal : public Signal, public ProcessingResult
{
public:
    ProcessedSignal()
    {
        cout << "[+] ProcessedSignal" << endl;
    }
    ~ProcessedSignal() override
    {
        cout << "[-] ProcessedSignal" << endl;
    }

    void printInfo() const override
    {
        cout << "ProcessedSignal Value: " << value << endl;
    }

    void inputFromKeyboard()
    {
        cout << "Input from keyboard: ";
        cin >> value;
    }

    void loadFromFile(const string& filename)
    {
        ifstream inFile(filename);
        if (inFile.is_open())
        {
            inFile >> value;
            cout << "Read from file '" << filename << "': " << value << endl;
            inFile.close();
        } else cout << "Failed to open file!" << endl;
    }
    
    void saveToFile(const string& filename) const
    {
        ofstream outFile(filename);
        if (outFile.is_open())
        {
            outFile << value;
            outFile.close();
        }
    }
};

void task3()
{
    cout << "INITIALIZE" << endl;
    ProcessedSignal obj = ProcessedSignal();
    
    cout << "RANDOMNESS" << endl;
    obj.generateRandom();
    obj.printInfo();

    cout << "PROCESSING" << endl;
    obj.processData();
    obj.printInfo();

    cout << "KEYBOARD" << endl;
    obj.inputFromKeyboard();
    obj.printInfo();

    cout << "FILES" << endl;
    obj.saveToFile("test_data.txt");
    cout << "Written in 'test_data.txt'." << endl;
    
    obj.loadFromFile("prep_test_data.txt");
    obj.printInfo();

    cout << "DELETION" << endl;
}