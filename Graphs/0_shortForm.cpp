#include<bits/stdc++.h>
using namespace std;
 
string getInitialism(string s){
        //this is default OUTPUT. You can change it.
        string result = "";
        vector<string> iw = {"and", "of", "for"};
        string temp = "";
        int n = s.size();
        int i = 0;
        int x = 0;
        for (int i = 0; i < n; i++)
        {
                if(s[i] != ' '){
                        temp.push_back(s[i]);
                }
                else {
                        x++;
                        if(find(iw.begin(), iw.end(), temp) == iw.end()) {
                            result.push_back(toupper(temp[0])) ;
                        }
                        temp = "";
                }
        }
        if(find(iw.begin(),iw.end(), temp) == iw.end())
            result.push_back(toupper(temp[0]));

        return result;
}
        
 
int main(){
        //INPUT [uncomment & modify if required]
        int n;
        cin>>n;
        string s;
        cin.ignore();
        getline(cin, s);
        // cout <<"fewrf" << s << "WEFewrf";


        // OUTPUT [uncomment & modify if required]
        cout<<getInitialism(s)<<endl;
}