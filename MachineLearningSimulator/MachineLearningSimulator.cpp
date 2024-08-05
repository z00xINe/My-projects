#include <bits/stdc++.h>

// =========================================================================================================

using namespace std;

// =========================================================================================================

int hexadecimalToDecimal(const string& hexadecimalNumber)
{
    return stoi(hexadecimalNumber, 0, 16);
}

// =========================================================================================================

string decimalToHexadecimal(int decimalNumber)
{
    stringstream ss;
    ss << hex << decimalNumber;
    return ss.str();
}

// =========================================================================================================

class Register
{
private:
    string c = "00"; // contain
    string ad = "00"; // address
public:
    Register(string x)
    {
        ad = x;
    }
    void set_value(string x)
    {
        c = x;
    }
    string get_value()
    {
        return c;
    }
    string get_address()
    {
        return ad;
    }
    ~Register()
    {
        c = "00";
    }
};

// =========================================================================================================

class Memory
{
private:
    string c = "00"; // contain
    string ad = "00"; // address
public:
    Memory(basic_string<char> x)
    {
        ad = x;
    }
    void set_value(string x)
    {
        c = x;
    }
    string get_value()
    {
        return c;
    }
    string get_address()
    {
        return ad;
    }
    ~Memory()
    {
        c = "00";
    }
};

// =========================================================================================================

class Machine
{
private:
    Memory* mem[256]{};
    Register* reg[16]{};
    int i = 0, s = 1, count = 0;
    string convert;
public:
    void Instruct1(string tmp)
    {
        convert.clear();
        convert += tmp[2];
        convert += tmp[3];
        i = hexadecimalToDecimal(convert);
        convert.clear();
        convert += tmp[1];
        s = hexadecimalToDecimal(convert);
        reg[s]->set_value(mem[i]->get_value());
    }

// =========================================================================================================

    void Instruct2(string tmp)
    {
        convert.clear();
        convert += tmp[1];
        i = hexadecimalToDecimal(convert);
        convert.clear();
        convert += tmp[2];
        convert += tmp[3];
        reg[i]->set_value(convert);
    }

// =========================================================================================================

    void Instruct3(string tmp)
    {
        convert.clear();
        convert += tmp[1];
        i = hexadecimalToDecimal(convert);
        convert.clear();
        convert += tmp[2];
        convert += tmp[3];
        s = hexadecimalToDecimal(convert);
        mem[s]->set_value(reg[i]->get_value());
    }

// =========================================================================================================

    void Instruct4(string tmp)
    {
        convert.clear();
        convert += tmp[2];
        i = hexadecimalToDecimal(convert);
        convert.clear();
        convert += tmp[3];
        s = hexadecimalToDecimal(convert);
        reg[i]->set_value(reg[s]->get_value());
    }

// =========================================================================================================

    void Instruct5(string tmp)
    {
        convert.clear();
        convert += tmp[2];
        s = hexadecimalToDecimal(convert);
        convert.clear();
        convert += tmp[3];
        i = hexadecimalToDecimal(convert);
        convert.clear();
        convert += tmp[1];
        int r = hexadecimalToDecimal(convert);
        convert.clear();
        int value1, value2, f;
        value1 = hexadecimalToDecimal(reg[s]->get_value());
        value2 = hexadecimalToDecimal(reg[i]->get_value());
        f = value1 + value2;
        convert = decimalToHexadecimal(f);
        reg[r]->set_value(convert);
    }

// =========================================================================================================

    int InstructB(string tmp)
    {
        convert = tmp[1];
        i = hexadecimalToDecimal(convert);
        if (reg[i]->get_value() == reg[0]->get_value())
        {
            convert.clear();
            convert += tmp[2];
            convert += tmp[3];
            i = hexadecimalToDecimal(convert);
            return i;
        }
        else
            return 300;
    }

// =========================================================================================================

    Machine(vector<string> instruct)
    {
        for (i = 0; i < 256; i++)
        {
            mem[i] = new Memory(decimalToHexadecimal(i));
        }
        for (auto& line : instruct)
        {
            convert += line[0];
            convert += line[1];
            mem[count]->set_value(convert);
            count++;
            convert.clear();
            convert += line[2];
            convert += line[3];
            mem[count]->set_value(convert);
            convert.clear();
            count++;
        }

        for (i = 0; i < 16; i++)
        {
            reg[i] = new Register(decimalToHexadecimal(i));
        }
        int y = 300;
        for (int j = 0; j < count; j++)
        {
            convert.clear();
            convert = mem[j]->get_value();
            j++;
            convert += mem[j]->get_value();
            y= 300;
            switch (convert[0])
            {
                case '1':
                    Instruct1(convert);
                    break;
                case '2':
                    Instruct2(convert);
                    break;
                case '3':
                    Instruct3(convert);
                    break;
                case '4':
                    Instruct4(convert);
                    break;
                case '5':
                    Instruct5(convert);
                    break;
                case 'B':
                    y = InstructB(convert);
                    break;
                case 'C':
                    break;
            }
            if (y < 256)
                j = y;
        }

        for (auto & m : mem)
        {
            cout << "Memory[" << m->get_address() << "]" << " = " << m->get_value() << endl;
        }

        cout << "======================================================================================\n";

        for (auto & r : reg)
        {
            cout << "Register[" << r->get_address() << "] " << "= " << r->get_value() << endl;
        }
    }
};

// ================================================================================================================================================

int main()
{
    ifstream file("Test.txt");

    if (!file)
    {
        cerr << "Error, can't open this file!\n";
        cerr << "Note: \"Test\" is the file name of your input file and his source is \".txt\"!\n";
        return 1;
    }

    vector <string> lines;
    string tmp;
    while (getline(file, tmp))
    {
        lines.push_back(tmp);
    }
    tmp.clear();
    for (auto & line : lines)
    {
        for (int j = 0; j < line.size(); j++)
        {
            if (line[j] != 'x' && line[j] != ' ' && line[j+1] != 'x')
                tmp += line[j];
        }
        line = tmp;
        tmp.clear();
    }
    Machine mac(lines);

    return 0;
}