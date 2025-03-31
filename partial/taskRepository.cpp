#include "duration.h"
#include "taskRepository.h"
using namespace std;
class Task {
    public:
        int id;
        Duration d;
        Task(): id{-1}, d{Duration(0, 's')} {}
        Task(int id, Duration d) : id{id}, d{d}{}

};

class TaskRepository {
    private:
        Task* elems;
        unsigned int capacity, length;
    public:
        TaskRepository(unsigned int capacity) : elems {new Task[capacity]}, capacity{capacity}, length{0}{}
        
        void push(Task t) {
            if (length == capacity) {
                unsigned int newCapacity = capacity * 2;
                
                Task* newElements = new Task[newCapacity];

                for(int i = 0; i < length; i ++) {
                    newElements[i] = elems[i];
                }
                delete[] elems;
                elems = newElements;
                capacity = newCapacity;
            }
            for (int i = 0; i < length; i ++) {
                if (elems[i].id == t.id) {
                    throw invalid_argument("id already exists");
                }
            }
            elems[length++] = t;
        }

        void print(char delimiter) {
            for (int i = 0; i < length; i ++) {
                cout << elems[i].id << delimiter << elems[i].d << '\n';
            }
        }

        Duration totalDuration(){
            Duration answer = Duration(0,'s');

            for (int i = 0; i < length; i ++) {
                answer = answer + elems[i].d;
            }
            return answer;
        }

        void deleteAllTasks() {
            delete[] elems;
            elems = new Task[capacity];
            length = 0;
        }

        int count_tasks_between(float min_duration, float max_duration) {
            int count = 0;
            for (int i = 0; i < length; i ++) {
                float currentDuration = elems[i].d.get_value();
                if (min_duration <= currentDuration and currentDuration <= max_duration) 
                    count ++;
            }
            return count;
        }

        
};