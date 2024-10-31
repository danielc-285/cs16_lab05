#include <iostream> // for cin, cout, endl
#include <cstdlib>  // for exit()
#include <cmath>    // for pow() function ONLY
using namespace std;

// FUNCTION DECLARATIONS: YOU MUST DEFINE AND USE THESE (do not remove):
//      You can declare/define other functions if you like as well,
//      but you must use the 2 functions below.
//Pre-Condition:
//Post-Condition:
int bin2d(string binstring);

//Pre-Condition:
//Post-Condition:
string dec2bh(string sdec, char bh);

int main ( int argc, char *argv[] ) {
    string converted_value;
    if(argc == 1){
        cerr << "Usage: converter <options: d2b, d2h, b2d> <value>" << endl;
        exit(1);
    }
    string operation = argv[1];
    string number = argv[2];
    if(operation == "d2b"){
            converted_value = dec2bh(number, 'b');
            cout << "The value in binary is: " << converted_value << endl;
    }
    else if(operation == "d2h"){
            converted_value = dec2bh(number, 'h');
            cout << "The value in hexadecimal is: " << converted_value << endl;
    }
    else if(operation == "b2d"){
            converted_value = to_string(bin2d(number));
            if(converted_value == "-1"){
                cerr << "Binary value contains non-binary digits." << endl;
                exit(1);
            }
            cout << "The value in decimal is: " << converted_value << endl;
    }
    else{
            cerr << "Usage: converter <options: d2b, d2h, b2d> <value>" << endl;
            exit(1);
    }
    return 0;
}

int bin2d(string binstring){
    int dec_value = 0;
    for(int i = 0; i < binstring.length(); i++){
        if(binstring[i] == '1'){
            dec_value += static_cast<int>(pow(2, binstring.length() - 1 - i));
        }
        else if(binstring[i] != '0'){
            dec_value = -1;
            break;
        }
    }
    return dec_value;

}

string dec2bh(string sdec, char bh){
    string bh_value = "";
    int dec_value = stoi(sdec);
    if(bh == 'b'){
        int bin_value = 0;
        int exp_count = 0;
        while(dec_value > 1){
            dec_value /= 2;
            exp_count++;
        }
        dec_value = stoi(sdec);
        for(int i = exp_count; i >= 0; i--){
            if(dec_value / static_cast<int>(pow(2, i)) != 0){
                bin_value += static_cast<int>(pow(10, i));
                dec_value -= static_cast<int>(pow(2, i));
            }
        }
        bh_value = to_string(bin_value);
    }
    else if(bh == 'h'){
        int exp_count = 0;
        while(dec_value > 1){
            dec_value /= 16;
            exp_count++;
        }
        dec_value = stoi(sdec);
        for(int i = exp_count; i >= 0; i--){
            char hex_value;
            if(dec_value / static_cast<int>(pow(16,i)) != 0){
                
                int hex_value_int = dec_value / static_cast<int>(pow(16,i));
                hex_value = hex_value_int;
                dec_value -= hex_value_int*static_cast<int>(pow(16,i));
                if(hex_value > 9){
                    hex_value += 55;
                }
                else{
                    hex_value += 48;
                }
                bh_value += hex_value;
            }
        }
    }
    return bh_value;
}

