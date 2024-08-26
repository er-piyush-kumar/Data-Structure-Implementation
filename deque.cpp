#include<iostream>
using namespace std;

class deque
{
    private:
        int *arr;
        int size;
        int front;
        int rear;

    public:

        deque(int size)
        {
            arr = new int[size];
            this->size = size;
            this->front = -1;
            this->rear = -1;
        }

        void push_back(int data)
        {
            //full
            //empty
            //circular
            //normal

            if((front==0 and rear==size-1) or (rear == front-1))
            {
                cout<<"Overflow"<<endl;
            }
            else if(front==-1 and rear==-1)
            {
                front++;
                rear++;
                arr[rear] = data;
            }
            else if(rear == size-1 and front !=0) //circular
            {
                rear = 0;
                arr[rear] = data;
            }
            else
            {
                rear++;
                arr[rear] = data;
            }
        }

        void push_front(int data)
        {
            //full
            //empty
            //circular
            //normal

            if((front==0 and rear==size-1) or (rear == front-1))
            {
                cout<<"Overflow"<<endl;
            }
            else if(front==-1 and rear==-1)
            {
                front++;
                rear++;
                arr[front] = data;
            }
            else if(front == 0 and rear != size-1) //circular
            {
                front = size-1;
                arr[front] = data;
            }
            else
            {
                front--;
                arr[front] = data;
            }
        }

        void pop_front()
        {
            //empty
            //single element
            //circular
            //normal

            if(front==-1 and rear==-1)
            {
                cout<<"Underflow"<<endl;
            }
            else if(front==rear)
            {
                arr[front] = -1;
                front = -1;
                rear = -1;
            }
            else if(front == size-1)
            {
                arr[front] = -1;
                front = 0;
            }
            else
            {
                arr[front] = -1;
                front++;
            }
        }

        void pop_back()
        {
            //empty
            //single element
            //circular
            //normal

            if(front==-1 and rear==-1)
            {
                cout<<"Underflow"<<endl;
            }
            else if(front==rear)
            {
                arr[front] = -1;
                front = -1;
                rear = -1;
            }
            else if(rear == 0)
            {
                arr[rear] = -1;
                rear = size-1;
            }
            else
            {
                arr[rear] = -1;
                rear--;
            }
        }

        void print()
        {
            cout<<"front : "<<front<<" , rear : "<<rear<<endl;
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
            if(rear!=-1)
                return arr[rear];
            else
                return -1;
        }

        bool isempty()
        {
          if(front==-1 and rear==-1)
            return true;
          else
            return false;
        }

        ~deque()
        {
            delete arr;
        }
};

int main()
{
    deque dq(5);
    return 0;
}