#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

private:
	Node<T>* first;
	int n;

public:
	ListLinked() {
        	first = nullptr;
        	n = 0;
    	}

    	~ListLinked() override {
        	while (first != nullptr) {
            		Node<T>* aux = first->next;
            		delete first;
            		first = aux;
        		}
	}
		
	int size() override {
		return n;
	}

	bool empty() override {
		return n == 0;
	}

	T get(int pos) override {
    		if (pos < 0 || pos >= n) {
        		throw std::out_of_range("Posición inválida");
		}
		
		Node<T>* aux = first;
		
		for (int i = 0; i < pos; i++){
			aux = aux->next;
		}

		return aux->data;
    	}

	T operator[](int pos) {
    		return get(pos);
	}

	int search(T e) override {
    		Node<T>* aux = first;

    		for (int i = 0; i < n; i++) {
        		if (aux->data == e){
				return i;
			}

        		aux = aux->next;
    		}

    		return -1;
	}

	void append(T e) override {
    		Node<T>* nuevo = new Node<T>(e);

    		if (first == nullptr) {
        		first = nuevo;
    		} else {
        		Node<T>* aux = first;
			while (aux->next != nullptr) {
    				aux = aux->next;
			}
			aux->next = nuevo;
    		}

		n++;
	}

	void prepend(T e) override {
    		Node<T>* nuevo = new Node<T>(e, first);
    		first = nuevo;
    		n++;
	}

	void insert(int pos, T e) override {
    		if (pos < 0 || pos > n) {
        		throw std::out_of_range("Posición inválida");
    		}

    		if (pos == 0) {
        		prepend(e);
        		return;
    		}	

    		if (pos == n) {
        		append(e);
        		return;
    		}
		
		Node<T>* aux = first;
    		for(int i = 0; i < pos-1; i++) {
			aux = aux->next;
		}

		Node<T>* nuevo = new Node<T>(e, aux->next);
		aux->next = nuevo;
		n++;
			
	}

	T remove(int pos) override {
    		if (pos < 0 || pos >= n) {
        		throw std::out_of_range("Posición inválida");
    		}		

    		Node<T>* borrar;

    		if (pos == 0) {
        		borrar = first;
        		first = first->next;
    		} else {
        		Node<T>* aux = first;

        		for (int i = 0; i < pos - 1; i++) {
            			aux = aux->next;
        		}

        		borrar = aux->next;
        		aux->next = borrar->next;
    		}

    		T removed = borrar->data;
    		delete borrar;
    		n--;

    		return removed;
	}

	friend std::ostream& operator<<(std::ostream& out, ListLinked<T>& list) {
    		out << "[\n";

    		Node<T>* aux = list.first;

    		while(aux != nullptr) {
			out << "  " << aux->data << '\n';
			aux = aux->next;
		}		

    		out << "]\n";
    		return out;
	}
             
};

#endif
