
#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
 
template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
 /**
  * @brief Construct a new Heap object
  *
  * @param m ary-ness of heap tree (default to 2)
  * @param c binary predicate function/functor that takes two items
  *          as an argument and returns a bool if the first argument has
  *          priority over the second.
  */
 Heap(int m=2, PComparator c = PComparator());
 
 /**
 * @brief Destroy the Heap object
 *
 */
 ~Heap();
 
 /**
  * @brief Push an item to the heap
  *
  * @param item item to heap
  */
 void push(const T& item);
 
 /**
  * @brief Returns the top (priority) item
  *
  * @return T const& top priority item
  * @throw std::underflow_error if the heap is empty
  */
 T const & top() const;
 
 /**
  * @brief Remove the top priority item
  *
  * @throw std::underflow_error if the heap is empty
  */
 void pop();
 
 /// returns true if the heap is empty
 
 /**
  * @brief Returns true if the heap is empty
  *
  */
 bool empty() const;
 
   /**
  * @brief Returns size of the heap
  *
  */
 size_t size() const;
  void trickle_Down(size_t index);
 
 void trickle_Up(size_t index);
 
 std::vector<T> debugVectorPrint(){
 return itemsVector;
}
 
 
private:
 PComparator comp;
 std::vector<T> itemsVector;
 size_t numAry;
};
 
 

template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
 // Here we use exceptions to handle the case of trying
 // to access the top element of an empty heap
 if(empty()){
   throw std::underflow_error("Sorry, it's empty");
 }
  return itemsVector[0];
}
 
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
{
 this -> numAry = m;
 this -> comp = c;
 }
 
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{
}
 
template<typename T, typename PComparator>
void Heap<T,PComparator>::trickle_Up(size_t index)
{
 while (index != 0)
 {
   size_t parentIndex = (index-1) / numAry;
   if (comp(itemsVector[index],itemsVector[parentIndex]))
   {
     std::swap(itemsVector[index],itemsVector[parentIndex]);
   } else {
     break;
   }
   index = parentIndex;
   parentIndex = ((index-1)/numAry);
 }
}
 
template<typename T, typename PComparator>
void Heap<T,PComparator>::trickle_Down(size_t index)
{
  /*if (index + 1 >= itemsVector.size())
  {
    return;
  }
  int smallerChild = numAry * index +1;
  int biggerChild = smallerChild;
  for (int i = 1; i <numAry; i++)
  {
    if (biggerChild + i < itemsVector.size() - 1)
    {
      smallerChild = biggerChild + i;
    }
  }
  if (comp(itemsVector[smallerChild], itemsVector[index]))
  {
    std::swap(itemsVector[index], itemsVector[smallerChild]);
    trickle_Down(smallerChild);
  }
  if (comp(itemsVector[index], itemsVector[smallerChild]))
  {
    std::swap(itemsVector[index], itemsVector[smallerChild]);
    trickle_Down(smallerChild);
  }*/
 
 if (index + 1 >= itemsVector.size()) //comment here
 {
   return;
 }
 size_t smallerChild = numAry * index + 1;
 if ((numAry * index) + 1 < itemsVector.size())
 {
   for (size_t i = 1; i <= numAry; i++)
   {
     size_t biggerChild = numAry * index + i;
     if (biggerChild < itemsVector.size()) {
     if (comp(itemsVector[biggerChild], itemsVector[smallerChild]))
     {
       smallerChild = biggerChild;
     }
   }
   }
 
   // Swap a child with node atu index
   if (comp(itemsVector[smallerChild], itemsVector[index])) {
     std::swap(itemsVector[smallerChild],itemsVector[index]);
     trickle_Down(smallerChild);
   }
 }
 /*if (comp(itemsVector[index],itemsVector[smallerChild]))
 {
   std::swap(itemsVector[index], itemsVector[smallerChild]);
 }*/
 //check all the children of current index to find smallest child (Use comparator)
 //Find smallest child, compare that smallest child to current index
 //If current index > smallest child, you will have to swap the index with the smallest child
 //Call trickleDown(index of Smallest Child because you swapped)
}
 
 
 
template<typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
 itemsVector.push_back(item);
 //std::vector<T> itemsChecker;
 //itemsChecker = debugVectorPrint();
 //std::cout << debugVectorPrint() << std::endl;
   /*if(empty()){
 
   // ================================
   // throw the appropriate exception
   // ===============================
 
 }*/
 trickle_Up(itemsVector.size() - 1);
}
 
 
 
// We will start pop() for you to handle the case of
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
 if(empty()){
   throw std::underflow_error("Sorry, it's empty");
 
   // ================================
   // throw the appropriate exception
   // ===============================
 
 }
 std::swap(itemsVector[0], itemsVector[itemsVector.size()-1]);
 itemsVector.pop_back();
 trickle_Down(0);
 ;
}
 
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
 if (itemsVector.empty())
 {
   return true;
 }
 return false;
}
 
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
 return itemsVector.size();
}
 
//TODO delete after debugging
 
 
 
 
 
 
 
 
#endif
 
 

