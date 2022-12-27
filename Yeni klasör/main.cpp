#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

/**
 * This is about matrices and arrays in c++
 * Also needs arguments you can use file name as I pushed it.
 * This is a game like your input file sends the the command where the number will be pushed like:
 *  Number <White Space> Row <White Space> Column
 *  And if 3 of them are the same number then collect them where the last one pushed and add number 1
 */


using namespace std;
void write(string part1, string part2, string fileName){
    string result = "PART 1:\n" + part1 + "\n" + "PART 2:\n" + part2;
    ofstream file(fileName, ios::out);
    file << result;
}
string read(const string& fileName){
    ifstream file(fileName, ios::in);
    string line;
    string a;
    while (getline(file, line)){
        a += line + "\n";
    }

    file.close();
    return a;
}

string part1(string fileName) {
    // This part is the input 1.
    string fileReturn = read(fileName);
    string size;
    for (char size1 : fileReturn){
        if (size1 == '\n'){
            break;
        }
        else{
            size += size1;
        }
    }
    int emptyArray[stoi(size)][stoi(size)];

    for (int i = 0; i < stoi(size); ++i) {
        for (int j = 0; j < stoi(size); ++j) {
            emptyArray[i][j] = 0;
        }
    }


    string emp;
    int count1 = 0;
    for (char count : fileReturn){
        if (count == '\n'){
            break;
        } else{
            count1++;
        }
    }
    for (char line : fileReturn.substr(count1+1)) {

        if (line != '\n') {
            emp += line;
        } else {
            string i;
            string j;
            string value;
            string chars;
            count1 = 0;
            for (char char1 : emp){
                if (char1 == ' ' && count1 == 0){
                    value = chars;
                    chars = "";
                    count1++;
                }
                else if(char1 == ' ' && count1 == 1){
                    i = chars;
                    chars = "";
                    count1++;
                }
                else{
                    chars += char1;
                }
            }
            j = chars;
            stringstream is(i);
            int ii;
            is >> ii;
            stringstream js(j);
            int ji;
            js >> ji;
            stringstream vs(value);
            int valuei;
            vs >> valuei;
            emptyArray[ii][ji] = valuei;

            vector<int> temp;

            bool control = true;

            while (control){
                if (ji + 1 < stoi(size) && emptyArray[ii][ji + 1] == valuei){
                    temp.push_back(ii);
                    temp.push_back(ji + 1);
                    if (ii - 1 >= 0 && emptyArray[ii - 1][ji + 1] == valuei){
                        temp.push_back(ii - 1);
                        temp.push_back(ji + 1);
                        if (ii - 2 >= 0 && emptyArray[ii - 2][ji + 1] == valuei){
                            temp.push_back(ii - 2);
                            temp.push_back(ji + 1);
                            if (ii - 3 >= 0 && emptyArray[ii - 3][ji + 1] == valuei){
                                temp.push_back(ii - 3);
                                temp.push_back(ji + 1);
                            }
                        }
                    }
                    if (ii + 1 < stoi(size) && emptyArray[ii + 1][ji + 1] == valuei){
                        temp.push_back(ii + 1);
                        temp.push_back(ji + 1);
                        if (ii + 2 < stoi(size) && emptyArray[ii + 2][ji + 1] == valuei){
                            temp.push_back(ii + 2);
                            temp.push_back(ji + 1);
                            if (ii + 3 >= 0 && emptyArray[ii + 3][ji + 1] == valuei){
                                temp.push_back(ii + 3);
                                temp.push_back(ji + 1);
                            }
                        }
                    }
                    if (ji + 2 < stoi(size) && emptyArray[ii][ji + 2] == valuei){
                        temp.push_back(ii);
                        temp.push_back(ji + 2);
                        if (ii - 1 >= 0 && emptyArray[ii - 1][ji + 2] == valuei){
                            temp.push_back(ii - 1); temp.push_back(ji + 2);
                            if (ii - 2 >= 0 && emptyArray[ii - 2][ji + 2] == valuei){
                                temp.push_back(ii - 2); temp.push_back(ji + 2);
                            }
                        }
                        if (ii + 1 < stoi(size) && emptyArray[ii + 1][ji + 2] == valuei){
                            temp.push_back(ii + 1); temp.push_back(ji + 2);
                            if (ii + 2 < stoi(size) && emptyArray[ii + 2][ji + 2] == valuei){
                                temp.push_back(ii + 2); temp.push_back(ji + 2);
                            }
                        }
                        if (ji + 3 < stoi(size) && emptyArray[ii][ji + 3] == valuei){
                            temp.push_back(ii);
                            temp.push_back(ji + 3);
                            if (ii - 1 >= 0 && emptyArray[ii - 1][ji + 3] == valuei){
                                temp.push_back(ii - 1); temp.push_back(ji + 3);
                            }
                            if (ii + 1 < stoi(size) && emptyArray[ii + 1][ji + 3] == valuei){
                                temp.push_back(ii + 1); temp.push_back(ji + 3);
                            }
                            if (ji + 4 < stoi(size) && emptyArray[ii][ji + 4]== valuei){
                                temp.push_back(ii);
                                temp.push_back(ji + 4);
                            }
                        }
                    }
                }

                if (ji - 1 >= 0 && emptyArray[ii][ji - 1] == valuei){
                    temp.push_back(ii);
                    temp.push_back(ji - 1);
                    if (ii - 1 >= 0 && emptyArray[ii - 1][ji - 1] == valuei){
                        temp.push_back(ii - 1);
                        temp.push_back(ji - 1);
                        if (ii - 2 >= 0 && emptyArray[ii - 2][ji - 1] == valuei){
                            temp.push_back(ii - 2);
                            temp.push_back(ji - 1);
                            if (ii - 3 >= 0 && emptyArray[ii - 3][ji - 1] == valuei){
                                temp.push_back(ii - 3);
                                temp.push_back(ji - 1);
                            }
                        }
                    }
                    if (ii + 1 < stoi(size) && emptyArray[ii + 1][ji - 1] == valuei){
                        temp.push_back(ii + 1);
                        temp.push_back(ji - 1);
                        if (ii + 2 < stoi(size) && emptyArray[ii + 2][ji - 1] == valuei){
                            temp.push_back(ii + 2);
                            temp.push_back(ji - 1);
                            if (ii + 3 >= 0 && emptyArray[ii + 3][ji - 1] == valuei){
                                temp.push_back(ii + 3);
                                temp.push_back(ji - 1);
                            }
                        }
                    }
                    if (ji - 2 < stoi(size) && emptyArray[ii][ji - 2] == valuei){
                        temp.push_back(ii);
                        temp.push_back(ji - 2);
                        if (ii - 1 >= 0 && emptyArray[ii - 1][ji - 2] == valuei){
                            temp.push_back(ii - 1); temp.push_back(ji - 2);
                            if (ii - 2 >= 0 && emptyArray[ii - 2][ji - 2] == valuei){
                                temp.push_back(ii - 2); temp.push_back(ji - 2);
                            }
                        }
                        if (ii + 1 < stoi(size) && emptyArray[ii + 1][ji - 2] == valuei){
                            temp.push_back(ii + 1); temp.push_back(ji - 2);
                            if (ii + 2 < stoi(size) && emptyArray[ii + 2][ji - 2] == valuei){
                                temp.push_back(ii + 2); temp.push_back(ji - 2);
                            }
                        }
                        if (ji - 3 < stoi(size) && emptyArray[ii][ji - 3] == valuei){
                            temp.push_back(ii);
                            temp.push_back(ji - 3);
                            if (ii - 1 >= 0 && emptyArray[ii - 1][ji - 3] == valuei){
                                temp.push_back(ii - 1); temp.push_back(ji - 3);
                            }
                            if (ii + 1 < stoi(size) && emptyArray[ii + 1][ji - 3] == valuei){
                                temp.push_back(ii + 1); temp.push_back(ji - 3);
                            }
                            if (ji - 4 < stoi(size) && emptyArray[ii][ji - 4]== valuei){
                                temp.push_back(ii);
                                temp.push_back(ji - 4);
                            }
                        }
                    }
                }

                if (ii + 1 < stoi(size) && emptyArray[ii + 1][ji] == valuei){
                    temp.push_back(ii + 1);
                    temp.push_back(ji);
                    if (ji + 1 < stoi(size) && emptyArray[ii + 1][ji + 1] == valuei){
                        temp.push_back(ii + 1);
                        temp.push_back(ji + 1);
                        if (ji + 2 < stoi(size) && emptyArray[ii + 1][ji + 2] == valuei){
                            temp.push_back(ii + 1);
                            temp.push_back(ji + 2);
                            if (ji + 3 < stoi(size) && emptyArray[ii + 1][ji + 3] == valuei){
                                temp.push_back(ii - 3);
                                temp.push_back(ji + 1);
                            }
                        }
                    }
                    if (ji - 1 >= 0 && emptyArray[ii + 1][ji - 1] == valuei){
                        temp.push_back(ii + 1);
                        temp.push_back(ji - 1);
                        if (ji - 2 >= 0 && emptyArray[ii + 1][ji - 2] == valuei){
                            temp.push_back(ii + 1);
                            temp.push_back(ji - 2);
                            if (ji - 3 >= 0 && emptyArray[ii + 1][ji - 2] == valuei){
                                temp.push_back(ii + 1);
                                temp.push_back(ji - 3);
                            }
                        }
                    }
                    if (ii + 2 < stoi(size) && emptyArray[ii + 2][ji] == valuei){
                        temp.push_back(ii + 2);
                        temp.push_back(ji);
                        if (ji - 1 >= 0 && emptyArray[ii + 2][ji - 1] == valuei){
                            temp.push_back(ii + 2); temp.push_back(ji - 1);
                            if (ji - 2 >= 0 && emptyArray[ii + 2][ji - 2] == valuei){
                                temp.push_back(ii + 2); temp.push_back(ji - 2);
                            }
                        }
                        if (ji + 1 < stoi(size) && emptyArray[ii + 2][ji + 1] == valuei){
                            temp.push_back(ii + 2); temp.push_back(ji + 1);
                            if (ji + 2 < stoi(size) && emptyArray[ii + 2][ji + 2] == valuei){
                                temp.push_back(ii + 2); temp.push_back(ji + 2);
                            }
                        }
                        if (ii + 3 < stoi(size) && emptyArray[ii + 3][ji] == valuei){
                            temp.push_back(ii + 3);
                            temp.push_back(ji);
                            if (ji - 1 >= 0 && emptyArray[ii + 3][ji - 1] == valuei){
                                temp.push_back(ii + 3); temp.push_back(ji - 1);
                            }
                            if (ji + 1 < stoi(size) && emptyArray[ii + 3][ji + 1] == valuei){
                                temp.push_back(ii + 3); temp.push_back(ji + 1);
                            }
                            if (ii + 4 < stoi(size) && emptyArray[ii + 4][ji]== valuei){
                                temp.push_back(ii + 4);
                                temp.push_back(ji);
                            }
                        }
                    }
                }

                if (ii - 1 < stoi(size) && emptyArray[ii - 1][ji] == valuei){
                    temp.push_back(ii - 1);
                    temp.push_back(ji);
                    if (ji + 1 < stoi(size) && emptyArray[ii - 1][ji + 1] == valuei){
                        temp.push_back(ii - 1);
                        temp.push_back(ji + 1);
                        if (ji + 2 < stoi(size) && emptyArray[ii - 1][ji + 2] == valuei){
                            temp.push_back(ii - 1);
                            temp.push_back(ji + 2);
                            if (ji + 3 < stoi(size) && emptyArray[ii - 1][ji + 3] == valuei){
                                temp.push_back(ii - 1);
                                temp.push_back(ji + 3);
                            }
                        }
                    }
                    if (ji - 1 >= 0 && emptyArray[ii - 1][ji - 1] == valuei){
                        temp.push_back(ii - 1);
                        temp.push_back(ji - 1);
                        if (ji - 2 >= 0 && emptyArray[ii - 1][ji - 2] == valuei){
                            temp.push_back(ii - 1);
                            temp.push_back(ji - 2);
                            if (ji - 3 >= 0 && emptyArray[ii - 1][ji - 2] == valuei){
                                temp.push_back(ii + 1);
                                temp.push_back(ji - 3);
                            }
                        }
                    }
                    if (ii - 2 < stoi(size) && emptyArray[ii - 2][ji] == valuei){
                        temp.push_back(ii - 2);
                        temp.push_back(ji);
                        if (ji - 1 >= 0 && emptyArray[ii - 2][ji - 1] == valuei){
                            temp.push_back(ii - 2); temp.push_back(ji - 1);
                            if (ji - 2 >= 0 && emptyArray[ii - 2][ji - 2] == valuei){
                                temp.push_back(ii - 2); temp.push_back(ji - 2);
                            }
                        }
                        if (ji + 1 < stoi(size) && emptyArray[ii - 2][ji + 1] == valuei){
                            temp.push_back(ii - 2); temp.push_back(ji + 1);
                            if (ji + 2 < stoi(size) && emptyArray[ii - 2][ji + 2] == valuei){
                                temp.push_back(ii - 2); temp.push_back(ji + 2);
                            }
                        }
                        if (ii - 3 < stoi(size) && emptyArray[ii - 3][ji] == valuei){
                            temp.push_back(ii - 3);
                            temp.push_back(ji);
                            if (ji - 1 >= 0 && emptyArray[ii - 3][ji - 1] == valuei){
                                temp.push_back(ii - 3); temp.push_back(ji - 1);
                            }
                            if (ji + 1 < stoi(size) && emptyArray[ii - 3][ji + 1] == valuei){
                                temp.push_back(ii - 3); temp.push_back(ji + 1);
                            }
                            if (ii - 4 < stoi(size) && emptyArray[ii - 4][ji]== valuei){
                                temp.push_back(ii - 4);
                                temp.push_back(ji);
                            }
                        }
                    }
                }

                if (temp.size() / 2 >= 2){
                    valuei = valuei + 1;
                    emptyArray[ii][ji] = valuei;
                    int index = 0;
                    for (int zero = 0; zero < temp.size() / 2; zero++){
                        emptyArray[temp.at(index)][temp.at(index + 1)] = 0;
                        index += 2;
                    }
                    temp.clear();
                    if (!(emptyArray[ii][ji + 1] == valuei || emptyArray[ii][ji - 1] == valuei
                          || emptyArray[ii + 1][ji] == valuei || emptyArray[ii - 1][ji] == valuei)){
                        control = false;
                    }
                } else{
                    control = false;
                }
            }

            emp = "";
        }
    }
    string end;

    for (int k = 0; k < stoi(size); ++k) {
        for (int l = 0; l < stoi(size); ++l) {
            end += to_string(emptyArray[k][l]);
            if (l == stoi(size) - 1){
                end += "\n";
            }else{
                end += " ";
            }
        }

    }
    return end;
}

string part2(string fileName){
    string mainFile = read(fileName);
    string strSize;
    int size;
    int index = 0;
    for (char chrSize : mainFile){
        if (chrSize == '\n'){
            index ++;
            break;
        } else{
            index ++;
            strSize += chrSize;
        }
    }
    stringstream ssSize(strSize);
    ssSize >> size;
    int newArray[size][size];

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++) {
            string a;
            stringstream b;
            int vt;
            for (char sum : mainFile.substr(index)){
                if (sum == ' ' || sum == '\n'){
                    index ++;
                    break;
                } else{
                    a += sum;
                    index ++;
                }
            }
            b << a;
            b >> vt;
            newArray[i][j] = vt;
        }
    }
    int point = 0;
    while (index < mainFile.size()){
        int iValue;
        int jValue;
        string strI;
        string strJ;
        string emp;
        for (char find : mainFile.substr(index)){
            if (find == ' '){
                strI = emp;
                emp = "";
                index ++;
            } else if (find == '\n'){
                strJ = emp;
                emp = "";
                index ++;
                break;
            }else{
                emp += find;
                index ++;
            }
        }
        stringstream ssI;
        ssI << strI;
        ssI >> iValue;
        stringstream ssJ;
        ssJ << strJ;
        ssJ >> jValue;


        int value = newArray[iValue][jValue];
        vector<int> temp;
        int many = 1;

        for (int general = 0; general < 8; general++){
            if (general == 0){
                for (int inner = 1; inner < size; inner++){
                    if (iValue - inner >= 0 && jValue + inner < size && newArray[iValue - inner][jValue + inner] == value){
                        temp.push_back(iValue - inner);
                        temp.push_back(jValue + inner);
                        many += 1;
                    }
                }
            }

            else if (general == 1){
                for (int inner = 1; inner < size; inner++){
                    if (jValue + inner < size && newArray[iValue][jValue + inner] == value){
                        temp.push_back(iValue);
                        temp.push_back(jValue + inner);
                        many += 1;
                    }
                }
            }

            else if (general == 2){
                for (int inner = 1; inner < size; inner++){
                    if (iValue + inner < size && jValue + inner < size && newArray[iValue + inner][jValue + inner] == value){
                        temp.push_back(iValue + inner);
                        temp.push_back(jValue + inner);
                        many += 1;
                    }
                }
            }

            else if (general == 3){
                for (int inner = 1; inner < size; inner++){
                    if (iValue + inner < size && newArray[iValue + inner][jValue] == value){
                        temp.push_back(iValue + inner);
                        temp.push_back(jValue);
                        many += 1;
                    }
                }
            }

            else if (general == 4){
                for (int inner = 1; inner < size; inner++){
                    if (iValue + inner < size && jValue - inner >= 0 && newArray[iValue + inner][jValue - inner] == value){
                        temp.push_back(iValue + inner);
                        temp.push_back(jValue - inner);
                        many += 1;
                    }
                }
            }

            else if (general == 5){
                for (int inner = 1; inner < size; inner++){
                    if (jValue - inner >= 0 && newArray[iValue][jValue - inner] == value){
                        temp.push_back(iValue);
                        temp.push_back(jValue - inner);
                        many += 1;
                    }
                }
            }

            else if (general == 6){
                for (int inner = 1; inner < size; inner++){
                    if (iValue - inner >= 0 && jValue - inner >= 0 && newArray[iValue - inner][jValue - inner] == value){
                        temp.push_back(iValue - inner);
                        temp.push_back(jValue - inner);
                        many += 1;
                    }
                }
            }

            else if (general == 7){
                for (int inner = 1; inner < size; inner++){
                    if (iValue - inner >= 0 && newArray[iValue - inner][jValue] == value){
                        temp.push_back(iValue - inner);
                        temp.push_back(jValue);
                        many += 1;
                    }
                }
            }
            newArray[iValue][jValue] = 0;
        }
        int find = 0;
        for (int zero = 0; zero < temp.size() / 2; zero++){
            newArray[temp.at(find)][temp.at(find + 1)] = 0;
            find += 2;
        }

        point += many * value;
    }
    string end;
    for (int k = 0; k < size; ++k) {
        for (int l = 0; l < size; ++l) {
            end += to_string(newArray[k][l]);
            if (l == size - 1){
                end += "\n";
            }else{
                end += " ";
            }
        }
    }
    end += "Final Point: " + to_string(point) + "p";
    return end;
}

int main(int argc, char *argv[]){
    write(part1(argv[1]), part2(argv[2]), argv[3]);
    return 0;
}