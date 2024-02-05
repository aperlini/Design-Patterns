#include <iostream>
#include <vector>
#include <stdexcept>


// Iterator interface defines the operations
// required to iterate through a collection

template <typename T>
class Iterator {
public:
    virtual ~Iterator() = default;
    virtual void begin() = 0;
    virtual bool end() const = 0;
    virtual void next() = 0;
    virtual T current() const = 0;
};


// Collection class declares public methods
// to access and modify elements. It also defines
// a 'create_iterator' method that will return an
// instance of a concrete iterator each time it is
// requested.

template <typename T>
class Collection {
	public:
		Collection() { }
		
		T at(int i) const {
			return this->items.at(i);
		}

		int size() const {
			return this->items.size();
		}

		void insert(T val) {
			this->items.push_back(val);
		}

		Iterator<T> *create_iterator();

	private:
		std::vector<T> items;

};


// ConcreteIterator implements the Iterator interface
// and redefine its methods to traverse the collection

template <typename T>
class ConcreteIterator : public Iterator<T> {

public:
	ConcreteIterator(Collection<T> *i) : items(i) { }
	~ConcreteIterator() {}

	void begin() override {
		this->index = 0;
	}

	void next() override {
		this->index++;
	}

	bool end() const override {
		return (this->index >= this->items->size());
	}

	T current() const override {
		if(this->end()) {
			throw std::out_of_range("undefined index");
		}
		return this->items->at(index);
	}

private:
	Collection<T> *items;
	int index;

};


// The method that provides the Iterator 
// must return the ConcreteIterator instance

template <typename T>
Iterator<T> *Collection<T>::create_iterator() {
	return new ConcreteIterator(this);
}


int main() {
	
	// Declaring a collection of 
	// integer and adding elements to t
	Collection<int> c1;	
	c1.insert(23);
	c1.insert(32);
	
	// Defining an Iterator and traversing the collection
	Iterator<int> *it = c1.create_iterator();

	for(it->begin(); !it->end(); it->next()) {
		std::cout << it->current() << "\n";
	}

	delete it;
	
	// Declaring a collection of 
	// strings and adding elements to it
	Collection<std::string> c2;	
	c2.insert("Hello");
	c2.insert("Universe");
	

	// Defining an Iterator and traversing the collection
	Iterator<std::string> *it_2 = c2.create_iterator();
	
	for(it_2->begin(); !it_2->end(); it_2->next()) {
		std::cout << it_2->current() << "\n";
	}

	delete it_2;


    return 0;
}

