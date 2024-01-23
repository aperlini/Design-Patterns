#include <iostream>
#include <vector>
#include <string>
#include <map>


// Item interface
class Item {
	public:
		const char *content;
		Item(const char *c) : content(c) {}
};

// Iterator interface
class Iterator {
	public:
		virtual ~Iterator() {}
		virtual const Item& next() = 0;
		virtual bool has_next() const = 0;
};

// Iterable interface
class Iterable {
	public:
		virtual Iterator create_iterator() const = 0;
};

// implements Iterable
class ConcreteCollection : public Iterable {
	private:
		const char *items[4] = {"diodes", "programmable devices", "transistors", "integrated circuits" };
		int length = 4;
	public:
		
		class CollectionIterator : public Iterator {
			
			private:
				const ConcreteCollection *coll;
				int index;

			public:
				CollectionIterator(const ConcreteCollection *c) : coll(c), index(0) {}
				
				bool has_next() const override {
					return this->index < this->coll->length;
				}

				const Item& next() override {
					if(this->has_next()) {
						const Item& c = this->coll->items[index]; 
						index++;
						return c;
					}
					throw std::out_of_range("No more elements");
				}
				
		};
		
		Iterator create_iterator() const override {
			return new CollectionIterator(this);
		}

};


int main() {
	
	ConcreteCollection cc = ConcreteCollection();
	ConcreteCollection::Iterator it = cc.create_iterator();
	
	while(it.has_next()) {
		const Item& item = it.next();
		std::cout << item.content << std::endl;
	}

	delete it;


	return 0;
}
