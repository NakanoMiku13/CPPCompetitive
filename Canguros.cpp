#include<bits/stdc++.h>
using namespace std;
template<typename T>
using pointer = T*;
template<typename T>
struct Node{
	T value;
	pointer<Node> next;
	Node(T value): value{value},next{nullptr}{}
};
template<typename T>
class Queue{
	pointer<Node<T>> _front, _back;
	size_t _size;
	public:
		Queue():_front{nullptr},_back{nullptr},_size{0}{}
	auto Empty()->bool{
		return not _front and not _back;
	}
	auto Push(T value)->void{
		auto n = new Node<T>(value);
		if(Empty()){
			_front=_back=n;
		}
		else{
			_back->next=n;
			_back=n;
		}
		_size++;
	}
	auto Pop()->void{
		if(Empty()) return;
		auto n=_front;
		_front=_front->next;
		delete n;
		_size--;
	}
	auto Front()->T{
		return _front->value;
	}
	auto Size()->size_t{
		return _size;
	}
};
auto main()->int{
	ios_base::sync_with_stdio(0);cin.tie(0);
	Queue<int> canguro;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		char x;
		cin>>x;
		if(x=='N'){
			int x;
			cin>>x;
			canguro.Push(x+1);
		}else if(x=='A'){
			n-=canguro.Front();
			canguro.Pop();
		}else if(n=='C'){
			cout<<canguro.Size()<<"\n";
		}else if(n=='R'){
			cout<<n<<"\n";
		}
	}
}
