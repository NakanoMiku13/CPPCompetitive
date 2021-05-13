#include<bits/stdc++.h>
using namespace std;
struct Node{
    char Value;
    Node* Next;
};
struct Stack{
    int Size=0;
    bool Valid=true;
    Node* Head=nullptr;
    bool Empty(){
        if(Head==nullptr){
            return true;
        }else{
            return false;
        }
    }
    bool ValidateInput(char x){
        if(x=='(' or x=='[' or x=='{') return true;
        return false;
    }
    bool ValidateInput2(char x, char head){
        if(x==')'){
            if(head=='('){
                Pop();
                return true;
            }else{
                return false;
            }
        }else if(x==']'){
            if(head=='['){
                Pop();
                return true;
            }else{
                return false;
            }
        }else if(x=='}'){
            if(head=='{'){
                Pop();
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
    void Push(char x){
        if(ValidateInput(x)){
            Size++;
            Node* tmp=new Node();
            tmp->Value=x;
            if(Empty()){
                Head=tmp;
            }else{
                Node* move=Head;
                Head=tmp;
                Head->Next=move;
                move=nullptr;
            }
            Valid=true;
        }else{
            if(Empty()){
                Valid=false;
            }else{
                ValidateInput2(x,Head->Value);
            }
        }
    }
    void Pop(){
        Size--;
        Node* tmp=Head;
        Head=Head->Next;
        delete(tmp);
    }
    bool IsValid(){
        if(Valid && Size==0){
            return true;
        }else{
            return false;
        }
    }
};
int main(){
    Stack x;
    string val;
    cin>>val;
    for(auto i=0;i<val.size();i++){
        x.Push(val[i]);
    }
    if(x.IsValid()){
        cout<<"SI"<<" "<<x.Size;
    }else{
        cout<<"NO"<<" "<<x.Size;
    }
}