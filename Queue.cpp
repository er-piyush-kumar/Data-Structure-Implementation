#include<iostream>
using namespace std;

class queue
{
    private:
        int *arr;
        int size;
        int front;
        int rear;
    
    public:
        queue(int size)
        {
            arr = new int[size];
            this->size = size;
            this->front = -1;
            this->rear = -1;
        }

        void push(int data)
        {
            //check it is empty or not
            if(front==-1 and rear==-1)
            {
                front++;
                rear++;
                arr[rear] = data;
            }
            else if(rear==size-1)
            {
                //overflow
                cout<<"Can't push, Overflow"<<endl;
            }
            else
            {
                rear++;
                arr[rear] = data;
            }
        }

        void pop()
        {
            //if it is empty
            if(front==-1 and rear==-1)
            {
                cout<<"Can't pop, Underflow"<<endl;
            }
            else if(front==rear) //single element
            {
                arr[front] = -1;
                front = -1;
                rear = -1;
            }
            else
            {
                arr[front] = -1;
                front++;
            }
        }

        int getsize()
        {
            //if empty
            if(front==-1 and rear == -1)
                return 0;
            else    
                return rear - front + 1;
        }

        bool empty()
        {
            if(front==-1 and rear==-1)
            {
                return true;
            }
            else
                return false;
        }

        void print()
        {
            for(int i = 0;i<size;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

        int getfront()
        {
            if(front!=-1)
                return arr[front];
            else
                return -1;
        }

        int getrear()
        {
            if(rear!=-1 and front!=-1)
                return arr[rear];
            else
                return -1;
        }

        ~queue()
        {
            delete arr;
        }


};


int main()
{
    queue q(5);
    return 0;
}