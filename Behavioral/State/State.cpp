#include <iostream>

class Switch;
class State;


// Common State Interface creates an abstraction 
// to toggle Switch object instances

class State {
public:
    virtual ~State() {}  
	virtual void toggle(Switch* s) = 0;
};


// Switch class holds a reference to a State 
// instance that can have multiple internal states 

class Switch {
public:
    Switch(State* s) : state(s) {}
    ~Switch() {
        delete this->state;
    }
    void set_state(State* s) {
        delete this->state;
        this->state = s;
    }
    void toggle();
private:
    State* state;
};


// Concrete States classes implement the State interface 
// and redefine 'toggle' method to specify the appropriate 
// state handler

class OffState : public State {
public:
    ~OffState() override {} 
	void toggle(Switch* s) override;
};

class OnState : public State {
public:
    ~OnState() override {}  
	void toggle(Switch* s) override;
};

void OffState::toggle(Switch* s) {
	std::cout << "Switch is OFF, turning ON..." << std::endl;
	OnState *onState = new OnState();
	s->set_state(onState);
}

void OnState::toggle(Switch* s) {
	std::cout << "Switch is ON, turning OFF..." << std::endl;
	OffState *os = new OffState();
	s->set_state(os);
}

void Switch::toggle() {
    this->state->toggle(this);
}



int main() {
	
	// Client defines new state 
	// and creates a Switch that is active
	State *on = new OnState();
	Switch *ls = new Switch(on);

	// then Switch is toggled off
	ls->toggle();	

	
	// Overriding current state
	State *off = new OffState();
	ls->set_state(off);

	// and turning switch back on
	ls->toggle();

	delete ls;
	
	return 0;
}
