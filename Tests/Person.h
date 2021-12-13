#ifndef PROJECT_PERSON_H
#define PROJECT_PERSON_H

#include <string>

class Person {
protected:
    std::string name;
    int age;
    char sex;
    bool validPerson;

    class InvalidPerson {
    private:
        std::string msg;
    public:
        InvalidPerson(std::string msg) {this->msg = msg;};
        std::string getMsg() {return msg;};
    };

public:
    /**Initializes uma pessoa "Undefined"
     *will have as values:
     * name - "undefined";
     * age - 0;
     * sex - 'U'
     */
    Person();

    /**Initializes a person
     * (validation and testing not implemented yet)
     *
     * @param name person's name
     * @param age person's age
     * @param sex person's sex ('M', 'F' or 'U')
     */
    Person(std::string name, int age, char sex);

    /**Returns the person's name
     *
     * @return person's name
     */
    
    bool isValid();
    
    /**Returns if the person's data is valid
    *
    * @return bool
    */
    
    std::string getName() const;

    /**Returns the person's age
     *
     * @return person's age
     */
    int getAge() const;

    /**Returns the person's sex
     *
     * @return person's sex
     */
    char getSex() const;

    /**Sets the person's name
     *
     * @param name person's name
     */
    void setName(std::string name);

    /**Sets the person's age
     *
     * @param age person's age
     */
    void setAge(int age);

    /**Sets a sex for the person
     *
     * @param sex person's sex
     */
    void setSex(char sex);
};


#endif
