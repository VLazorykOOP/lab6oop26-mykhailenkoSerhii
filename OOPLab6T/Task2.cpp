#include "Task2.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Data
{
protected:
    double value;

public:
    Data() : value(0.0)
    {
        cout << "[+] Data" << endl;
    }

    virtual ~Data()
    {
        cout << "[-] Data" << endl;
    }

    void inputFromKeyboard()
    {
        cout << "Input number: ";
        cin >> value;
    }

    void generateRandom()
    {
        value = rand() % 1000;
        cout << "Random value: " << value << endl;
    }

    void loadFromFile(const string& filename)
    {
        ifstream inFile(filename);
        if (inFile.is_open())
        {
            inFile >> value;
            cout << "File read:  '" << filename << "'" << endl;
            inFile.close();
        }
        else cout << "Failed to open file" << endl;
    }

    virtual void display() const = 0;
    virtual void save(const string& filename) const = 0;
    virtual void process() = 0;
};

class Signal : public Data
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

    void display() const override
    {
        cout << "Signal display, value: " << value << endl;
    }

    void save(const string& filename) const override
    {
        ofstream outFile(filename);
        if (outFile.is_open())
        {
            outFile << "Signal: " << value;
            outFile.close();
            cout << "Signal saved to file" << endl;
        }
    }

    void process() override
    {
        value += 5.5;
        cout << "Processed" << endl;
    }
};

class ProcessingResult : public Data
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

    void display() const override
    {
        cout << "Result value: " << value << endl;
    }

    void save(const string& filename) const override
    {
        ofstream outFile(filename);
        if (outFile.is_open())
        {
            outFile << "Result: " << value;
            outFile.close();
            cout << "Result Saved to file" << endl;
        }
    }

    void process() override
    {
        value *= 2.0;
        cout << "Processed." << endl;
    }
};

class AuxiliaryData : public Data
{
public:
    AuxiliaryData()
    {
        cout << "[+] AuxiliaryData" << endl;
    }
    ~AuxiliaryData() override
    {
        cout << "[-] AuxiliaryData" << endl;
    }

    void display() const override
    {
        cout << "Aux display, value: " << value << endl;
    }

    void save(const string& filename) const override
    {
        ofstream outFile(filename);
        if (outFile.is_open())
        {
            outFile << "Aux: " << value;
            outFile.close();
            cout << "Aux saved in file" << endl;
        }
    }

    void process() override
    {
        value = 0;
        cout << "Aux processed" << endl;
    }
};

void task2()
{
    cout << "Signal + Random" << endl;
    Data* signal = new Signal();
    signal->generateRandom();
    signal->process();
    signal->display();
    signal->save("signal_output.txt");
    delete signal;

    cout << "ProcessingResult + Keyboard" << endl;
    Data* result = new ProcessingResult();
    result->inputFromKeyboard();
    result->process();
    result->display();
    result->save("result_output.txt");
    delete result;

    cout << "AuxiliaryData + File reading" << endl;
    Data* aux = new AuxiliaryData();

    ofstream tempFile("temp_input.txt");
    tempFile << 42.7;
    tempFile.close();

    aux->loadFromFile("temp_input.txt");
    aux->display();
    aux->process();
    aux->display();
    delete aux;
}