#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <map>

// Teacher Concrete Class holds a reference to a list 
// of teachers instances to create a heirarchical tree 
// structure it can refer to

class Teacher {
	
	private:
		std::string name;
		int salary;
		std::vector<Teacher> reportees;

	public:

		Teacher(std::string n, int s) : name(n), salary(s) {}
		
		// 'vec_index' method helps us to retrieve vector index
		//  for a certain Teacher instance
		int vec_index(const Teacher& to_be_found) const {
			auto it = find(this->reportees.begin(), this->reportees.end(), to_be_found);
			return (it != this->reportees.end()) ? std::distance(this->reportees.begin(), it) : -1;
		} 
		
		// Usage of std::find requires (re)definition of '==' operator
		bool operator==(const Teacher& other) const {
			return name == other.name && salary == other.salary;
		}
		
		void add(const Teacher& t) {
			this->reportees.push_back(t);
		} 
		
		void remove(Teacher& t) {
			int index = vec_index(t);
			std::cout << this->reportees[index].name << std::endl;			
		}
		
		
		// Variadic function template to take 
		// any number of arguments in 'addAll' method
		template<typename ... Args>
		void addAll(Args&&... reportees) {
			(this->reportees.emplace_back(std::forward<Args>(reportees)), ...);
		}

		std::vector<Teacher> get_reportees() {
			return this->reportees;
		}

		void print_infos() const {
			std::cout <<  "Teacher(name=" << this->name << ", salary=" << this->salary << ")" << std::endl;
		}

		void print_reportees() const {
			std::cout << "Reportees : " << std::endl;
			for(const auto& t : this->reportees) {
				t.print_infos();
			}
			std::cout << std::endl;
		}


};

int main() {

	// New Teacher instance
	Teacher t1 = Teacher("Albert", 4000);
	
	// Infos Action
	t1.print_infos();
	
	// Teachers map
	std::map<std::string, int> other_teachers{{"Jean-Marc", 2000}, {"Jean-Pierre", 3000}};
	for(const auto & [name, salary]: other_teachers) {
		Teacher n = Teacher(name, salary);
		t1.add(n);
	}
	
	t1.print_reportees();

	
	return 0;
}
