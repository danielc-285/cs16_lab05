#include <iostream> // for cin, cout
#include <vector>   // for vector
#include <string>   // for getline()
using namespace std;

// FUNCTION DECLARATION: YOU MUST DEFINE AND USE THIS (do not remove):
//      You can declare/define other functions if you like as well,
//      but you must use function split() below.
//Pre-Condition: 
//Post-Condition: 
vector<string> split(string target, string delimiter);

int main(){
    string input_string, input_delimiter;
    cout << "Enter string to split:" << endl;
    getline(cin, input_string);
    cout << "Enter delimiter string:" << endl;
    getline(cin, input_delimiter);
    vector<string> output = split(input_string, input_delimiter);
    if(output.size() > 0){
        cout << "The substrings are: ";
        for(int i = 0; i < output.size() - 1; i++){
            cout << "\"" << output[i] << "\", ";
        }
        cout << "\"" << output[output.size() - 1] << "\"" << endl;
    }
    else{
        cout << "No substrings." << endl;
    }
    return 0;
}

vector<string> split(string target, string delimiter){
    vector<string> separate_strings;
    if(target.find(delimiter) == string::npos){
        separate_strings.push_back(target);
    }
    else{
        while(true){
            int delim_index = target.find(delimiter);
            if(delim_index != string::npos && delim_index != 0){
                separate_strings.push_back(target.substr(0, delim_index));
            }
            else if(delim_index == string::npos){
                separate_strings.push_back(target);
                break;
            }
            if(target.length() > 1){
                target = target.substr(delim_index + 1, target.length() - delim_index - 1);
            }
            else{
                break;
            }
        }
    }
    return separate_strings;
}

