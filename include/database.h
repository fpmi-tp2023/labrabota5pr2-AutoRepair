//
// Created by Kirill on 10.04.2023.
//

#ifndef LABRABOTA5PR2_AUTOREPAIR_INCLUDE_BATABASE_H_
#define LABRABOTA5PR2_AUTOREPAIR_INCLUDE_BATABASE_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlite3.h>

void createTable(sqlite3 *dataBase, char *sqlRequest, int rc);

void createDataBase();

#endif //LABRABOTA5PR2_AUTOREPAIR_INCLUDE_BATABASE_H_
