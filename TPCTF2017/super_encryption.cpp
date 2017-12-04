#include <iostream>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;
void swap5(string &input);
void swap3(string &input);

void decrypt(string &input)
{
    swap3(input);
    swap5(input);
    for(int i = 0; i < input.size(); i++)
    {
        unsigned char v3 = (((i + 22) / 2 ^ 0x1B ) % 11);
        input[i] -= v3;
    }
}

void encrypt(char *input)
{
    unsigned long long v7;
    string pass1;
    int input_length = 0;
    for(int i = 0; input[i] != 10; i++)
    {
        input_length++;
        double v13 = input[i];
        double v3 = floor( (double) ( ( (i+22) / 2 ^ 0x1B ) % 11) );
        pass1.push_back((char)floor(v3 + v13));
    }

    cout << "pass1=" << pass1 << endl;

    string pass2;
    int i = 0;
    while(i + 4 < input_length)
    {
        pass2.push_back(pass1[i+4]);
        pass2.push_back(pass1[i+3]);
        pass2.push_back(pass1[i+2]);
        pass2.push_back(pass1[i+1]);
        pass2.push_back(pass1[i]);
        i+=5;
    }
    while(i < input_length)
    {
        pass2.push_back(pass1[i]);
        i++;
    }
    
    cout << "pass2=" << pass2 << endl;
    
    string s;
    i = 0;
    while(i + 3 < input_length)
    {
        s.push_back(pass2[i+2]);
        s.push_back(pass2[i+1]);
        s.push_back(pass2[i]);
        i+=3;
    }
    while(i < input_length)
    {
        s.push_back(pass2[i]);
        i++;
    }
    cout << "pass3=" << s << endl;
}

void swap5(string &input)
{
    int i = 0;
    while(i + 4 < input.size())
    {
        //cout << input << endl;
        char a = input[i];
        char b = input[i+1];
        char c = input[i+2];
        char d = input[i+3];
        char e = input[i+4];

        input[i+4] = a;
        input[i+3] = b;
        input[i+2] = c;
        input[i+1] = d;
        input[i] = e;
        i+=5;
    }
    //cout << "pass2=" << input << endl;
}

void swap3(string &input)
{
    int i = 0;
    while(i + 3 < input.size()) // i+2?
    {
        char a = input[i];
        char c = input[i+2];

        input[i+2] = a;
        input[i] = c;
        i+=3;
    }
    //cout << "pass3=" << input << endl;
}

int main()
{
    string flag = "dufhyuc>bi{{f0|;vwh<~b5p5thjq6goj}";

    //char input[] = "dufhyuc>bi{{f0|;vwh<~b5p5thjq6goj}\xa";
    //char input[] = "tpctf{aaaaaaaaaaaaaaaaaaaaaaaaaaa}\xa";
    //encrypt(input);
    decrypt(flag);
    cout << flag << endl;
    return 0;
}
