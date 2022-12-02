#include <iostream>
#include <fstream>
#include <windows.h>
#include "vector"

#define print(a) cout<<" "<<a<<" "<<endl

using namespace std;

vector<string> split(string s){
    int q = 0;
    vector<string> sout(3);
    for(int i = 0;i<s.size();i++){
        if(s[i] != ';')
            sout[q] += s[i];
        else
            q++;
        if(q == 3)
            break;
    }
    return sout;
}

char shift_eng(char c,int shift){
    if (c - shift > 96 and c - shift < 123)
        c = char(c - shift);
    else {
        if (c - shift < 97)
            c = char(123 - (97 - (c - shift)));
        else {
            if (c - shift > 122)
                c = char(96 + ((c - shift) - 122));
        }
    }
    return c;
}

//170
//160-175
//224-239

string decode_mail(string mail){
    int q = 0;
    int shift = 0;
    for(int i = mail.size();mail[i] != '.';i--,q++){}
    if(q == 4) {
        if('o' == shift_eng(mail[mail.size()-2],int(mail[mail.size()-1]-'m')) and 'c' == shift_eng(mail[mail.size()-3],int(mail[mail.size()-1]-'m')))
            shift = int(mail[mail.size()-1]-'m');
        if('i' == shift_eng(mail[mail.size()-2],int(mail[mail.size()-1]-'z')) and 'a' == shift_eng(mail[mail.size()-3],int(mail[mail.size()-1]-'z')))
            shift = int(mail[mail.size()-1]-'z');
        if('r' == shift_eng(mail[mail.size()-2],int(mail[mail.size()-1]-'h')) and 'a' == shift_eng(mail[mail.size()-3],int(mail[mail.size()-1]-'h')))
            shift = int(mail[mail.size()-1]-'h');
        if('e' == shift_eng(mail[mail.size()-2],int(mail[mail.size()-1]-'s')) and 'b' == shift_eng(mail[mail.size()-3],int(mail[mail.size()-1]-'s')))
            shift = int(mail[mail.size()-1]-'s');
        if('d' == shift_eng(mail[mail.size()-2],int(mail[mail.size()-1]-'m')) and 'q' == shift_eng(mail[mail.size()-3],int(mail[mail.size()-1]-'b')))
            shift = int(mail[mail.size()-1]-'b');
        if('o' == shift_eng(mail[mail.size()-2],int(mail[mail.size()-1]-'m')) and 'b' == shift_eng(mail[mail.size()-3],int(mail[mail.size()-1]-'m')))
            shift = int(mail[mail.size()-1]-'m');
        if('r' == shift_eng(mail[mail.size()-2],int(mail[mail.size()-1]-'g')) and 'o' == shift_eng(mail[mail.size()-3],int(mail[mail.size()-1]-'g')))
            shift = int(mail[mail.size()-1]-'g');
        if('i' == shift_eng(mail[mail.size()-2],int(mail[mail.size()-1]-'a')) and 'b' == shift_eng(mail[mail.size()-3],int(mail[mail.size()-1]-'a')))
            shift = int(mail[mail.size()-1]-'a');
        if('p' == shift_eng(mail[mail.size()-2],int(mail[mail.size()-1]-'m')) and 'c' == shift_eng(mail[mail.size()-3],int(mail[mail.size()-1]-'m')))
            shift = int(mail[mail.size()-1]-'m');
        if('e' == shift_eng(mail[mail.size()-2],int(mail[mail.size()-1]-'t')) and 'n' == shift_eng(mail[mail.size()-3],int(mail[mail.size()-1]-'t')))
            shift = int(mail[mail.size()-1]-'t');
        if('e' == shift_eng(mail[mail.size()-2],int(mail[mail.size()-1]-'u')) and 'o' == shift_eng(mail[mail.size()-3],int(mail[mail.size()-1]-'u')))
            shift = int(mail[mail.size()-1]-'u');
        if('i' == shift_eng(mail[mail.size()-2],int(mail[mail.size()-1]-'z')) and 'b' == shift_eng(mail[mail.size()-3],int(mail[mail.size()-1]-'z')))
            shift = int(mail[mail.size()-1]-'z');
    }
    if(q == 5){
        if('f' == shift_eng(mail[mail.size()-2],int(mail[mail.size()-1]-'o')) and 'n' == shift_eng(mail[mail.size()-3],int(mail[mail.size()-1]-'o')))
            shift = int(mail[mail.size()-1]-'o');
        if('e' == shift_eng(mail[mail.size()-2],int(mail[mail.size()-1]-'o')) and 'n' == shift_eng(mail[mail.size()-3],int(mail[mail.size()-1]-'o')))
            shift = int(mail[mail.size()-1]-'o');
    }
    for(int i = 0;i<mail.size();i++){
        if(mail[i] != '@' and mail[i] != '.' and mail[i] != '1' and mail[i] != '2' and mail[i] != '3'
        and mail[i] != '4' and mail[i] != '5' and mail[i] != '6' and mail[i] != '7' and mail[i] != '8' and
                mail[i] != '9' and mail[i] != '0'){
            mail[i] = shift_eng(mail[i],shift);
        }
    }
    return mail;
}

string clear(string s){
    string sout;
    for(int i = 0;i<s.size();i++)
        if (i > 40)
            sout+=s[i];

    return sout;
}

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    fstream in1("../student_8.csv");
    fstream in2("../hash.txt");
    fstream in3("../decoded.txt");
    ofstream out("../student_8_done.csv");
    string s1,s2,s3,s4;
    getline(in1,s1);
    out<<s1<<endl;
    vector<string> str;
    while(!in1.eof()){
        getline(in1,s1);
        getline(in2,s2);
        getline(in3,s4);
        str = split(s1);
        out<<clear(s2)<<";"<<decode_mail(str[1])<<";"<<s4<<endl;
    }
    return 0;

}
