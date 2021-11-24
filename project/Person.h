#ifndef PROJECT_PERSON_H
#define PROJECT_PERSON_H

#include <string>

class Person {
protected:
    std::string name;
    int age;
    char sex;

public:
    /**Inicializa uma pessoa "Indefinida"
     *terá como valores:
     * name - "undefined";
     * age - 0;
     * sex - 'U'
     */
    Person();

    /**Inicializa uma pessoa
     *
     * @param name nome
     * @param age idade
     * @param sex sexo
     */
    Person(std::string name, int age, char sex);

    /**Devolve o nome da pessoa
     *
     * @return nome da pessoa
     */
    std::string getName();

    /**Devolve a idade da pessoa
     *
     * @return idade da pessoa
     */
    int getAge();

    /**Devolve o sexo da pessoa
     *
     * @return sexo da pessoa
     */
    char getSex();

    /**Atribui um nome à pessoa
     *
     * @param name nome
     */
    void setName(std::string name);

    /**Atribui uma idade à pessoa
     *
     * @param age idade
     */
    void setAge(int age);

    /**Atribui um sexo à pessoa
     *
     * @param sex sexo
     */
    void setSex(char sex);
};


#endif
