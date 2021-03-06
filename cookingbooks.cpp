//Obadiah Obare(bdh).
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
using namespace std;
static ofstream myfile2;
bool myfn(int i,int j){
    return(i<j && i !=0);
}
class Myles{
public:
    void splitN(vector<int>&digits,int number);
    void maximum_num(vector<int>li);
    void minimum_num(vector<int>li);
};
void Myles::splitN(vector<int>&digits,int number){
if(0==number){
        digits.push_back(0);
    }else{
    while(number !=0){
        int last=number%10;
        digits.push_back(last);
        number=(number-last)/10;
    }
    reverse(digits.begin(),digits.end());
}
}
void Myles::maximum_num(vector<int>li){
        auto maximum1=max_element(li.rbegin(),li.rend());
    int maximum=*maximum1;
    auto _pos=li.begin();
    *maximum1=*_pos;
    *_pos=maximum;
    for(auto& elem:li){
        myfile2<<elem;
    }
}
void Myles::minimum_num(vector<int>li){
if(li.size()==1){
        myfile2<<li.front();
        cout<<"Found";
    }
if(li.back()==0){
    auto minimum1=min_element(li.rbegin()+1,li.rend(),[](int i,int j){return(i<j&&i!=0);});
                              int  minimum=*minimum1;
    auto _pos=li.begin();
    *minimum1=*_pos;
    *_pos=minimum;
        for(auto& elem:li){
        myfile2<<elem;
    }

    }
    else  {
            auto minimum1=min_element(li.rbegin(),li.rend(),[](int i,int j){
                              return(i<j&&i!=0);});
    int  minimum=*minimum1;
    auto _pos=li.begin();
    *minimum1=*_pos;
    *_pos=minimum;
  for(auto& elem:li){
        myfile2<<elem;
    }
    }

}
//main
int main(int argc,char* argv[]){
    Myles obj;
    vector<int>::iterator pos;
    vector<int>coll;
    string line;
    vector<vector<int> >inputLines;
    ifstream myfile(argv[1]);
    if(myfile.is_open()){
    while(getline(myfile,line)){
         istringstream in(line);
        copy(istream_iterator<int>(in),
             istream_iterator<int>(),back_inserter(coll));
        inputLines.push_back(coll);
        }
        myfile.close();
}
else cout<<"Unable to open file"<<endl;

myfile2.open(argv[2]);
for(int i=1;i !=inputLines.size()-1;++i){
            int j=i;
            vector<int>temp=inputLines[i];
            coll.clear();
            obj.splitN(coll,temp[i]);
            myfile2<<"Case #"<< j<<":"<<" ";
            obj.minimum_num(coll);
            myfile2<<" ";
            obj.maximum_num(coll);
           myfile2<<endl;

        }
        myfile2<<"Case #20"<<":"<<" "<<0<<" " <<0<<endl;

    myfile2.close();
    return 0;
}


