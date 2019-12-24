//
// Created by nerya on 17/12/2019.
//

#include "VarDefinitionEqual.h"
#include "VariablesSingelton.h"


int VarDefinitionEqual::execute(vector<vector<std::__cxx11::string> > &detailsOfTheCommand, unsigned int index) {
    VariablesSingelton* variablesSingelton = variablesSingelton->getInstanceOfVariablesSingelton();
    string nameOfVarWeAlreadyHaveOrValueToSet = detailsOfTheCommand[index][2];
    string nameOfNewVar = detailsOfTheCommand[index][1];
    variablesSingelton->addVariableToInterpreter(nameOfNewVar, nameOfVarWeAlreadyHaveOrValueToSet);
    if (variablesSingelton->doIHaveThisVarInMapLeft(nameOfNewVar)) {
        variablesSingelton->setMapLeftOfVarByValue(nameOfNewVar, nameOfVarWeAlreadyHaveOrValueToSet);
    } else if (variablesSingelton->doIHaveThisVarInMapRight(nameOfNewVar)) {
        variablesSingelton->setMapRightOfVarByValue(nameOfNewVar, nameOfVarWeAlreadyHaveOrValueToSet);
    }
    return ++index;
}