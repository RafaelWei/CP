#include<bits/stdc++.h>

using namespace std;

typedef pair<string, string> ss;
typedef vector<ss> vss;
string separator="by";

bool myComp(const ss &p1, const ss &p2){
    if(p1.second!=p2.second) return p1.second<p2.second;
    return p1.first < p2.first;
}

int main(){
    vss books;
    vector<bool> returned, borrowed;
    string str;
    string token1, token2;
    int pos;

    getline(cin, str);
    while(str!="END"){
        pos = str.find(separator);
        token1 = str.substr(0, pos);
        token2 = str.erase(0, pos+separator.length()+1);
        books.push_back(make_pair(token1, token2));
        getline(cin, str);
    }
    returned.assign(books.size(), false);
    returned.assign(books.size(), false);
    sort(books.begin(), books.end(), myComp);

    getline(cin, str);
    while(str!="END"){
        pos = str.find(' ');
        token1 = str.substr(0, pos);
        token2 = str.erase(0, pos+1);
        if(token1=="BORROW"){
            for(int i=0; i<books.size(); i++){
                if(books[i].first == token2){
                    borrowed[i]=true;
                    returned[i]=false;
                    break;
                }
            }
        }
        else if(token1=="RETURN"){
            for(int i=0; i<books.size(); i++){
                if(books[i].first == token2){
                    borrowed[i]=false;
                    returned[i]=true;
                    break;
                }
            }
        }
        else if(token1=="SHELVE"){
            int previous=-1;
                for(int i=0; i<books.size();i++){
                    if(!borrowed[i]){
                        previous=i;
                    }
                    if(returned[i]==true){
                        if(previous==-1){
                            cout << "Put " << books[i].first << "first\n";
                        }
                        else{
                            cout << "Put " << books[i].first << "after " << books[previous].first << "\n";
                        }

                        returned[i] = false;
                        borrowed[i] = false;
                        previous = i;
                    }
                }
                cout << "\n";
        }
    }
    return 0;
}
