#include <vector>
class PriorityQueue{
    vector<int> pq ;

public:
  PriorityQueue(){
      next = 0 ;
  }

  bool isEmpty(){
      return pq.size() == 0 ;
  }

  /**return the number of element present in priority queue */
  int getSize(){
      return pq.size() ;
  }

  int getMin(){
      if(isEmpty()){
        return 0 ;
      }
      return pq[0] ;
  }



  void insert(int element){
      pq.push_back(element) ;

      int childIndex = pq.size() - 1 ;
      int parentIndex = (childIndex - 1) / 2 ;
      if(parentIndex >= 0){
        if(pq[parentIndex] > pq[childIndex]){
            swap(pq[parentIndex], pq[childIndex])
        }
      }

  }
};
