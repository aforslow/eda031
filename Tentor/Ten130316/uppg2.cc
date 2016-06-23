
class Scheduler {
	public:
		void insertEvent(Event* e);
		void actionLoop();
	private:
		struct CompareTimes {
			bool operator()(Event* e1, Event* e2) const {
				return e1->getTime() > e2->getTime();
			}
		priority_queue<Event*, vector<Event*>, CompareTimes> pq;
};

void Scheduler::insertEvent(Event* e){
	pq.push(e);
}

void Scheduler::actionLoop(){
	while (!pq.empty()){
		pq.top()->action();
		delete pq.top();
		pq.pop();
	}
}
