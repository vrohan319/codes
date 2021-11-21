template <typename T>
class queueUsingArray{

    T *data ;
    int nextIndex ;
    int firstIndex ;
    int size ;
    int capacity ;

public :

    queueUsingArray(T s){
        data = new T[s] ;
        nextIndex = 0 ;
        firstIndex = -1 ;
        size = 0 ;
        capacity = s ;
    }

    int getSize(){
        return size ;
    }

    int isEmpty(){
        return size == 0 ;
    }

    void enqueue(T element){
        if(size == capacity){
            cout << "queue is full" << endl ;
            return ;
        }
        data[nextIndex] = element ;
        nextIndex = (nextIndex + 1) % capacity ;
        if(firstIndex == -1){
            firstIndex = 0 ;
        }
        size++ ;
    }

    T Front(){
        if(isEmpty()){
            cout << "queue is empty" << endl ;
            return 0 ;
        }
        return data[firstIndex] ;
    }

    T dequeue(){
        if(isEmpty()){
            cout << "queue is empty" << endl ;
            return 0 ;
        }
        T ans = data[firstIndex] ;
        size-- ;
        firstIndex = (firstIndex + 1) % capacity ;

        if(size == 0){
            firstIndex = -1 ;
            nextIndex = 0 ;
        }
        return ans ;
    }

};
