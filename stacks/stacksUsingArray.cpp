 #include <climits>

 template <typename T>
class stackUsingArray{

    T *data ;
    int nextIndex ;
    int capacity ;

public :
    stackUsingArray(){
        capacity = 4 ;
        data = new T[capacity] ;
        nextIndex = 0 ;
    }

    bool isEmpty(){
        return nextIndex == 0 ;
    }

    //insert element

    void push(T element){
        if(nextIndex == capacity){
            capacity *= 2 ;
            T *newData = new T[capacity] ;
            for(int i = 0 ; i < nextIndex ; i++){
                newData[i] = data[i] ;
            }

            delete [] data ;
            data = newData ;

            /*
            cout << "stack overflow" << endl ;
            return ; */
        }
        data[nextIndex] = element ;
        nextIndex++ ;
    }

    T pop(){
        if(nextIndex == 0){
            cout<< "stack empty" << endl ;
            return 0;
        }
        nextIndex-- ;
        return data[nextIndex] ;
    }

    T top(){

        if(isEmpty()){
            cout<< "stack empty" << endl ;
            return 0 ;
        }
        return data[nextIndex - 1] ;
    }

    int size(){
        return nextIndex ;
    }

};















