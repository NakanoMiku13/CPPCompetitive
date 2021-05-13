#include<bits/stdc++.h>
using namespace std;
struct Node{
    int value;
    Node* next;
};
struct Stack{
    Node* Head=nullptr;
    void Push(int x){
        Node* tmp=new Node();
        tmp->value=x;
        if(Head==nullptr){
            Head=tmp;
        }else{
            Node* move=Head;
            Head=tmp;
            Head->next=move;
            move=nullptr;
        }
    }
    int Value(){
        return Head->value;
    }
    void Pop(){
        if(Head!=nullptr){
            Node* tmp=Head;
            Head=Head->next;
            delete(tmp);
        }
    }
    void Print(){
        Node* tmp = Head;
        while(tmp!=nullptr){
            cout<<tmp->value<<endl;
            tmp=tmp->next;
        }
    }
};
struct Queue{
    Node* Head=nullptr;
    Node* Front=nullptr;
    Node* Back=nullptr;
    int TopValue(){
        return Front->value;
    }
    void Push(int x){
        Node* tmp=new Node();
        tmp->value=x;
        if(Head==nullptr){
            Head=tmp;
            Front=Head;
            Back=Head;
        }else{
            Node* move=Head;
            Head=tmp;
            Head->next=move;
            Back=Head;
            move=nullptr;
        }
    }
    void Print(){
        Node* tmp = Head;
        while(tmp!=nullptr){
            cout<<tmp->value<<endl;
            tmp=tmp->next;
        }
    }
    void Pop(){
        if(Head!=nullptr){
            if(Front!=Head && Front!=Back){
                Node* move=Head;
                Node* tmp=Front;
                while (move->next!=Front)
                {
                    move=move->next;
                }
                Front=move;
                move=nullptr;
                delete(tmp);
            }else{
                Head=nullptr;
                Front=nullptr;
                Back=nullptr;
            }
            
        }
    }
};
int main(){
    Queue x,deleted;
    Stack y,deleted2;
    string text,next;
    int n,z;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>z;
        x.Push(z);
        y.Push(z);
    }
    x.Print();
    y.Print();
    cout<<"----"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        x.Pop();
        y.Pop();
    }
    x.Print();
    y.Print();
    cout<<"----";
    cin>>n>>text;
    for(int i=0;i<n;i++){
        cin>>next>>z;
        if(text=="P"){
            if(next=="PUSH"){
                x.Push(z);
            }else{
                deleted.Push(x.TopValue());
                x.Pop();
            }
        }else{
            if(next=="PUSH"){
                y.Push(z);
            }else{
                deleted2.Push(y.Value());
                y.Pop();
            }
        }
    }
    if(text=="P"){
        deleted.Print();
    }else{
        deleted2.Print();
    }
}