class dynamicArray{

    int *data;
    int nextIndex ;
    int capacity;

    public:

    dynamicArray(){
        data = new int[5] ;
        nextIndex = 0 ;
        capacity = 5 ;
    }

    void add(int element){
        if(nextIndex == capacity){
            int *newData = new int[2 * capacity] ;
            for(int i = 0 ; i < capacity ; i++){
                newData[i] = data[i] ;
            }

            delete [] data ;
            data = newData ;
            capacity *= 2 ;

        }else{
            data[nextIndex] = element ;
            nextIndex++ ;
        }

    }

    int get(int i)const{
        if(i >= 0 && i < nextIndex){
            return data[i] ;
        }
            return -1 ;
    }


    void add(int i , int element){

        if(i >= 0 && i < nextIndex){
            data[i] = element ;
        }else if(i == nextIndex){
            add(element) ;
        }else{
            return ;
        }
    }

    void print()const {
        for(int i = 0 ; i < nextIndex ; i++){
            cout << data[i] <<" " ;
        }
        cout << endl ;
    }

    dynamicArray(dynamicArray const &d){

        int *newData = new int[d.capacity] ;
        for(int i = 0 ; i < d.nextIndex ; i++){
            newData[i] = d.data[i] ;
        }

        this->data = newData ;
        this->nextIndex = d.nextIndex ;
        this->capacity = d.capacity ;

    }

    void operator=(dynamicArray const &d){
        int *newData = new int[d.capacity] ;
        for(int i = 0 ; i < d.nextIndex ; i++){
            newData[i] = d.data[i] ;
        }

        this->data = newData ;
        this->nextIndex = d.nextIndex ;
        this->capacity = d.capacity ;
    }

};
