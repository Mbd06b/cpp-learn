#ifndef UB_STACK_H
#define UB_STACK_H



template <class DATA>
	class UBStack: private UBArray <DATA, size_t> {


	public:
			UBStack (); //default
			~UBStack();

			bool 	push	 (const DATA &); //this will never fail,
			bool 	pop		 (DATA &);

			size_t	size 	 ()const;
			void 	clearAll ();


	private:
			//hidden methods
						UBStack (const UBStack <DATA> &);
		UBStack<DATA> &	operator = (const UBStack <DATA> &);


		size_t top; //Keep track of the top of our stack.
};


template <class DATA> //default
	UBStack <DATA>::UBStack(): top (0){

}

template <class DATA> //destructor
	UBStack<DATA>::~UBStack(){

}

template <class DATA>
	bool UBStack<DATA>::push(const DATA & D){

		//(*this) [top] = D;
		getAt (Top++) = D;  //
		return true;

}

template <class DATA>
	bool UBStack<DATA>::pop(DATA & D){

		if(top > 0){ //true - ive got something on the stack.

			D = (*this) [--Top];
			return true;

		}else{
			return false;
		};

}

template <class DATA>
	size_t UBStack<DATA>::size() const{
	return top;
}

template <class DATA>
	void UBStack<DATA>::clearAll(){
	deleteAllNodes(); //From UBArray
}
#endif
