#include <string>
#include <iostream>
#include <vector>

using namespace std;

class input{
    private:
        string before;
        string after;

    public:
        input(string in){
            before=in;
        }

        bool convert_to_txt(){
            bool success=false;
            after="";


           

           for(char &c:before){
               
               if(c=='.'){
                   after=after+"[ dot ]";
               }else if(c=='/'){
                   after=after+"[ forwardslash ]";
               }else if(c=='#'){
                   after=after+"[ hash ]";
               }else if(c=='?'){
                   after=after+"[ questionmark ]";
               }else if(c=='+'){
                   after=after+"[ plus ]";
               }else{
                   after=after+c;
               }
           }

            
            
            if(after==before){
                cout<<"Failed to convert website to txt"<<endl;
                cout<<"Or website wasn't valid"<<endl;
                success=false;
            }else{
                success=true;
            }
            return success;
        }

        bool convert_to_web(){
            bool success=false;

            after=before;
            string pplus="[ plus ]";
            string question="[ questionmark ]";
            string has="[ hash ]";
            string slash="[ forwardslash ]";
            string dot="[ dot ]";

            //loop for those sings
            bool end=false;
            while(end==false){
                while(after.find(dot,0)!=string::npos){
                    auto loc=after.find(dot,0);
                    after.erase(loc,dot.size());
                    after.insert(loc,".");
                }
                while(after.find(slash,0)!=string::npos){
                    auto loc=after.find(slash,0);
                    after.erase(loc,slash.size());
                    after.insert(loc,"/");
                }
                while(after.find(has,0)!=string::npos){
                    auto loc=after.find(has,0);
                    after.erase(loc,has.size());
                    after.insert(loc,"#");
                }
                while(after.find(question,0)!=string::npos){
                    auto loc=after.find(question,0);
                    after.erase(loc,question.size());
                    after.insert(loc,"?");
                }
                while(after.find(pplus,0)!=string::npos){
                    auto loc=after.find(pplus,0);
                    after.erase(loc,pplus.size());
                    after.insert(loc,"+");
                }
                end=true;
            }
            if(after==before){
                cout<<"Failed to convert website to txt"<<endl;
                cout<<"Or website wasn't valid"<<endl;
                success=false;
            }else{
                success=true;
            }
           


            return success;
        }

        string &getBefore(){
            return before;
        }
        string &getAfter(){
            return after;
        }
};

int main(){
    cout<<"Enter website bellow"<<endl;
    string website;
    getline(cin,website);

    //input to change
    input converter(website);
    converter.convert_to_txt();
    
    //after converting display
    cout<<"Your website in txt is:"<<endl;
    cout<<converter.getAfter()<<endl;
    return 0;
}
