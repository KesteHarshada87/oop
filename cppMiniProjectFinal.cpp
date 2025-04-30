#include <iostream>  // for cout, endl
#include <vector>    // for vector
#include <algorithm> // for remove

template<typename T>
class SmartContainer {
protected:
    std::vector<T> data;
public:
    virtual void insert(const T& value) = 0;
    virtual void remove(const T& value) = 0;
    virtual void undo() = 0;
    virtual void display() const = 0;
    virtual ~SmartContainer() {}
};

template<typename T>
class SmartVector : public SmartContainer<T> {
    std::vector<std::vector<T> > history; // note: space between >> for old compilers
public:
    void insert(const T& value) override {
        std::cout << "Inserting value: " << value << std::endl;
        this->history.push_back(this->data);
        this->data.push_back(value);
    }

    void remove(const T& value) override {
        std::cout << "Removing value: " << value << std::endl;
        this->history.push_back(this->data);
        this->data.erase(std::remove(this->data.begin(), this->data.end(), value), this->data.end());
    }

    void undo() override {
        std::cout << "Undoing last operation..." << std::endl;
        if (!this->history.empty()) {
            this->data = this->history.back();
            this->history.pop_back();
        } else {
            std::cout << "No operations to undo." << std::endl;
        }
    }

    void display() const override {
        std::cout << "Current container data: ";
        for (typename std::vector<T>::const_iterator it = this->data.begin(); it != this->data.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    T& operator[](std::size_t index) {
        std::cout << "Accessing element at index: " << index << std::endl;
        return this->data[index];
    }

    SmartVector<T> operator+(const SmartVector<T>& other) {
        std::cout << "Merging two SmartVectors..." << std::endl;
        SmartVector<T> result;
        result.data = this->data;
        result.data.insert(result.data.end(), other.data.begin(), other.data.end());
        return result;
    }
};

// ---- Test Program ----
int main() {
    SmartVector<int> vec1;
    vec1.insert(10);
    vec1.insert(20);
    vec1.display();

    SmartVector<int> vec2;
    vec2.insert(30);
    vec2.insert(40);
    vec2.display();

    SmartVector<int> vec3 = vec1 + vec2;
    vec3.display();

    vec3.remove(20);
    vec3.display();

    vec3.undo(); // undo last removal
    vec3.display();

    return 0;
}

