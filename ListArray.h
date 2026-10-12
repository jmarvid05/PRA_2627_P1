#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T> {

    private:
        // miembros privados
	T* arr;
	int max; //tamaño actual del array
	int n;   //elementos  que hay guardados en el array
	static const int MINSIZE = 2;

	void resize(int new_size){
		T* new_arr = new T[new_size];
		for (int i = 0; i < n; i++){
			new_arr[i] = arr[i];
 		}
		delete[] arr;
		arr = new_arr;
		max = new_size;
	}
	
    public:
        // miembros públicos, incluidos los heredados de List<T>
	ListArray(){
		max = MINSIZE;
		n= 0;
		arr = new T[MINSIZE];
	}

	~ListArray() override {
    		delete[] arr;
	}

	int size() override { 
		return n;
	}

	bool empty() override {
    		return n == 0;
	}

	T get(int pos) override {
   		if(pos < 0 || pos >= n){
			throw std::out_of_range("Posición inválida");
		}
		return arr[pos];	
	}	

	T operator[](int pos){
   		return get(pos);
	}

	int search(T e) override {
		for(int i = 0; i < n; i++){
			if(arr[i] == e){
				return i;
			}
		}
		return -1;
	}
	
	void append(T e) override {
		if(n == max){
			resize(max * 2);
		}
		arr[n]=e;
		n++;
	}

	void prepend(T e) override {
		if(n == max){
			resize(max *2);
		}
		for(int i = n; i > 0; i--){
			arr[i] = arr[i-1];
		}
		arr[0] = e;
		n++;
	}

	void insert(int pos, T e) override {
		if(pos < 0 || pos > n){
			throw std::out_of_range("Posición inválida");
		}
		if(n == max){
                        resize(max *2);
                }
		for (int i = n; i > pos; i--) {
 			arr[i] = arr[i - 1];
		}	
		arr[pos]= e;
		n++;
	}
	
	T remove(int pos) override {
                if(pos < 0 || pos > n-1){
                        throw std::out_of_range("Posición inválida");
                }
		T removed = arr[pos];
                for (int i = pos; i < n-1; i++) {
                        arr[i] = arr[i + 1];
                }
                n--;
		return removed;
        }

	friend std::ostream& operator<<(std::ostream& out, ListArray<T>& list) {
    		out << "[\n";
		for (int i = 0; i < list.n; i++) {
        		out << "  " << list.arr[i] << '\n';
			
    		}
		out << "]\n";
		return out;
	}


};
