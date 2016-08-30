#ifndef UB_ARRAY_H
#define UB_ARRAY_H

#include <WCS_Pointer.h>
#include <stdexcept>

// NOTE: whatever is used to replace INDEX in the template  below MUST support the comparison

template <class DATA, class INDEX>
class UBArray{ //UB-Unbounded


	private:

		struct Node: public RefCount{ //anything that uses WCS_Pointer needs to receive inheritance from RefCount

			DATA 				Data;
			INDEX			 	Index;
			WCS_Pointer <Node> pNext;
			WCS_Pointer <Node> pPrev;

			//THIS Node CONSTRUCTOR IS INSIDE UBArray!!
			Node (const INDEX &); //writing a contsructor for our Node


		};

	public:

							 UBArray(); //default constructor
							~UBArray();
				void deleteAllNodes (); //delete all nodes, when you want to clear out your list and star over.

				DATA &		getFirst();
				DATA & 		getNext ();
				DATA &		Remove  (const INDEX &); // removes the requested index from the list.

				DATA &		operator []	(const INDEX &); //returns a & reference to DATA in the index so we can modify it.
		const   DATA & 		operator [] (const INDEX &)const;

	private:
		//Copy Operators
							UBArray (const UBArray <DATA, INDEX> &); //put the copy constructor in private, because copying a whole database would be a massive operation
		UBArray <DATA, INDEX> & operator = (const UBArray <DATA, INDEX> &);


mutable WCS_Pointer <Node> 		Current; //mutable means that this member is changable even if the class is constant.
//mutable tells the program that this will not be stored in ROM, but RAM.
//mutable should only be used "behind the scenes" for the customer, the way the program behaves should not be visible
//to the customer when you use mutable.
		WCS_Pointer <Node>		Head;
		WCS_Pointer <Node> 		Tail;

		//we need a counter to keep track of how many nodes we create.
		//int 				numNodes = 0;
	};

template <class DATA, class INDEX>
	UBArray <DATA, INDEX>::UBArray(){
	//the WCS_Pointers are automatically called to construct null pointers.
	//then there is nothing we need to initialize
}

//THIS IS THE CONSTRUCTOR FOR Node, that is INSIDE UBArray.
template <class DATA, class INDEX>
	UBArray <DATA, INDEX>::Node::Node(const INDEX & I): Index (I){
	//Index = I;
}



template <class DATA, class INDEX>
	UBArray <DATA, INDEX>::~UBArray(){
		deleteAllNodes();
}

template <class DATA, class INDEX>
	void UBArray <DATA, INDEX>::deleteAllNodes(){
	//Left as an Exercise for the Student
}

template <class DATA, class INDEX>
	DATA & UBArray <DATA, INDEX>::getFirst(){

	if (Head){ //if we have  ahead
		Current = Head;
		return (*Head).Data;
	}else{
		throw exception("Array Empty - getFirst"); //array empty
	}

}

template <class DATA, class INDEX>
	DATA & UBArray <DATA, INDEX>::getNext(){
	if (Current){
		if((*Current).pNext){
			Current = (*Current).pNext;
			return (*Current).Data;
		}else{
			throw exception ("No Next Element - UBArray::getNext");
		};

	}else{
		throw exception("No Element Found - UBArray::getNext");
	};
}


template <class DATA, class INDEX>
	DATA & UBArray <DATA, INDEX>::operator [](const INDEX & I){ // I - Index location
		if (!Head){ //if Head is null, then the list is empty.

			Head  =  WCS_Pointer <Node> (new Node (I)); //sends the I to assign to the Index.
			Tail = Head;
			return (*Head).Data; //return the Data area pointed to my head.
							 //we could write this as Head->Data to make sure we call the head before we dereference it.
		}
		else{//if we are looking for something and it is what we are looking for.. return it.
			if (I == (*Head).Index){
				return (*Head).Data;
			}
			else{//if we have to go infront of the Head, we have to create a new Node, and make it the Head.
				 if (I < (*Head).Index){

					(*Head).pPrev 		   = WCS_Pointer <Node> (new Node(I)); //create new head node
					(*(*Head).pPrev).pNext = Head; //this is the next node after the one we just added is the old head
					Head				   = (*Head).pPrev;
					return (*Head).Data;

				 	}
				 else{
					 if (I == (*Tail).Index){ //if what we are looking for is the tail.
						 return (*Tail).Data; //return the Tail Data.
					 }else{
						 	if (I > (*Tail).Index){
						 		(*Tail).pNext 		   = WCS_Pointer <Node> (new Node(I)); //create new head node
						 		(*(*Tail).pNext).pPrev = Tail; //this is the next node after the one we just added is the old head
						 		Tail				   = (*Tail).pNext;
						 		return (*Tail).Data;

						 	}else{
						 		WCS_Pointer <Node> pTemp1 ((*Head).pNext); //we need a temporary pointer to walk down the list.
						 		for(; I > (*pTemp1).Index ; pTemp1 = (*pTemp1).pNext){ //we are going to keep going down the list.
						 			//we stop if we have reached the one we want, or are before the one we want.
						 			if(I == (*pTemp1).Index){//if the index is what I'm looking for
						 				return (*pTemp1).Data; //return the data from the existing index location
						 			}else{
						 				//Since we didn't find an existing node.
						 				WCS_Pointer <Node> pTemp2 (new Node (I)); //we create a new node.
						 				(*(*pTemp1).pPrev).pNext = pTemp2; //linking the previous node to our new node.
						 				(*pTemp2).pPrev 		 = (*pTemp1).pPrev; //pointing our node to the previus node
						 				(*pTemp1).pPrev          = pTemp2; //linking our node to the next node
						 				(*pTemp2).pNext			 = pTemp1; //linking the next node to the node we created

						 				return (*pTemp2).Data; //We return the data for our new node.
						 			}
						 		}

						 	}
					 }
				 }
				}
		}
}


template <class DATA, class INDEX>
	const DATA & UBArray <DATA, INDEX>::operator [](const INDEX & I) const{

	//we are not changing the DATA, we are just sending the data back or throwing an exception if it's not there.
	//if const [] can't find a corresponding index, we throw an error.

}

#endif UB_ARRAY_H_
