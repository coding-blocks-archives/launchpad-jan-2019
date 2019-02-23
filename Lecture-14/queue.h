

class Queue{
private:
	int front;
	int rear;
	int * arr;
	int cs;
	int ms;

public:
	Queue(int ds=5){
		ms = ds;
		front = 0;
		rear = (ds-1);
		cs = 0;
		arr = new int[ms];
	};
	void push(const int data){
		if(cs<ms){
			rear = (rear+1)%ms;
			arr[rear] = data;
			cs++;
		}
	}
	void pop(){
		if(cs>0){
			front = (front+1)%ms;
			cs--;
		}
	}
	int getfront() const{
		return arr[front];
	}
	bool isEmpty(){
		return cs==0;
	}
	bool isFull(){
		return cs==ms;
	}

};